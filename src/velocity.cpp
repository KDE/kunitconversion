/*
 *   Copyright (C) 2008-2009 Petri Damstén <damu@iki.fi>
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

#include "velocity_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

#include <math.h>


namespace KUnitConversion
{

class BeaufortUnitPrivate : public UnitPrivate
{
public:
    BeaufortUnitPrivate(CategoryId categoryId, UnitId id, qreal multiplier,
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
        return 0.836 * pow(value, 3.0 / 2.0);
    }

    qreal fromDefault(qreal value) const override
    {
        return pow(value / 0.836, 2.0 / 3.0);
    }
};

Velocity::Velocity() : CustomCategory(VelocityCategory, i18n("Speed"), i18n("Speed"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (velocity)", "%1 %2");

    addDefaultUnit(CustomUnit(VelocityCategory, MeterPerSecond, 1,
                              i18nc("velocity unit symbol", "m/s"),
                              i18nc("unit description in lists", "meters per second"),
                              i18nc("unit synonyms for matching user input", "meter per second;meters per second;m/s;ms"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 meters per second"),
                              ki18ncp("amount in units (integer)", "%1 meter per second", "%1 meters per second")));

    addCommonUnit(CustomUnit(VelocityCategory, KilometerPerHour, 0.277778,
                             i18nc("velocity unit symbol", "km/h"),
                             i18nc("unit description in lists", "kilometers per hour"),
                             i18nc("unit synonyms for matching user input",
                                   "kilometer per hour;kilometers per hour;km/h;kmh"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kilometers per hour"),
                             ki18ncp("amount in units (integer)", "%1 kilometer per hour", "%1 kilometers per hour")));

    addCommonUnit(CustomUnit(VelocityCategory, MilePerHour, 0.44704,
                             i18nc("velocity unit symbol", "mph"),
                             i18nc("unit description in lists", "miles per hour"),
                             i18nc("unit synonyms for matching user input", "mile per hour;miles per hour;mph"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 miles per hour"),
                             ki18ncp("amount in units (integer)", "%1 mile per hour", "%1 miles per hour")));

    addUnit(CustomUnit(VelocityCategory, FootPerSecond, 0.3048,
                       i18nc("velocity unit symbol", "ft/s"),
                       i18nc("unit description in lists", "feet per second"),
                       i18nc("unit synonyms for matching user input",
                             "foot per second;feet per second;ft/s;ft/sec;fps"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 feet per second"),
                       ki18ncp("amount in units (integer)", "%1 foot per second", "%1 feet per second")));

    addUnit(CustomUnit(VelocityCategory, InchPerSecond, 0.0254,
                       i18nc("velocity unit symbol", "in/s"),
                       i18nc("unit description in lists", "inches per second"),
                       i18nc("unit synonyms for matching user input",
                             "inch per second;inches per second;in/s;in/sec;ips"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 inches per second"),
                       ki18ncp("amount in units (integer)", "%1 inch per second", "%1 inches per second")));

    addCommonUnit(CustomUnit(VelocityCategory, Knot, 0.514444,
                             i18nc("velocity unit symbol", "kt"),
                             i18nc("unit description in lists", "knots"),
                             i18nc("unit synonyms for matching user input", "knot;knots;kt;nautical miles per hour"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 knots"),
                             ki18ncp("amount in units (integer)", "%1 knot", "%1 knots")));

    // http://en.wikipedia.org/wiki/Speed_of_sound
    addCommonUnit(CustomUnit(VelocityCategory, Mach, 343,
                             i18nc("velocity unit symbol", "Ma"),
                             i18nc("unit description in lists", "Mach"),
                             i18nc("unit synonyms for matching user input", "mach;machs;Ma;speed of sound"),
                             symbolString,
                             ki18nc("amount in units (real)", "Mach %1"),
                             ki18ncp("amount in units (integer)", "Mach %1", "Mach %1")));

    addUnit(CustomUnit(VelocityCategory, SpeedOfLight, 2.99792458e+08,
                       i18nc("velocity unit symbol", "c"),
                       i18nc("unit description in lists", "speed of light"),
                       i18nc("unit synonyms for matching user input", "speed of light;c"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 speed of light"),
                       ki18ncp("amount in units (integer)", "%1 speed of light", "%1 speed of light")));

    // http://en.wikipedia.org/wiki/Beaufort_scale
    addUnit(CustomUnit(new BeaufortUnitPrivate(VelocityCategory, Beaufort, 1.0,
                                               i18nc("velocity unit symbol", "bft"),
                                               i18nc("unit description in lists", "Beaufort"),
                                               i18nc("unit synonyms for matching user input", "Beaufort;Bft"),
                                               symbolString,
                                               ki18nc("amount in units (real)", "%1 on the Beaufort scale"),
                                               ki18ncp("amount in units (integer)", "%1 on the Beaufort scale",
                                                       "%1 on the Beaufort scale"))));
}

} // KUnitConversion namespace
