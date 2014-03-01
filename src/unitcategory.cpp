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
#include <klocalizedstring.h>
#include <QMap>

namespace KUnitConversion
{

class UnitCategoryPrivate : public QSharedData
{
public:
    UnitCategoryPrivate() : m_id(InvalidCategory)
    {
    };

    virtual ~UnitCategoryPrivate()
    {
    };

    UnitCategoryPrivate *clone()
    {
        return new UnitCategoryPrivate(*this);
    }

    bool operator==(const UnitCategoryPrivate &other) const
    {
        return (m_id == other.m_id);
    }

    bool operator!=(const UnitCategoryPrivate &other) const
    {
        return !(*this == other);
    }

    QString m_name;
    Unit m_defaultUnit;
    QMap<QString, Unit> m_unitMap;
    QMap<UnitId, Unit> m_idMap;
    QList<Unit> m_units;
    QList<Unit> m_mostCommonUnits;
    QString m_description;
    KLocalizedString m_symbolStringFormat;
    CategoryId m_id;
};

UnitCategory::UnitCategory()
    : d(0)
{
}

UnitCategory::UnitCategory(CategoryId id)
    : d(new UnitCategoryPrivate)
{
    d->m_id = id;
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

void UnitCategory::setSymbolStringFormat(const KLocalizedString &symbolStringFormat)
{
    if (d)
        d->m_symbolStringFormat = symbolStringFormat;
}

KLocalizedString UnitCategory::symbolStringFormat() const
{
    if (d)
        return d->m_symbolStringFormat;
    return KLocalizedString();
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

void UnitCategory::setMostCommonUnits(const QList<UnitId> &units)
{
    if (isNull())
        return;
    d->m_mostCommonUnits.clear();
    foreach (UnitId u, units) {
        d->m_mostCommonUnits.append(unit(u));
    }
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
        double v = toUnit.fromDefault(value.unit().toDefault(value.number()));
        return Value(v, toUnit);
    }
    return Value();
}

void UnitCategory::addUnitMapValues(const Unit &unit, const QString &names)
{
    if (isNull())
        return;
    const QStringList list = names.split(';');
    foreach (const QString &name, list) {
        d->m_unitMap[name] = unit;
    }
}

void UnitCategory::addIdMapValue(const Unit &unit, UnitId id)
{
    if (isNull())
        return;
    d->m_idMap[id] = unit;
    d->m_units.append(unit);
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

void UnitCategory::setName(const QString &name)
{
    if (d)
        d->m_name = name;
}

void UnitCategory::setDefaultUnit(const Unit &defaultUnit)
{
    if (d)
        d->m_defaultUnit = defaultUnit;
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

void UnitCategory::setDescription(const QString &description)
{
    if (d)
        d->m_description = description;
}

}
