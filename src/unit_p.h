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

#ifndef KUNITCONVERSION_UNIT_P_H
#define KUNITCONVERSION_UNIT_P_H

#include "unit.h"
#include "unitcategory.h"

#include <KI18n/KLocalizedString>

namespace KUnitConversion
{

class UnitPrivate : public QSharedData
{
public:
    UnitPrivate();

    UnitPrivate(CategoryId categoryId, UnitId id, qreal multiplier,
                const QString &symbol, const QString &description,
                const QString &matchString, const KLocalizedString &symbolString,
                const KLocalizedString &realString, const KLocalizedString &integerString);

    virtual ~UnitPrivate();

    UnitPrivate *clone();
    bool operator==(const UnitPrivate &other) const;
    bool operator!=(const UnitPrivate &other) const;

    void setUnitMultiplier(qreal multiplier);
    qreal unitMultiplier() const;

    virtual qreal toDefault(qreal value) const;
    virtual qreal fromDefault(qreal value) const;

    CategoryId m_categoryId;
    UnitId m_id;
    qreal m_multiplier;
    QString m_symbol;
    QString m_description;
    QString m_matchString;
    KLocalizedString m_symbolString;
    KLocalizedString m_realString;
    KLocalizedString m_integerString;
    UnitCategory m_category;
};

class CustomUnit : public Unit
{
public:
    CustomUnit(UnitPrivate *dd) : Unit(dd)
    {};

    CustomUnit(CategoryId categoryId, UnitId id, qreal multiplier,
                     const QString &symbol, const QString &description,
                     const QString &matchString, const KLocalizedString &symbolString,
                     const KLocalizedString &realString, const KLocalizedString &integerString)
        : Unit(new UnitPrivate(categoryId, id, multiplier,
                               symbol, description,
                               matchString, symbolString,
                               realString, integerString))
    {};

    virtual ~CustomUnit()
    {};
};

} // KUnitConversion namespace

#endif // KUNITCONVERSION_UNIT_P_H
