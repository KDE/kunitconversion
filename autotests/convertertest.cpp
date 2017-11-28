/*
 *   Copyright (C) 2009 Petri Damstén <damu@iki.fi>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "convertertest.h"
#include <kunitconversion/unitcategory.h>
#include <QVector>
#include <QThread>
#include <QStandardPaths>

using namespace KUnitConversion;

void ConverterTest::initTestCase()
{
    QStandardPaths::enableTestMode(true);

    // Remove currency cache to force a download
    const QString cache = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + QStringLiteral("/libkunitconversion/currency.xml");
    QFile::remove(cache);
}

void ConverterTest::testCategory()
{
    Converter c;
    QCOMPARE(c.categoryForUnit(QStringLiteral("km")).id(), LengthCategory);
    QCOMPARE(c.category(QStringLiteral("Length")).id(), LengthCategory);
    QCOMPARE(c.category(LengthCategory).name(), QStringLiteral("Length"));
    QVERIFY(c.categories().size() > 0);
}

void ConverterTest::testUnits()
{
    Converter c;
    QCOMPARE(c.unit(QStringLiteral("km")).symbol(), QStringLiteral("km"));
    QCOMPARE(c.unit(Kilogram).symbol(), QStringLiteral("kg"));
}

void ConverterTest::testConvert()
{
    Converter c;
    Value v = c.convert(Value(3.14, Kilometer), QStringLiteral("m"));
    QCOMPARE(v.number(), 3140.0);
    v = c.convert(v, QStringLiteral("cm"));
    QCOMPARE(v.number(), 314000.0);
    v = c.convert(v, c.category(LengthCategory).defaultUnit());
    QCOMPARE(v.number(), 3140.0);
}

void ConverterTest::testInvalid()
{
    Converter c;
    QCOMPARE(c.categoryForUnit(QStringLiteral("does not exist")).id(), InvalidCategory);
    QCOMPARE(c.unit(QStringLiteral("does not exist")).symbol(), QString());
    QCOMPARE(c.category(QStringLiteral("does not exist")).name(), QString());
}

class CurrencyTestThread : public QThread
{
public:
    CurrencyTestThread(Converter &c) : m_c(c) {}
    void run() Q_DECL_OVERRIDE
    {
        Value input = Value(1000, Eur);
        Value v = m_c.convert(input, QStringLiteral("$"));
        number = v.number();
    }
    int number;
    Converter &m_c;
};

void ConverterTest::testCurrency()
{
    Converter c;
    // 2 threads is enough for tsan to notice races, let's not hammer the website with more concurrent requests
    const int numThreads = 2;
    QVector<CurrencyTestThread *> threads;
    threads.resize(numThreads);
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = new CurrencyTestThread(c);
    }
    for (int i = 0; i < numThreads; ++i) {
        threads[i]->start();
    }
    for (int i = 0; i < numThreads; ++i) {
        threads[i]->wait();
        QVERIFY(threads.at(i)->number > 100);
    }
    qDeleteAll(threads);
}

QTEST_MAIN(ConverterTest)

