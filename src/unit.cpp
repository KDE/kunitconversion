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
        : m_id(InvalidUnit),
          m_multiplier(0),
          m_complex(0)
    {
    };

    UnitPrivate(const UnitCategory &category, const Complex *complex = 0)
        : m_multiplier(1.0),
          m_category(category),
          m_complex(complex)
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
        return (m_id == other.m_id && m_symbol == other.m_symbol);
    }

    bool operator!=(const UnitPrivate &other) const
    {
        return !(*this == other);
    }

    UnitId m_id;
    QString m_symbol;
    QString m_description;
    double m_multiplier;
    KLocalizedString m_realString;
    KLocalizedString m_integerString;
    UnitCategory m_category;
    const Complex *m_complex;
};

Unit::Unit()
    : d(0)
{
}

Unit::Unit(const UnitCategory &category, UnitId id, double multiplier, const QString &symbol,
           const QString &description, const QString &match,
           const KLocalizedString &realString, const KLocalizedString &integerString)
    : d(new UnitPrivate(category))
{
    d->m_id = id;
    d->m_symbol = symbol;
    d->m_description = description;
    d->m_multiplier = multiplier;
    d->m_realString = realString;
    d->m_integerString = integerString;
    d->m_category.addUnitMapValues(*this, match);
    d->m_category.addIdMapValue(*this, id);
}

Unit::Unit(const UnitCategory &category, UnitId id, const Complex *complex, const QString &symbol,
           const QString &description, const QString &match,
           const KLocalizedString &realString, const KLocalizedString &integerString)
    : d(new UnitPrivate(category, complex))
{
    d->m_id = id;
    d->m_symbol = symbol;
    d->m_description = description;
    d->m_realString = realString;
    d->m_integerString = integerString;
    d->m_category.addUnitMapValues(*this, match);
    d->m_category.addIdMapValue(*this, id);
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

bool Unit::isValid() const
{
    return (d && !d->m_symbol.isEmpty());
}

UnitId Unit::id() const
{
    if (d)
        return d->m_id;
    return InvalidUnit;
}

UnitCategory Unit::category() const
{
    if (d)
        return d->m_category;
    return UnitCategory();
}

QString Unit::description() const
{
    if (d)
        return d->m_description;
    return QString();
}

QString Unit::symbol() const
{
    if (d)
        return d->m_symbol;
    return QString();
}

void Unit::setUnitMultiplier(double multiplier)
{
    if (d)
        d->m_multiplier = multiplier;
}

double Unit::toDefault(double value) const
{
    if (isNull())
        return 0;
    if (d->m_complex) {
        return d->m_complex->toDefault(value);
    } else {
        return value * d->m_multiplier;
    }
}

double Unit::fromDefault(double value) const
{
    if (isNull())
        return 0;
    if (d->m_complex) {
        return d->m_complex->fromDefault(value);
    } else {
        return value / d->m_multiplier;
    }
}

QString Unit::toString(double value, int fieldWidth, char format, int precision,
                       const QChar &fillChar) const
{
    if (isNull())
        return QString();
    if ((int)value == value && precision < 1) {
        return d->m_integerString.subs((int)value).toString();
    }
    return d->m_realString.subs(value, fieldWidth, format, precision, fillChar).toString();
}

QString Unit::toSymbolString(double value, int fieldWidth, char format, int precision,
                             const QChar &fillChar) const
{
    if (isNull())
        return QString();
    return category().symbolStringFormat().subs(value, fieldWidth, format, precision, fillChar)
                                          .subs(d->m_symbol)
                                          .toString();
}

}

