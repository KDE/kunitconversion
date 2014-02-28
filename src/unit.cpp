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

#include "unit.h"
#include "unitcategory.h"

#include <klocalizedstring.h>
#include <qdebug.h>

namespace KUnitConversion
{

Complex::Complex()
{
}

Complex::~Complex()
{
}

class UnitPrivate : public QSharedData
{
public:
    UnitPrivate()
        : multiplier(0),
          complex(0),
          id(int(InvalidUnit))
    {
    };

    UnitPrivate(const UnitCategory &category, const Complex *complex = 0)
        : multiplier(1.0)
        , complex(complex)
        , category(category)
    {
    };

    virtual ~UnitPrivate()
    {
    };

    UnitPrivate *clone()
    {
        return new UnitPrivate(*this);
    }

    bool operator==(const UnitPrivate &other) const
    {
        return (id == other.id && symbol == other.symbol);
    }

    bool operator!=(const UnitPrivate &other) const
    {
        return !(*this == other);
    }

    QString symbol;
    QString description;
    double multiplier;
    KLocalizedString real;
    KLocalizedString integer;
    const Complex *complex;
    UnitCategory category;
    int id;
};

Unit::Unit()
    : d(0)
{
}

Unit::Unit(const UnitCategory &category, int id, double multiplier, const QString &symbol,
           const QString &description, const QString &match,
           const KLocalizedString &real, const KLocalizedString &integer)
    : d(new UnitPrivate(category))
{
    d->multiplier = multiplier;
    d->real = real;
    d->integer = integer;
    d->symbol = symbol;
    d->description = description;
    d->id = id;
    d->category.addUnitMapValues(*this, match);
    d->category.addIdMapValue(*this, id);
}

Unit::Unit(const UnitCategory &category, int id, const Complex *complex, const QString &symbol,
           const QString &description, const QString &match,
           const KLocalizedString &real, const KLocalizedString &integer)
    : d(new UnitPrivate(category, complex))
{
    d->real = real;
    d->integer = integer;
    d->symbol = symbol;
    d->description = description;
    d->id = id;
    d->category.addUnitMapValues(*this, match);
    d->category.addIdMapValue(*this, id);
}

Unit::Unit(const Unit &other)
    : d(other.d)
{
}

Unit::~Unit()
{
}

Unit &Unit::operator=(const Unit &other)
{
    d = other.d;
    return *this;
}

bool Unit::operator==(const Unit &other) const
{
    if (d && other.d)
        return (*d == *other.d);
    else
        return (d == other.d);
}

bool Unit::operator!=(const Unit &other) const
{
    if (d && other.d)
        return (*d != *other.d);
    else
        return (d != other.d);
}

bool Unit::isNull() const
{
    return (d <= 0);
}

UnitCategory Unit::category() const
{
    if (d)
        return d->category;
    return (int)InvalidCategory;
}

QString Unit::description() const
{
    if (d)
        return d->description;
    return QString();
}

QString Unit::symbol() const
{
    if (d)
        return d->symbol;
    return QString();
}

double Unit::multiplier() const
{
    if (d)
        return d->multiplier;
    return 0;
}

void Unit::setMultiplier(double multiplier)
{
    if (d)
        d->multiplier = multiplier;
}

double Unit::toDefault(double value) const
{
    if (isNull())
        return 0;
    if (d->complex) {
        return d->complex->toDefault(value);
    } else {
        return value * d->multiplier;
    }
}

double Unit::fromDefault(double value) const
{
    if (isNull())
        return 0;
    if (d->complex) {
        return d->complex->fromDefault(value);
    } else {
        return value / d->multiplier;
    }
}

QString Unit::toString(double value, int fieldWidth, char format, int precision,
                       const QChar &fillChar) const
{
    if (isNull())
        return QString();
    if ((int)value == value && precision < 1) {
        return d->integer.subs((int)value).toString();
    }
    return d->real.subs(value, fieldWidth, format, precision, fillChar).toString();
}

QString Unit::toSymbolString(double value, int fieldWidth, char format, int precision,
                             const QChar &fillChar) const
{
    if (isNull())
        return QString();
    return category().symbolStringFormat().subs(value, fieldWidth, format, precision, fillChar)
           .subs(d->symbol).toString();
}

bool Unit::isValid() const
{
    return (d && !d->symbol.isEmpty());
}

int Unit::id() const
{
    if (d)
        return d->id;
    return int(InvalidUnit);
}

}

