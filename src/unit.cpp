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

#include "unit.h"
#include "unit_p.h"
#include "unitcategory.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{

UnitPrivate::UnitPrivate()
    : m_categoryId(InvalidCategory),
      m_id(InvalidUnit),
      m_multiplier(1.0)
{
}

UnitPrivate::UnitPrivate(CategoryId categoryId, UnitId id, qreal multiplier,
                         const QString &symbol, const QString &description,
                         const QString &matchString, const KLocalizedString &symbolString,
                         const KLocalizedString &realString, const KLocalizedString &integerString)
    : m_categoryId(categoryId),
      m_id(id),
      m_multiplier(multiplier),
      m_symbol(symbol),
      m_description(description),
      m_matchString(matchString),
      m_symbolString(symbolString),
      m_realString(realString),
      m_integerString(integerString)
{
}

UnitPrivate::~UnitPrivate()
{
}

UnitPrivate *UnitPrivate::clone()
{
    return new UnitPrivate(*this);
}

bool UnitPrivate::operator==(const UnitPrivate &other) const
{
    return (m_id == other.m_id && m_symbol == other.m_symbol);
}

bool UnitPrivate::operator!=(const UnitPrivate &other) const
{
    return !(*this == other);
}

void UnitPrivate::setUnitMultiplier(qreal multiplier)
{
    m_multiplier = multiplier;
}

qreal UnitPrivate::unitMultiplier() const
{
    return m_multiplier;
}

qreal UnitPrivate::toDefault(qreal value) const
{
    return value * m_multiplier;
}

qreal UnitPrivate::fromDefault(qreal value) const
{
    return value / m_multiplier;
}

Unit::Unit()
    : d(0)
{
}

Unit::Unit(UnitPrivate *dd)
    : d(dd)
{
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
    return d;
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

CategoryId Unit::categoryId() const
{
    if (d)
        return d->m_categoryId;
    return InvalidCategory;
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

void Unit::setUnitMultiplier(qreal multiplier)
{
    if (d)
        setUnitMultiplier(multiplier);
}

qreal Unit::toDefault(qreal value) const
{
    if (d)
        return d->toDefault(value);
    return 0;
}

qreal Unit::fromDefault(qreal value) const
{
    if (d)
        return d->fromDefault(value);
    return 0;
}

QString Unit::toString(qreal value, int fieldWidth, char format, int precision,
                       const QChar &fillChar) const
{
    if (isNull())
        return QString();
    if ((int)value == value && precision < 1) {
        return d->m_integerString.subs((int)value).toString();
    }
    return d->m_realString.subs(value, fieldWidth, format, precision, fillChar).toString();
}

QString Unit::toSymbolString(qreal value, int fieldWidth, char format, int precision,
                             const QChar &fillChar) const
{
    if (d)
        return d->m_symbolString.subs(value, fieldWidth, format, precision, fillChar).subs(d->m_symbol).toString();
    return QString();
}

}

