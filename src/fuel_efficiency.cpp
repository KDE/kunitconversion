/*
 *   Copyright (C) 2009 Petri Damstén <damu@iki.fi>
 *   Copyright (C) 2014 John Layt <jlayt@kde.org>
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

#include "fuel_efficiency_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

class FuelUnitPrivate : public UnitPrivate
{
public:
    FuelUnitPrivate(CategoryId categoryId, UnitId id, qreal multiplier,
                    const QString &symbol, const QString &description,
                    const QString &matchString, const KLocalizedString &symbolString,
                    const KLocalizedString &realString, const KLocalizedString &integerString)
        : UnitPrivate(categoryId, id, multiplier,
                      symbol, description,
                      matchString, symbolString,
                      realString, integerString)
    {}

    qreal toDefault(qreal value) const override
    {
        return unitMultiplier() / value;
    }

    qreal fromDefault(qreal value) const override
    {
        return unitMultiplier() / value;
    }
};

FuelEfficiency::FuelEfficiency() : CustomCategory(FuelEfficiencyCategory, i18n("Fuel Efficiency"), i18n("Fuel Efficiency"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (fuel efficiency)", "%1 %2");

    addDefaultUnit(CustomUnit(new FuelUnitPrivate(FuelEfficiencyCategory, LitersPer100Kilometers, 1,
                                                  i18nc("fuelefficiency unit symbol", "l/100 km"),
                                                  i18nc("unit description in lists", "liters per 100 kilometers"),
                                                  i18nc("unit synonyms for matching user input",
                                                        "liters per 100 kilometers;liters per 100 kilometers;l/100 km;L/100 km"),
                                                  symbolString,
                                                  ki18nc("amount in units (real)", "%1 liters per 100 kilometers"),
                                                  ki18ncp("amount in units (integer)", "%1 liters per 100 kilometers",
                                                          "%1 liters per 100 kilometers"))));

    addCommonUnit(CustomUnit(new FuelUnitPrivate(FuelEfficiencyCategory, MilePerUsGallon, 235.2,
                                                 i18nc("fuelefficiency unit symbol", "mpg"),
                                                 i18nc("unit description in lists", "miles per US gallon"),
                                                 i18nc("unit synonyms for matching user input",
                                                       "mile per US gallon;miles per US gallon;mpg"),
                                                 symbolString,
                                                 ki18nc("amount in units (real)", "%1 miles per US gallon"),
                                                 ki18ncp("amount in units (integer)", "%1 mile per US gallon",
                                                         "%1 miles per US gallon"))));

    addCommonUnit(CustomUnit(new FuelUnitPrivate(FuelEfficiencyCategory, MilePerImperialGallon, 282.5,
                                                 i18nc("fuelefficiency unit symbol", "mpg (imperial)"),
                                                 i18nc("unit description in lists", "miles per imperial gallon"),
                                                 i18nc("unit synonyms for matching user input",
                                                       "mile per imperial gallon;miles per imperial gallon;mpg (imperial)"),
                                                 symbolString,
                                                 ki18nc("amount in units (real)", "%1 miles per imperial gallon"),
                                                 ki18ncp("amount in units (integer)", "%1 mile per imperial gallon",
                                                         "%1 miles per imperial gallon"))));

    addCommonUnit(CustomUnit(new FuelUnitPrivate(FuelEfficiencyCategory, KilometrePerLitre, 100.0,
                                                 i18nc("fuelefficiency unit symbol", "kmpl"),
                                                 i18nc("unit description in lists", "kilometers per liter"),
                                                 i18nc("unit synonyms for matching user input",
                                                       "kilometer per liter;kilometers per liter;kmpl;km/l"),
                                                 symbolString,
                                                 ki18nc("amount in units (real)", "%1 kilometers per liter"),
                                                 ki18ncp("amount in units (integer)", "%1 kilometer per liter",
                                                         "%1 kilometers per liter"))));
}

} // KUnitConversion namespace
