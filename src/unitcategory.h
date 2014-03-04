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

#ifndef KUNITCONVERSION_UNITCATEGORY_H
#define KUNITCONVERSION_UNITCATEGORY_H

#include "value.h"
#include "unit.h"
#include "kunitconversion/kunitconversion_export.h"

#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QString>
#include <QtCore/QStringList>

namespace KUnitConversion
{

class UnitCategoryPrivate;

class KUNITCONVERSION_EXPORT UnitCategory
{
public:
    /**
     * Null constructor
     **/
    UnitCategory();

    /**
     * Copy constructor, copy @param other to this.
     **/
    UnitCategory(const UnitCategory &other);

    virtual ~UnitCategory();

    /**
     * Assignment operator, assign @param other to this.
     **/
    UnitCategory &operator=(const UnitCategory &other);

#ifdef Q_COMPILER_RVALUE_REFS
    /**
     * Move-assigns \a other to this UnitCategory instance, transferring the
     * ownership of the managed pointer to this instance.
     **/
    UnitCategory &operator=(UnitCategory &&other) { swap(other); return *this; }
#endif

    /**
     * Swaps this UnitCategory with \a other. This function is very fast and never fails.
     **/
    void swap(UnitCategory &other) { d.swap(other.d); }

    /**
     * @return Returns true if this UnitCategory is equal to the @param other UnitCategory.
     **/
    bool operator==(const UnitCategory &other) const;

    /**
     * @return Returns true if this UnitCategory is not equal to the @param other UnitCategory.
     **/
    bool operator!=(const UnitCategory &other) const;

    /**
     * @return returns true if this UnitCategory is null
     **/
    bool isNull() const;

    /**
     * @return category id.
     **/
    CategoryId id() const;

    /**
     * Returns name for the unit category.
     *
     * @return Translated name for category.
     **/
    QString name() const;

    /**
     * @return unit category description
     **/
    QString description() const;

    /**
     * Returns default unit.
     *
     * @return default unit.
     **/
    Unit defaultUnit() const;

    /**
     * Check if unit category has a unit.
     *
     * @return True if unit is found
     **/
    bool hasUnit(const QString &unit) const;

    /**
     * Return unit for string.
     *
     * @return Pointer to unit class.
     **/
    Unit unit(const QString &s) const;

    /**
    * Return unit for unit enum.
    *
    * @return Pointer to unit class.
    **/
    Unit unit(UnitId unitId) const;

    /**
     * Return units in this category.
     *
     * @return list of units.
     **/
    QList<Unit> units() const;

    /**
     * Return most common units in this category.
     *
     * @return list of units.
     **/
    QList<Unit> mostCommonUnits() const;

    /**
     * Return all unit names, short names and unit synonyms in this category.
     *
     * @return list of units.
     **/
    QStringList allUnits() const;

    /**
     * Convert value to another unit.
     *
     * @param value value to convert
     * @param toUnit unit to convert to. If empty default unit is used.
     * @return converted value
     **/
    Value convert(const Value &value, const QString &toUnit = QString());
    Value convert(const Value &value, UnitId toUnit);
    virtual Value convert(const Value &value, const Unit &toUnit);

protected:
    void addDefaultUnit(const Unit &unit);
    void addCommonUnit(const Unit &unit);
    void addUnit(const Unit &unit);

private:
    friend class CustomCategory;
    friend class Unit;

    UnitCategory(UnitCategoryPrivate *dd);

    QExplicitlySharedDataPointer<UnitCategoryPrivate> d;
};

} // KUnitConversion namespace

#endif
