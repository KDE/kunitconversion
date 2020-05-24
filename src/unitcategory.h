/*
 *   SPDX-FileCopyrightText: 2007-2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef KUNITCONVERSION_UNITCATEGORY_H
#define KUNITCONVERSION_UNITCATEGORY_H

#include "kunitconversion/kunitconversion_export.h"

#include "value.h"
#include "unit.h"

#include <QExplicitlySharedDataPointer>
#include <QString>
#include <QStringList>

namespace KUnitConversion
{

class UnitCategoryPrivate;

/**
 * @short Class to define a category of units of measurement
 *
 * @since 4.4
 *
 * This is a class to define a category of units of measurement.
 *
 * @b license GNU-LGPL v.2 or later
 *
 * @see Converter, Unit, Value
 *
 * @author Petri Damstén <damu@iki.fi>
 * @author John Layt <jlayt@kde.org>
 */

class KUNITCONVERSION_EXPORT UnitCategory
{
public:
    /**
     * Null constructor
     **/
    UnitCategory();

    /**
     * Copy constructor, copy @p other to this.
     **/
    UnitCategory(const UnitCategory &other);

    virtual ~UnitCategory();

    /**
     * Assignment operator, assign @p other to this.
     **/
    UnitCategory &operator=(const UnitCategory &other);

#ifdef Q_COMPILER_RVALUE_REFS
    /**
     * Move-assigns @p other to this UnitCategory instance, transferring the
     * ownership of the managed pointer to this instance.
     **/
    UnitCategory &operator=(UnitCategory &&other) { swap(other); return *this; }
#endif

    /**
     * Swaps this UnitCategory with @p other. This function is very fast and never fails.
     **/
    void swap(UnitCategory &other) { d.swap(other.d); }

    /**
     * @return @c true if this UnitCategory is equal to the @p other UnitCategory.
     **/
    bool operator==(const UnitCategory &other) const;

    /**
     * @return @c true if this UnitCategory is not equal to the @p other UnitCategory.
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
