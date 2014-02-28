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
    UnitCategoryPrivate() : id(int(InvalidCategory))
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
        return (id == other.id);
    }

    bool operator!=(const UnitCategoryPrivate &other) const
    {
        return !(*this == other);
    }

    QString name;
    Unit defaultUnit;
    QMap<QString, Unit> unitMap;
    QMap<int, Unit> idMap;
    QList<Unit> units;
    QList<Unit> mostCommonUnits;
    QString description;
    QUrl url;
    KLocalizedString symbolStringFormat;
    int id;
};

UnitCategory::UnitCategory()
    : d(0)
{
}

UnitCategory::UnitCategory(int id)
    : d(new UnitCategoryPrivate)
{
    d->id = id;
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

void UnitCategory::setSymbolStringFormat(const KLocalizedString &symbolStringFormat)
{
    if (d)
        d->symbolStringFormat = symbolStringFormat;
}

KLocalizedString UnitCategory::symbolStringFormat() const
{
    if (d)
        return d->symbolStringFormat;
    return KLocalizedString();
}

QList<Unit> UnitCategory::units() const
{
    if (d)
        return d->units;
    return QList<Unit>();
}

QList<Unit> UnitCategory::mostCommonUnits() const
{
    if (d)
        return d->mostCommonUnits;
    return QList<Unit>();
}

void UnitCategory::setMostCommonUnits(const QList<int> &units)
{
    if (isNull())
        return;
    d->mostCommonUnits.clear();
    foreach (int u, units) {
        d->mostCommonUnits.append(unit(u));
    }
}

QStringList UnitCategory::allUnits() const
{
    if (d)
        return d->unitMap.keys();
    return QStringList();
}

bool UnitCategory::hasUnit(const QString &unit) const
{
    if (d)
        return d->unitMap.contains(unit);
    return false;
}

Value UnitCategory::convert(const Value &value, const QString &toUnit)
{
    if (d && (toUnit.isEmpty() || d->unitMap.contains(toUnit)) && value.unit().isValid()) {
        Unit to = toUnit.isEmpty() ? defaultUnit() : d->unitMap[toUnit];
        return convert(value, to);
    }
    return Value();
}

Value UnitCategory::convert(const Value &value, int toUnit)
{
    if (d && d->idMap.contains(toUnit) && value.unit().isValid()) {
        return convert(value, d->idMap[toUnit]);
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
        d->unitMap[name] = unit;
    }
}

void UnitCategory::addIdMapValue(const Unit &unit, int id)
{
    if (isNull())
        return;
    d->idMap[id] = unit;
    d->units.append(unit);
}

Unit UnitCategory::unit(const QString &s) const
{
    if (d)
        return d->unitMap.value(s);
    return Unit();
}

Unit UnitCategory::unit(int unitId) const
{
    if (d && d->idMap.contains(unitId)) {
        return d->idMap[unitId];
    }
    return Unit();
}

QString UnitCategory::name() const
{
    if (d)
        return d->name;
    return QString();
}

void UnitCategory::setName(const QString &name)
{
    if (d)
        d->name = name;
}

void UnitCategory::setDefaultUnit(const Unit &defaultUnit)
{
    if (d)
        d->defaultUnit = defaultUnit;
}

Unit UnitCategory::defaultUnit() const
{
    if (d)
        return d->defaultUnit;
    return Unit();
}

QString UnitCategory::description() const
{
    if (d)
        return d->description;
    return QString();
}

void UnitCategory::setDescription(const QString &description)
{
    if (d)
        d->description = description;
}

QUrl UnitCategory::url() const
{
    if (d)
        return d->url;
    return QUrl();
}

void UnitCategory::setUrl(const QUrl &url)
{
    if (d)
        d->url = url;
}

int UnitCategory::id() const
{
    if (d)
        return d->id;
    return int(InvalidCategory);
}

}
