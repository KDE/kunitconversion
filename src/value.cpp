/*
 *   Copyright (C) 2007-2009 Petri Damstén <damu@iki.fi>
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

#include "value.h"
#include "converter.h"

#include <qmath.h>

namespace KUnitConversion
{

class ValuePrivate : public QSharedData
{
public:
    ValuePrivate()
        : m_number(0)
    {
    }

    ValuePrivate(qreal number, UnitId unitId = InvalidUnit)
        : m_number(number)
    {
        m_unit = m_converter.unit(unitId);
    }

    ValuePrivate(qreal number, const Unit &unit)
        : m_number(number),
          m_unit(unit)
    {
    }

    ValuePrivate(qreal number, const QString &unitString)
        : m_number(number)
    {
        m_unit = m_converter.unit(unitString);
    }

    ValuePrivate(const ValuePrivate &other)
        : QSharedData(other),
          m_number(other.m_number),
          m_unit(other.m_unit)
    {
    }

    virtual ~ValuePrivate()
    {
    }

    ValuePrivate &operator=(const ValuePrivate &other)
    {
        m_number = other.m_number;
        m_unit = other.m_unit;
        return *this;
    }

    ValuePrivate *clone()
    {
        return new ValuePrivate(*this);
    }

    bool operator==(const ValuePrivate &other) const
    {
        return (m_number == other.m_number && m_unit == other.m_unit);
    }

    bool operator!=(const ValuePrivate &other) const
    {
        return !(*this == other);
    }

    qreal m_number;
    Unit m_unit;
    Converter m_converter;
};

Value::Value()
    : d(0)
{
}

Value::Value(const Value &other)
    : d(other.d)
{
}

Value::Value(qreal number, const Unit &unit)
    : d(new ValuePrivate(number, unit))
{
}

Value::Value(qreal number, const QString &unitString)
    : d(new ValuePrivate(number, unitString))
{
}

Value::Value(qreal number, UnitId unitId)
    : d(new ValuePrivate(number, unitId))
{
}

Value::Value(const QVariant &number, const QString &unitString)
    : d(new ValuePrivate(number.toReal(), unitString))
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
    return !d;
}

bool Value::isValid() const
{
    return (d && d->m_unit.isValid());
}

qreal Value::number() const
{
    if (d)
        return d->m_number;
    return 0;
}

Unit Value::unit() const
{
    if (d)
        return d->m_unit;
    return Unit();
}

QString Value::toString(int fieldWidth, char format, int precision, const QChar &fillChar) const
{
    if (isValid())
        return d->m_unit.toString(d->m_number, fieldWidth, format, precision, fillChar);
    return QString();
}

QString Value::toSymbolString(int fieldWidth, char format, int precision,
                              const QChar &fillChar) const
{
    if (isValid())
        return d->m_unit.toSymbolString(d->m_number, fieldWidth, format, precision, fillChar);
    return QString();
}

Value &Value::round(uint decimals)
{
    if (!isValid())
        return *this;

    uint div = qPow(10, decimals);
    qreal add = 0.5 / (qreal)div;

    d->m_number = (int)((d->m_number + add) * div) / (qreal)div;
    return *this;
}

Value Value::convertTo(const Unit &unit) const
{
    if (d)
        return d->m_converter.convert(*this, unit);
    return Value();
}

Value Value::convertTo(UnitId unitId) const
{
    if (d)
        return d->m_converter.convert(*this, unitId);
    return Value();
}

Value Value::convertTo(const QString &unitString) const
{
    if (d)
        return d->m_converter.convert(*this, unitString);
    return Value();
}

}
