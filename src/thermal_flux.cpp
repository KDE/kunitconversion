/*
 *   Copyright (C) 2010 Petri Damstén <damu@iki.fi>
 *   Copyright (C) 2014 John Layt <jlayt@kde.org>
 *   Copyright (C) 2014 Garret Wassermann <gwasser@gmail.com>
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

#include "thermal_flux_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

ThermalFlux::ThermalFlux() : CustomCategory(ThermalFluxCategory, i18n("Thermal Flux Density"), i18n("Thermal Flux Density"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (thermal flux density)", "%1 %2");

    addDefaultUnit(CustomUnit(ThermalFluxCategory, WattPerSquareMeter, 1,
                              i18nc("thermal flux unit symbol", "W/m²"),
                              i18nc("unit description in lists", "watt per square meter"),
                              i18nc("unit synonyms for matching user input",
                                    "watt per square meter;W/m2;W/m^2"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 watts per square meter"),
                              ki18ncp("amount in units (integer)", "%1 watt per square meter",
                                      "%1 watts per square meter")));

    addCommonUnit(CustomUnit(ThermalFluxCategory, BtuPerHourPerSquareFoot, 0.3169986,
                             i18nc("thermal flux unit symbol", "Btu/hr/ft²"),
                             i18nc("unit description in lists", "btu per hour per square foot"),
                             i18nc("unit synonyms for matching user input",
                                   "btu per hour per square foot;Btu/hr/ft2;Btu/hr/ft^2;Btu/ft^2/hr;Btu/ft2/hr"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 btu per hour per square foot"),
                             ki18ncp("amount in units (integer)", "%1 btu per hour per square foot",
                                     "%1 btu per hour per square foot")));

}

} // KUnitConversion namespace
