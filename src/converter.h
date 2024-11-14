/*
 *   SPDX-FileCopyrightText: 2008-2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef KUNITCONVERSION_CONVERTER_H
#define KUNITCONVERSION_CONVERTER_H

#include <kunitconversion/kunitconversion_export.h>

#include "unitcategory.h"

#include <QExplicitlySharedDataPointer>

namespace KUnitConversion
{
class Value;
class UnitCategory;
class ConverterPrivate;

/*!
 * \class KUnitConversion::Converter
 * \inmodule KUnitConversion
 *
 * \brief Class for converting values between units of measurement.
 *
 * This is a class to convert values between different units of measurement.
 *
 * \sa Unit, UnitCategory, Value
 */
class KUNITCONVERSION_EXPORT Converter
{
public:
    /*!
     * Creates a Converter instance.
     */
    Converter();

    ~Converter();

    Converter(const Converter &other);

    Converter &operator=(const Converter &other);

    Converter &operator=(Converter &&other);

    /*!
     * Convert value to another unit.
     *
     * \a value value to convert
     *
     * \a toUnit unit to convert to. If empty default unit is used.
     *
     * Returns converted value
     **/
    Value convert(const Value &value, const QString &toUnit = QString()) const;

    /*!
     * \overload Converter::convert()
     */
    Value convert(const Value &value, UnitId toUnit) const;

    /*!
     * \overload Converter::convert()
     */
    Value convert(const Value &value, const Unit &toUnit) const;

    /*!
     * Find unit category for unit.
     *
     * \a unit unit to find category for.
     *
     * Returns unit category for unit
     **/
    UnitCategory categoryForUnit(const QString &unit) const;

    /*!
     * Find unit for string unit.
     *
     * \a unitString unit string to find unit for.
     *
     * Returns unit for string unit
     **/
    Unit unit(const QString &unitString) const;

    /*!
     * Find unit for unit enum.
     *
     * \a unitId unit enum to find unit for.
     *
     * Returns unit for string unit
     **/
    Unit unit(UnitId unitId) const;

    /*!
     * Find unit category.
     *
     * \a category name of the category to find (length, area, mass, etc.).
     *
     * Returns unit category named category or invalid category.
     **/
    UnitCategory category(const QString &category) const;

    /*!
     * Find unit category.
     *
     * \a categoryId id of the category to find (LengthCategory, AreaCategory, etc.).
     *
     * Returns unit category which id is categoryId or invalid category.
     **/
    UnitCategory category(CategoryId categoryId) const;

    /*!
     * Returns a list of all unit categories.
     **/
    QList<UnitCategory> categories() const;

private:
    QExplicitlySharedDataPointer<ConverterPrivate> d;
};

} // KUnitConversion namespace

#endif
