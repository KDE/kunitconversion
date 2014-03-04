/*
 *   Copyright (C) 2007-2009 Petri Damstén <damu@iki.fi>
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

#include "unitcategory.h"
#include "unitcategory_p.h"
#include "unit_p.h"

#include <klocalizedstring.h>
#include <QMap>

namespace KUnitConversion
{

UnitCategoryPrivate::UnitCategoryPrivate()
    : m_id(InvalidCategory)
{
}

UnitCategoryPrivate::UnitCategoryPrivate(CategoryId id, const QString &name, const QString &description)
    : m_id(id),
      m_name(name),
      m_description(description)
{
}

UnitCategoryPrivate::~UnitCategoryPrivate()
{
}

UnitCategoryPrivate *UnitCategoryPrivate::clone()
{
    return new UnitCategoryPrivate(*this);
}

bool UnitCategoryPrivate::operator==(const UnitCategoryPrivate &other) const
{
    return (m_id == other.m_id);
}

bool UnitCategoryPrivate::operator!=(const UnitCategoryPrivate &other) const
{
    return !(*this == other);
}

Value UnitCategoryPrivate::convert(const Value &value, const Unit &toUnit)
{
    qreal v = value.unit().toDefault(value.number());
    return Value(toUnit.fromDefault(v), toUnit);
}

UnitCategory::UnitCategory()
    : d(0)
{
}

UnitCategory::UnitCategory(UnitCategoryPrivate *dd)
    : d(dd)
{
}

UnitCategory::UnitCategory(const UnitCategory &other)
    : d(other.d)
{
}

UnitCategory::~UnitCategory()
{
}

UnitCategory &UnitCategory::operator=(const UnitCategory &other)
{
    d = other.d;
    return *this;
}

bool UnitCategory::operator==(const UnitCategory &other) const
{
    if (d && other.d)
        return (*d == *other.d);
    else
        return (d == other.d);
}

bool UnitCategory::operator!=(const UnitCategory &other) const
{
    if (d && other.d)
        return (*d != *other.d);
    else
        return (d != other.d);
}

bool UnitCategory::isNull() const
{
    return (d <= 0);
}

CategoryId UnitCategory::id() const
{
    if (d)
        return d->m_id;
    return InvalidCategory;
}

QList<Unit> UnitCategory::units() const
{
    if (d)
        return d->m_units;
    return QList<Unit>();
}

QList<Unit> UnitCategory::mostCommonUnits() const
{
    if (d)
        return d->m_mostCommonUnits;
    return QList<Unit>();
}

QStringList UnitCategory::allUnits() const
{
    if (d)
        return d->m_unitMap.keys();
    return QStringList();
}

bool UnitCategory::hasUnit(const QString &unit) const
{
    if (d)
        return d->m_unitMap.contains(unit);
    return false;
}

Value UnitCategory::convert(const Value &value, const QString &toUnit)
{
    if (d && (toUnit.isEmpty() || d->m_unitMap.contains(toUnit)) && value.unit().isValid()) {
        Unit to = toUnit.isEmpty() ? defaultUnit() : d->m_unitMap[toUnit];
        return convert(value, to);
    }
    return Value();
}

Value UnitCategory::convert(const Value &value, UnitId toUnit)
{
    if (d && d->m_idMap.contains(toUnit) && value.unit().isValid()) {
        return convert(value, d->m_idMap[toUnit]);
    }
    return Value();
}

Value UnitCategory::convert(const Value &value, const Unit &toUnit)
{
    if (d && !toUnit.isNull()) {
        qreal v = toUnit.fromDefault(value.unit().toDefault(value.number()));
        return Value(v, toUnit);
    }
    return Value();
}

Unit UnitCategory::unit(const QString &s) const
{
    if (d)
        return d->m_unitMap.value(s);
    return Unit();
}

Unit UnitCategory::unit(UnitId unitId) const
{
    if (d && d->m_idMap.contains(unitId)) {
        return d->m_idMap[unitId];
    }
    return Unit();
}

QString UnitCategory::name() const
{
    if (d)
        return d->m_name;
    return QString();
}

Unit UnitCategory::defaultUnit() const
{
    if (d)
        return d->m_defaultUnit;
    return Unit();
}

QString UnitCategory::description() const
{
    if (d)
        return d->m_description;
    return QString();
}

void UnitCategory::addDefaultUnit(const Unit &unit)
{
    if (d) {
        addCommonUnit(unit);
        d->m_defaultUnit = unit;
    }
}

void UnitCategory::addCommonUnit(const Unit &unit)
{
    if (d) {
        addUnit(unit);
        d->m_mostCommonUnits.append(unit);
    }
}

void UnitCategory::addUnit(const Unit &unit)
{
    if (d) {
        unit.d->m_category = *this;
        const QStringList list = unit.d->m_matchString.split(';');
        foreach (const QString &name, list)
            d->m_unitMap[name] = unit;
        d->m_idMap[unit.id()] = unit;
        d->m_units.append(unit);
    }
}

}
