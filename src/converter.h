/*
 *   Copyright (C) 2008-2009 Petri Damstén <damu@iki.fi>
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

#ifndef KUNITCONVERSION_CONVERTER_H
#define KUNITCONVERSION_CONVERTER_H

#include <kunitconversion/kunitconversion_export.h>

#include "unitcategory.h"

#include <QtCore/QExplicitlySharedDataPointer>
#include <QtCore/QVariant>

namespace KUnitConversion
{

class Value;
class UnitCategory;
class ConverterPrivate;

class KUNITCONVERSION_EXPORT Converter
{
public:
    Converter();
    ~Converter();

    /**
     * Assignment operator, assign @param other to this.
     **/
    Converter &operator=(const Converter &other);

#ifdef Q_COMPILER_RVALUE_REFS
    /**
     * Move-assigns \a other to this Converter instance, transferring the
     * ownership of the managed pointer to this instance.
     **/
    Converter &operator=(Converter &&other) { swap(other); return *this; }
#endif

    /**
     * Swaps this Converter with \a other. This function is very fast and never fails.
     **/
    void swap(Converter &other) { d.swap(other.d); }

    /**
     * @return Returns true if this Converter is equal to the @param other Converter.
     **/
    bool operator==(const Converter &other) const;

    /**
     * @return Returns true if this Converter is not equal to the @param other Converter.
     **/
    bool operator!=(const Converter &other) const;

    /**
     * Convert value to another unit.
     *
     * @param value value to convert
     * @param toUnit unit to convert to. If empty default unit is used.
     * @return converted value
     **/
    Value convert(const Value &value, const QString &toUnit = QString()) const;
    Value convert(const Value &value, UnitId toUnit) const;
    Value convert(const Value &value, const Unit &toUnit) const;

    /**
     * Find unit category for unit.
     *
     * @param unit unit to find category for.
     * @return unit category for unit
     **/
    UnitCategory categoryForUnit(const QString &unit) const;

    /**
     * Find unit for string unit.
     *
     * @param unitString unit string to find unit for.
     * @return unit for string unit
     **/
    Unit unit(const QString &unitString) const;

    /**
    * Find unit for unit enum.
    *
    * @param unit unit enum to find unit for.
    * @return unit for string unit
    **/
    Unit unit(UnitId unitId) const;

    /**
     * Find unit category.
     *
     * @param category name of the category to find (length, area, mass, etc.).
     * @return unit category named category or invalid category.
     **/
    UnitCategory category(const QString &category) const;

    /**
     * Find unit category.
     *
     * @param categoryId id of the category to find (LengthCategory, AreaCategory, etc.).
     * @return unit category which id is categoryId or invalid category.
     **/
    UnitCategory category(CategoryId categoryId) const;

    /**
     * Returns a list of all unit categories.
     *
     * @return list of unit categories.
     **/
    QList<UnitCategory> categories() const;

private:
    QExplicitlySharedDataPointer<ConverterPrivate> d;
};

} // KUnitConversion namespace

#endif
