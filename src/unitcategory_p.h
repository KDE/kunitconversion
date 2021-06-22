/*
 *   SPDX-FileCopyrightText: 2007-2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
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
    CustomCategory(UnitCategoryPrivate *dd)
        : UnitCategory(dd)
    {
    }

    CustomCategory(CategoryId id, const QString &name, const QString &description)
        : UnitCategory(new UnitCategoryPrivate(id, name, description))
    {
    }

    virtual ~CustomCategory()
    {
    }
};

} // KUnitConversion namespace

#endif // KUNITCONVERSION_UNITCATEGORY_P_H
