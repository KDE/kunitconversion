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

#include "density_p.h"
#include "unit_p.h"

#include <klocalizedstring.h>

namespace KUnitConversion
{

Density::Density() : CustomCategory(DensityCategory, i18n("Density"), i18n("Density"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (density)", "%1 %2");

    addDefaultUnit(CustomUnit(DensityCategory, KilogramsPerCubicMeter, 1,
                              i18nc("density unit symbol", "kg/m³"),
                              i18nc("unit description in lists", "kilograms per cubic meter"),
                              i18nc("unit synonyms for matching user input",
                                    "kilogram per cubic meter;kilograms per cubic meter;kg/m³"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 kilograms per cubic meter"),
                              ki18ncp("amount in units (integer)",
                                      "%1 kilogram per cubic meter", "%1 kilograms per cubic meter")));

    // source Google calculator
    addCommonUnit(CustomUnit(DensityCategory, KilogramPerLiter, 1000,
                             i18nc("density unit symbol", "kg/l"),
                             i18nc("unit description in lists", "kilograms per liter"),
                             i18nc("unit synonyms for matching user input",
                                   "kilogram per liter;kilograms per liter;kg/l"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kilograms per liter"),
                             ki18ncp("amount in units (integer)", "%1 kilogram per liter", "%1 kilograms per liter")));

    addUnit(CustomUnit(DensityCategory, GramPerLiter, 1,
                       i18nc("density unit symbol", "g/l"),
                       i18nc("unit description in lists", "grams per liter"),
                       i18nc("unit synonyms for matching user input", "gram per liter;grams per liter;g/l"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 grams per liter"),
                       ki18ncp("amount in units (integer)", "%1 gram per liter", "%1 grams per liter")));

    addUnit(CustomUnit(DensityCategory, GramPerMilliliter, 1000,
                       i18nc("density unit symbol", "g/ml"),
                       i18nc("unit description in lists", "grams per milliliter"),
                       i18nc("unit synonyms for matching user input",
                             "gram per milliliter;grams per milliliter;g/ml"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 grams per milliliter"),
                       ki18ncp("amount in units (integer)", "%1 gram per milliliter", "%1 grams per milliliter")));

    // source : Google calculator
    addUnit(CustomUnit(DensityCategory, OuncePerCubicInch, 1729.99404,
                       i18nc("density unit symbol", "oz/in³"),
                       i18nc("unit description in lists", "ounces per cubic inch"),
                       i18nc("unit synonyms for matching user input",
                             "ounce per cubic inch;ounces per cubic inch;oz/in³"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 ounces per cubic inch"),
                       ki18ncp("amount in units (integer)", "%1 ounce per cubic inch", "%1 ounces per cubic inch")));

    addCommonUnit(CustomUnit(DensityCategory, OuncePerCubicFoot, 1.00115396,
                             i18nc("density unit symbol", "oz/ft³"),
                             i18nc("unit description in lists", "ounces per cubic foot"),
                             i18nc("unit synonyms for matching user input",
                                   "ounce per cubic foot;ounces per cubic foot;oz/ft³"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 ounces per cubic foot"),
                             ki18ncp("amount in units (integer)", "%1 ounce per cubic foot", "%1 ounces per cubic foot")));

    addUnit(CustomUnit(DensityCategory, PoundPerCubicInch, 27679.9047,
                       i18nc("density unit symbol", "lb/in³"),
                       i18nc("unit description in lists", "pounds per cubic inch"),
                       i18nc("unit synonyms for matching user input",
                             "pound per cubic inch;pounds per cubic inch;lb/in³"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 pounds per cubic inch"),
                       ki18ncp("amount in units (integer)", "%1 pound per cubic inch", "%1 pounds per cubic inch")));

    addUnit(CustomUnit(DensityCategory, PoundPerCubicFoot, 16.0184634,
                       i18nc("density unit symbol", "lb/ft³"),
                       i18nc("unit description in lists", "pounds per cubic foot"),
                       i18nc("unit synonyms for matching user input",
                             "pound per cubic foot;pounds per cubic foot;lb/ft³"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 pounds per cubic foot"),
                       ki18ncp("amount in units (integer)", "%1 pound per cubic foot", "%1 pounds per cubic foot")));

    addUnit(CustomUnit(DensityCategory, PoundPerCubicYard, 0.593276421,
                       i18nc("density unit symbol", "lb/yd³"),
                       i18nc("unit description in lists", "pounds per cubic yard"),
                       i18nc("unit synonyms for matching user input",
                             "pound per cubic yard;pounds per cubic yard;lb/yd³"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 pounds per cubic yard"),
                       ki18ncp("amount in units (integer)", "%1 pound per cubic yard", "%1 pounds per cubic yard")));
}

} // KUnitConversion namespace
