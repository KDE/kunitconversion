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

#include "acceleration_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

Acceleration::Acceleration() : CustomCategory(AccelerationCategory, i18n("Acceleration"), i18n("Acceleration"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (acceleration)", "%1 %2");

    addDefaultUnit(CustomUnit(AccelerationCategory, MetresPerSecondSquared, 1,
                              i18nc("acceleration unit symbol", "m/s²"),
                              i18nc("unit description in lists", "meters per second squared"),
                              i18nc("unit synonyms for matching user input",
                                    "meter per second squared;meters per second squared;m/s²;m/s2;m/s^2"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 meters per second squared"),
                              ki18ncp("amount in units (integer)", "%1 meter per second squared",
                                      "%1 meters per second squared")));

    addCommonUnit(CustomUnit(AccelerationCategory, FeetPerSecondSquared, 0.3048,
                             i18nc("acceleration unit symbol", "ft/s²"),
                             i18nc("unit description in lists", "feet per second squared"),
                             i18nc("unit synonyms for matching user input",
                                   "foot per second squared;feet per second squared;ft/s²;ft/s2;ft/s^2"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 feet per second squared"),
                             ki18ncp("amount in units (integer)", "%1 foot per second squared",
                                     "%1 feet per second squared")));

    addUnit(CustomUnit(AccelerationCategory, StandardGravity, 9.80665,
                       i18nc("acceleration unit symbol", "g"),
                       i18nc("unit description in lists", "standard gravity"),
                       i18nc("unit synonyms for matching user input", "standard gravity;g"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 times standard gravity"),
                       ki18ncp("amount in units (integer)", "%1 standard gravity",
                               "%1 times standard gravity")));
}

} // KUnitConversion namespace
