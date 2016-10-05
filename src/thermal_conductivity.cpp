/*
 *   Copyright (C) 2010 Petri Damstén <damu@iki.fi>
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

#include "thermal_conductivity_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

ThermalConductivity::ThermalConductivity() : CustomCategory(ThermalConductivityCategory, i18n("Thermal Conductivity"), i18n("Thermal Conductivity"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (thermal conductivity)", "%1 %2");

    addDefaultUnit(CustomUnit(ThermalConductivityCategory, WattPerMeterKelvin, 1,
                              i18nc("thermal conductivity unit symbol", "W/m·K"),
                              i18nc("unit description in lists", "watt per meter kelvin"),
                              i18nc("unit synonyms for matching user input",
                                    "watt per meter kelvin;watt per meter-kelvin;W/mK;W/m.K"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 watts per meter kelvin"),
                              ki18ncp("amount in units (integer)", "%1 watt per meter kelvin",
                                      "%1 watts per meter kelvin")));

    addCommonUnit(CustomUnit(ThermalConductivityCategory, BtuPerFootHourFahrenheit, 0.5779,
                             i18nc("thermal conductivity unit symbol", "Btu/ft·hr·°F"),
                             i18nc("unit description in lists", "btu per foot hour degree Fahrenheit"),
                             i18nc("unit synonyms for matching user input",
                                   "btu per foot hour degree Fahrenheit;btu per foot hour Fahrenheit;btu per foot-hour-Fahrenheit;Btu/ft-hr-F"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 btu per foot hour degree Fahrenheit"),
                             ki18ncp("amount in units (integer)", "%1 btu per foot hour degree Fahrenheit",
                                     "%1 btu per foot hour degree Fahrenheit")));

    addCommonUnit(CustomUnit(ThermalConductivityCategory, BtuPerSquareFootHourFahrenheitPerInch, 6.9348,
                             i18nc("thermal conductivity unit symbol", "Btu/ft²·hr·°F/in"),
                             i18nc("unit description in lists", "btu per square foot hour degree Fahrenheit per inch"),
                             i18nc("unit synonyms for matching user input",
                                   "btu per square foot hour degree Fahrenheit per inch;btu per foot squared hour Fahrenheit per inch;btu per sq foot-hour-Fahrenheit per inch;Btu/ft^2-hr-F/in"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 btu per square foot hour degree Fahrenheit per inch"),
                             ki18ncp("amount in units (integer)", "%1 btu per square foot hour degree Fahrenheit per inch",
                                     "%1 btu per square foot hour degree Fahrenheit per inch")));

}

} // KUnitConversion namespace
