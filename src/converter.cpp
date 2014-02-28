/*
 *   Copyright (C) 2008-2009 Petri Damstén <damu@iki.fi>
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

#include "converter.h"

#include <klocalizedstring.h>

#include "unit.h"
#include "unitcategory.h"

#include "area_p.h"
#include "length_p.h"
#include "currency_p.h"
#include "density_p.h"
#include "energy_p.h"
#include "fuel_efficiency_p.h"
#include "mass_p.h"
#include "power_p.h"
#include "pressure_p.h"
#include "temperature_p.h"
#include "timeunit_p.h"
#include "velocity_p.h"
#include "volume_p.h"
#include "acceleration_p.h"
#include "force_p.h"
#include "angle_p.h"
#include "frequency_p.h"

namespace KUnitConversion
{

class ConverterPrivate
{
public:
    QMap<int, UnitCategory> categories;
    ConverterPrivate()
    {
        categories[LengthCategory] = Length();
        categories[AreaCategory] = Area();
        categories[VolumeCategory] = Volume();
        categories[TemperatureCategory] = Temperature();
        categories[VelocityCategory] = Velocity();
        categories[MassCategory] = Mass();
        categories[PressureCategory] = Pressure();
        categories[EnergyCategory] = Energy();
        categories[CurrencyCategory] = Currency();
        categories[PowerCategory] = Power();
        categories[TimeCategory] = Time();
        categories[FuelEfficiencyCategory] = FuelEfficiency();
        categories[DensityCategory] = Density();
        categories[AccelerationCategory] = Acceleration();
        categories[ForceCategory] = Force();
        categories[AngleCategory] = Angle();
        categories[FrequencyCategory] = Frequency();
    };

    ~ConverterPrivate()
    {
    };
};

Q_GLOBAL_STATIC(ConverterPrivate, static_d)

Converter::Converter(QObject *parent)
    : QObject(parent), d(static_d())
{
}

Converter::~Converter()
{
}

Value Converter::convert(const Value &value, const QString &toUnit) const
{
    if (value.unit().isValid()) {
        return value.unit().category().convert(value, toUnit);
    }
    return Value();
}

Value Converter::convert(const Value &value, int toUnit) const
{
    if (value.unit().isValid()) {
        return value.unit().category().convert(value, toUnit);
    }
    return Value();
}

Value Converter::convert(const Value &value, const Unit &toUnit) const
{
    if (toUnit.isValid() && value.unit().isValid()) {
        return value.unit().category().convert(value, toUnit);
    }
    return Value();
}

UnitCategory Converter::categoryForUnit(const QString &unit) const
{
    foreach (const UnitCategory &u, categories()) {
        if (u.hasUnit(unit)) {
            return u;
        }
    }
    return UnitCategory();
}

Unit Converter::unit(const QString &unitString) const
{
    foreach (const UnitCategory &u, d->categories) {
        Unit unitClass = u.unit(unitString);
        if (unitClass.isValid()) {
            return unitClass;
        }
    }
    return Unit();
}

Unit Converter::unit(int unitId) const
{
    foreach (const UnitCategory &u, d->categories) {
        Unit unitClass = u.unit(unitId);
        if (unitClass.isValid()) {
            return unitClass;
        }
    }
    return Unit();
}

UnitCategory Converter::category(const QString &category) const
{
    foreach (const UnitCategory &u, d->categories) {
        if (u.name() == category) {
            return u;
        }
    }
    // not found
    return UnitCategory();
}

UnitCategory Converter::category(int categoryId) const
{
    if (d->categories.contains(categoryId)) {
        return d->categories[categoryId];
    }
    // not found
    return UnitCategory();
}

QList<UnitCategory> Converter::categories() const
{
    QList<UnitCategory> categories = d->categories.values();
    return categories;
}

}

