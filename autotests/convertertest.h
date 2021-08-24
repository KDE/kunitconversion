/*
 *   SPDX-FileCopyrightText: 2009 Petri Damstén <damu@iki.fi>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef CONVERTERTEST_H
#define CONVERTERTEST_H

#include <QObject>
#include <QTest>
#include <kunitconversion/converter.h>

using namespace KUnitConversion;

class ConverterTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void initTestCase();
    void testCategory();
    void testUnits();
    void testConvert();
    void testInvalid();
    void testCurrency();
    /**
     * Checks that conversion tables are updated after timeout
     *
     * Regression test for https://bugs.kde.org/show_bug.cgi?id=441337
     */
    void testCurrencyConversionTableUpdate();
};

#endif // CONVERTERTEST_H
