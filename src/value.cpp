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

#include "value.h"
#include "converter.h"
#include <qmath.h>

namespace KUnitConversion
{

class ValuePrivate : public QSharedData
{
public:
    ValuePrivate()
        : number(0)
    {
    }

    ValuePrivate(double n = 0.0, int u = InvalidUnit)
        : number(n)
    {
        unit = converter.unit(u);
    }

    ValuePrivate(double n, const Unit &u)
        : number(n)
        , unit(u)
    {
    }

    ValuePrivate(double n, const QString &u)
        : number(n)
    {
        unit = converter.unit(u);
    }

    ValuePrivate(const ValuePrivate &other)
        : QSharedData(other),
          number(other.number),
          unit(other.unit)
    {
    }

    virtual ~ValuePrivate()
    {
    }

    ValuePrivate &operator=(const ValuePrivate &other)
    {
        number = other.number;
        unit = other.unit;
        return *this;
    }

    ValuePrivate *clone()
    {
        return new ValuePrivate(*this);
    }

    bool operator==(const ValuePrivate &other) const
    {
        return (number == other.number && unit == other.unit);
    }

    bool operator!=(const ValuePrivate &other) const
    {
        return !(*this == other);
    }

    double number;
    Unit unit;
    Converter converter;
};

Value::Value()
    : d(0)
{
}

Value::Value(double n, const Unit &u)
    : d(new ValuePrivate(n, u))
{
}

Value::Value(double n, const QString &u)
    : d(new ValuePrivate(n, u))
{
}

Value::Value(double n, int u)
    : d(new ValuePrivate(n, u))
{
}

Value::Value(const QVariant &n, const QString &u)
    : d(new ValuePrivate(n.toDouble(), u))
{
}

Value::~Value()
{
}

Value &Value::operator=(const Value &other)
{
    d = other.d;
    return *this;
}

bool Value::operator==(const Value &other) const
{
    if (d && other.d)
        return (*d == *other.d);
    else
        return (d == other.d);
}

bool Value::operator!=(const Value &other) const
{
    if (d && other.d)
        return (*d != *other.d);
    else
        return (d != other.d);
}

bool Value::isNull() const
{
    return (d <= 0);
}

bool Value::isValid() const
{
    return (d && d->unit.isValid());
}

QString Value::toString(int fieldWidth, char format, int precision, const QChar &fillChar) const
{
    if (isValid()) {
        return d->unit.toString(d->number, fieldWidth, format, precision, fillChar);
    }
    return QString();
}

QString Value::toSymbolString(int fieldWidth, char format, int precision,
                              const QChar &fillChar) const
{
    if (isValid()) {
        return d->unit.toSymbolString(d->number, fieldWidth, format, precision, fillChar);
    }
    return QString();
}

Value &Value::round(uint decimals)
{
    if (!isValid())
        return *this;

    uint div = qPow(10, decimals);
    double add = 0.5 / (double)div;

    d->number = (int)((d->number + add) * div) / (double)div;
    return *this;
}

double Value::number() const
{
    if (d)
        return d->number;
    return 0;
}

Unit Value::unit() const
{
    if (d)
        return d->unit;
    return Unit();
}

Value Value::convertTo(const Unit &unit) const
{
    if (d)
        return d->converter.convert(*this, unit);
    return Value();
}

Value Value::convertTo(int unit) const
{
    if (d)
        return d->converter.convert(*this, unit);
    return Value();
}

Value Value::convertTo(const QString &unit) const
{
    if (d)
        return d->converter.convert(*this, unit);
    return Value();
}

}
