/*
 *   Copyright (C) 2010 Petri Damstén <damu@iki.fi>
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

#include "angle_p.h"
#include "unit_p.h"

#include <klocalizedstring.h>

#include <math.h>

namespace KUnitConversion
{

class RadiansUnitPrivate : public UnitPrivate
{
public:
    RadiansUnitPrivate(CategoryId categoryId, UnitId id, qreal multiplier,
                       const QString &symbol, const QString &description,
                       const QString &matchString, const KLocalizedString &symbolString,
                       const KLocalizedString &realString, const KLocalizedString &integerString)
        : UnitPrivate(categoryId, id, multiplier,
                      symbol, description,
                      matchString, symbolString,
                      realString, integerString)
    {};

    qreal toDefault(qreal value) const
    {
        return (value / (2 * M_PI)) * 360.0;
    };
    qreal fromDefault(qreal value) const
    {
        return (value / 360.0) * (2 * M_PI);
    };
};

Angle::Angle() : CustomCategory(AngleCategory, i18n("Angle"), i18n("Angle"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (angle)", "%1 %2");

    addDefaultUnit(CustomUnit(AngleCategory, Degree, 1,
                              i18nc("angle unit symbol", "°"),
                              i18nc("unit description in lists", "degrees"),
                              i18nc("unit synonyms for matching user input", "deg;degree;degrees;°"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 degrees"),
                              ki18ncp("amount in units (integer)", "%1 degree", "%1 degrees")));

    addCommonUnit(CustomUnit(new RadiansUnitPrivate(AngleCategory, Radian, 1.0,
                                                    i18nc("angle unit symbol", "rad"),
                                                    i18nc("unit description in lists", "radians"),
                                                    i18nc("unit synonyms for matching user input", "rad;radian;radians"),
                                                    symbolString,
                                                    ki18nc("amount in units (real)", "%1 radians"),
                                                    ki18ncp("amount in units (integer)", "%1 radian", "%1 radians"))));

    addUnit(CustomUnit(AngleCategory, Gradian, 360.0 / 400.0,
                       i18nc("angle unit symbol", "grad"),
                       i18nc("unit description in lists", "gradians"),
                       i18nc("unit synonyms for matching user input", "grad;gradian;gradians;grade;gon"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 gradians"),
                       ki18ncp("amount in units (integer)", "%1 gradian", "%1 gradians")));

    addCommonUnit(CustomUnit(AngleCategory, ArcMinute, 1.0 / 60.0,
                             i18nc("angle unit symbol", "'"),
                             i18nc("unit description in lists", "arc minutes"),
                             i18nc("unit synonyms for matching user input", "minute of arc;MOA;arcminute;minute;'"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 arc minutes"),
                             ki18ncp("amount in units (integer)", "%1 arc minute", "%1 arc minutes")));

    addCommonUnit(CustomUnit(AngleCategory, ArcSecond, 1.0 / 3600.0,
                             i18nc("angle unit symbol", "\""),
                             i18nc("unit description in lists", "arc seconds"),
                             i18nc("unit synonyms for matching user input", "second of arc;arcsecond;second;\""),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 arc seconds"),
                             ki18ncp("amount in units (integer)", "%1 arc second", "%1 arc seconds")));
}

} // KUnitConversion namespace
