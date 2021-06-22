/*
 *   SPDX-FileCopyrightText: 2009 Petri Damstén <damu@iki.fi>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "categorytest.h"
#include <kunitconversion/unitcategory.h>

using namespace KUnitConversion;

void CategoryTest::initTestCase()
{
}

void CategoryTest::testInfo()
{
    UnitCategory cg = c.category(AreaCategory);
    QCOMPARE(cg.name(), QStringLiteral("Area"));
    QCOMPARE(cg.description(), QStringLiteral("Area"));
    QCOMPARE(cg.id(), AreaCategory);
}

void CategoryTest::testUnits()
{
    UnitCategory cg = c.category(MassCategory);
    QCOMPARE(cg.defaultUnit().symbol(), QStringLiteral("kg"));
    QCOMPARE(cg.hasUnit(QStringLiteral("g")), true);
    QCOMPARE(cg.unit(QStringLiteral("g")).symbol(), QStringLiteral("g"));
    QCOMPARE(cg.unit(Kilogram).symbol(), QStringLiteral("kg"));
    QVERIFY(cg.units().size() > 0);
    QVERIFY(cg.allUnits().size() > 0);
}

void CategoryTest::testConvert()
{
    UnitCategory cg = c.category(LengthCategory);
    Value v = cg.convert(Value(3.14, Kilometer), QStringLiteral("m"));
    QCOMPARE(v.number(), 3140.0);
    v = cg.convert(v, QStringLiteral("cm"));
    QCOMPARE(v.number(), 314000.0);
    v = cg.convert(v, cg.defaultUnit());
    QCOMPARE(v.number(), 3140.0);
}

void CategoryTest::testInvalid()
{
    UnitCategory cg = c.category(CategoryId(99999));
    QCOMPARE(cg.name(), QString());
    cg = c.category(QStringLiteral("don't exist"));
    QCOMPARE(cg.name(), QString());
}

QTEST_MAIN(CategoryTest)
