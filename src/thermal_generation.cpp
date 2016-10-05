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

#include "thermal_generation_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

ThermalGeneration::ThermalGeneration() : CustomCategory(ThermalGenerationCategory, i18n("Thermal Generation"), i18n("Thermal Generation"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (thermal generation)", "%1 %2");

    addDefaultUnit(CustomUnit(ThermalGenerationCategory, WattPerCubicMeter, 1,
                              i18nc("thermal generation unit symbol", "W/m³"),
                              i18nc("unit description in lists", "watt per cubic meter"),
                              i18nc("unit synonyms for matching user input",
                                    "watt per cubic meter;W/m3;W/m^3"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 watts per cubic meter"),
                              ki18ncp("amount in units (integer)", "%1 watt per cubic meter",
                                      "%1 watts per cubic meter")));

    addCommonUnit(CustomUnit(ThermalGenerationCategory, BtuPerHourPerCubicFoot, 0.09662,
                             i18nc("thermal generation unit symbol", "Btu/hr/ft³"),
                             i18nc("unit description in lists", "btu per hour per cubic foot"),
                             i18nc("unit synonyms for matching user input",
                                   "btu per hour per cubic foot;Btu/hr/ft3;Btu/hr/ft^3;Btu/ft^3/hr;Btu/ft3/hr"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 btu per hour per cubic foot"),
                             ki18ncp("amount in units (integer)", "%1 btu per hour per cubic foot",
                                     "%1 btu per hour per cubic foot")));

}

} // KUnitConversion namespace
