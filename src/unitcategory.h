/*
 *   SPDX-FileCopyrightText: 2007-2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef KUNITCONVERSION_UNITCATEGORY_H
#define KUNITCONVERSION_UNITCATEGORY_H

#include "kunitconversion/kunitconversion_export.h"
#include "unit.h"
#include "value.h"
#include <QExplicitlySharedDataPointer>
#include <QString>
#include <QStringList>
#include <chrono>

namespace KUnitConversion
{
class UnitCategoryPrivate;

/**
 * @short Class to define a category of units of measurement
 *
 * This is a class to define a category of units of measurement.
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

    // TODO KF6: remove virtual
    virtual ~UnitCategory();

    /**
     * Assignment operator, assign @p other to this.
     **/
    UnitCategory &operator=(const UnitCategory &other);

    // TODO KF6: de-inline
#ifdef Q_COMPILER_RVALUE_REFS
    /**
     * Move-assigns @p other to this UnitCategory instance, transferring the
     * ownership of the managed pointer to this instance.
     **/
    UnitCategory &operator=(UnitCategory &&other)
    {
        swap(other);
        return *this;
    }
#endif

    // TODO KF6: remove
    /**
     * Swaps this UnitCategory with @p other. This function is very fast and never fails.
     **/
    void swap(UnitCategory &other)
    {
        d.swap(other.d);
    }

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

    // TODO KF6: make const
    /**
     * Convert value to another unit selected by string.
     *
     * @param value value to convert
     * @param toUnit unit to convert to. If empty default unit is used.
     * @return converted value
     **/
    Value convert(const Value &value, const QString &toUnit = QString());

    // TODO KF6: make const
    /**
     * Convert value to another unit selected by enum.
     *
     * @param value value to convert
     * @param toUnit unit to convert to.
     * @return converted value
     **/
    Value convert(const Value &value, UnitId toUnit);

    // TODO KF6: make const, remove virtual
    /**
     * Convert value to another unit.
     *
     * @param value value to convert
     * @param toUnit unit to be used for conversion
     * @return converted value
     **/
    virtual Value convert(const Value &value, const Unit &toUnit);

    /**
     * @return true if category has conversion table that needs to be updated via online access, otherwise false
     */
    bool hasOnlineConversionTable() const;

    /**
     * Explicit request to sync conversion table when it is older than @p updateSkipPeriod.
     *
     * This method is supposed to be called at a convenient time at application startup. Yet it is
     * safe to already do unit conversions that require an up-to-date conversion table (like currency).
     * Those conversions yet block internally until the table is up-to-date.
     */
    void syncConversionTable(std::chrono::seconds updateSkipPeriod);

protected:
    // TODO KF6: remove those three
    void addDefaultUnit(const Unit &unit);
    void addCommonUnit(const Unit &unit);
    void addUnit(const Unit &unit);

private:
    friend class Unit;
    friend class UnitCategoryPrivate;

    KUNITCONVERSION_NO_EXPORT explicit UnitCategory(UnitCategoryPrivate *dd);

protected:
    QExplicitlySharedDataPointer<UnitCategoryPrivate> d;
};

} // KUnitConversion namespace

#endif
