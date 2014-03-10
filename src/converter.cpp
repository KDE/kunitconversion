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

#include "converter.h"

#include "acceleration_p.h"
#include "angle_p.h"
#include "area_p.h"
#include "currency_p.h"
#include "density_p.h"
#include "energy_p.h"
#include "force_p.h"
#include "frequency_p.h"
#include "fuel_efficiency_p.h"
#include "length_p.h"
#include "mass_p.h"
#include "power_p.h"
#include "pressure_p.h"
#include "temperature_p.h"
#include "timeunit_p.h"
#include "velocity_p.h"
#include "volume_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

class ConverterPrivate : public QSharedData
{
public:
    ConverterPrivate()
    {
        m_categories[LengthCategory] = Length();
        m_categories[AreaCategory] = Area();
        m_categories[VolumeCategory] = Volume();
        m_categories[TemperatureCategory] = Temperature();
        m_categories[VelocityCategory] = Velocity();
        m_categories[MassCategory] = Mass();
        m_categories[PressureCategory] = Pressure();
        m_categories[EnergyCategory] = Energy();
        m_categories[CurrencyCategory] = Currency();
        m_categories[PowerCategory] = Power();
        m_categories[TimeCategory] = Time();
        m_categories[FuelEfficiencyCategory] = FuelEfficiency();
        m_categories[DensityCategory] = Density();
        m_categories[AccelerationCategory] = Acceleration();
        m_categories[ForceCategory] = Force();
        m_categories[AngleCategory] = Angle();
        m_categories[FrequencyCategory] = Frequency();
    };

    virtual ~ConverterPrivate()
    {
    };

    ConverterPrivate *clone()
    {
        return new ConverterPrivate(*this);
    }

    bool operator==(const ConverterPrivate &other) const
    {
        return (m_categories == other.m_categories);
    }

    bool operator!=(const ConverterPrivate &other) const
    {
        return !(*this == other);
    }

    QMap<CategoryId, UnitCategory> m_categories;
};

class QConverterSingleton
{
public:
    QConverterSingleton() : d(new ConverterPrivate()) {}
    QExplicitlySharedDataPointer<ConverterPrivate> d;
};

Q_GLOBAL_STATIC(QConverterSingleton, global_converter)

Converter::Converter()
    : d(global_converter->d)
{
}

Converter::~Converter()
{
}

Converter::Converter(const Converter &other)
: d(other.d)
{
}

Converter &Converter::operator=(const Converter &other)
{
    d = other.d;
    return *this;
}

bool Converter::operator==(const Converter &other) const
{
    if (d && other.d)
        return (*d == *other.d);
    else
        return (d == other.d);
}

bool Converter::operator!=(const Converter &other) const
{
    if (d && other.d)
        return (*d != *other.d);
    else
        return (d != other.d);
}

Value Converter::convert(const Value &value, const QString &toUnit) const
{
    if (d && value.unit().isValid()) {
        return value.unit().category().convert(value, toUnit);
    }
    return Value();
}

Value Converter::convert(const Value &value, UnitId toUnit) const
{
    if (d && value.unit().isValid()) {
        return value.unit().category().convert(value, toUnit);
    }
    return Value();
}

Value Converter::convert(const Value &value, const Unit &toUnit) const
{
    if (d && toUnit.isValid() && value.unit().isValid()) {
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
    foreach (const UnitCategory &u, categories()) {
        Unit unitClass = u.unit(unitString);
        if (unitClass.isValid()) {
            return unitClass;
        }
    }
    return Unit();
}

Unit Converter::unit(UnitId unitId) const
{
    foreach (const UnitCategory &u, categories()) {
        Unit unitClass = u.unit(unitId);
        if (unitClass.isValid()) {
            return unitClass;
        }
    }
    return Unit();
}

UnitCategory Converter::category(const QString &category) const
{
    foreach (const UnitCategory &u, categories()) {
        if (u.name() == category) {
            return u;
        }
    }
    // not found
    return UnitCategory();
}

UnitCategory Converter::category(CategoryId categoryId) const
{
    if (d && d->m_categories.contains(categoryId)) {
        return d->m_categories[categoryId];
    }
    // not found
    return UnitCategory();
}

QList<UnitCategory> Converter::categories() const
{
    if (d)
        return d->m_categories.values();
    return QList<UnitCategory>();
}

}

