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

#ifndef KUNITCONVERSION_UNITCATEGORY_P_H
#define KUNITCONVERSION_UNITCATEGORY_P_H

#include "unitcategory.h"

#include <KI18n/KLocalizedString>

#include <QMap>

namespace KUnitConversion
{

class UnitCategoryPrivate : public QSharedData
{
public:
    UnitCategoryPrivate();
    UnitCategoryPrivate(CategoryId id, const QString &name, const QString &description);
    virtual ~UnitCategoryPrivate();

    UnitCategoryPrivate *clone();
    bool operator==(const UnitCategoryPrivate &other) const;
    bool operator!=(const UnitCategoryPrivate &other) const;

    virtual Value convert(const Value &value, const Unit &toUnit);

    CategoryId m_id;
    QString m_name;
    QString m_description;
    KLocalizedString m_symbolStringFormat;
    Unit m_defaultUnit;
    QMap<QString, Unit> m_unitMap;
    QMap<UnitId, Unit> m_idMap;
    QList<Unit> m_units;
    QList<Unit> m_mostCommonUnits;
};

class CustomCategory : public UnitCategory
{
public:
    CustomCategory(UnitCategoryPrivate *dd) : UnitCategory(dd)
    {}

    CustomCategory(CategoryId id, const QString &name, const QString &description)
        : UnitCategory(new UnitCategoryPrivate(id, name, description))
    {}

    virtual ~CustomCategory()
    {}
};

} // KUnitConversion namespace

#endif // KUNITCONVERSION_UNITCATEGORY_P_H
