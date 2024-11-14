/*
 *   SPDX-FileCopyrightText: 2007-2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef KUNITCONVERSION_VALUE_H
#define KUNITCONVERSION_VALUE_H

#include "kunitconversion/kunitconversion_export.h"

#include "unit.h"

#include <QSharedDataPointer>
#include <QString>

class QVariant;

namespace KUnitConversion
{
class ValuePrivate;

/*!
 * \class KUnitConversion::Value
 * \inmodule KUnitConversion
 *
 * \brief Class to hold a value in a unit of measurement.
 *
 * This is a class to hold a value in a unit of measurement.
 *
 * \sa Converter, Unit, UnitCategory
 */

class KUNITCONVERSION_EXPORT Value
{
public:
    /*!
     * Creates a null value.
     */
    Value();
    /*!
     * Creates a value with a unit instance
     */
    Value(qreal number, const Unit &unit);
    /*!
     * Creates a value with a unit (as a string).
     */
    Value(qreal number, const QString &unitString);
    /*!
     * Creates a value with a unit (as a enum value).
     */
    Value(qreal number, UnitId unitId);
    /*!
     * Creates a value based on a QVariant (calling toReal() on it) with a unit (as a string).
     */
    Value(const QVariant &number, const QString &unitString);

    Value(const Value &other);

    ~Value();

    Value &operator=(const Value &other);

#ifdef Q_COMPILER_RVALUE_REFS
    Value &operator=(Value &&other)
    {
        swap(other);
        return *this;
    }
#endif

    void swap(Value &other)
    {
        d.swap(other.d);
    }

    /*!
     * Returns true if this Value is equal to the \a other Value.
     **/
    bool operator==(const Value &other) const;

    bool operator!=(const Value &other) const;

    /*!
     * Returns returns true if this Value is null
     **/
    bool isNull() const;

    /*!
     * Returns true if value is valid
     **/
    bool isValid() const;

    /*!
     * Number part of the value
     **/
    qreal number() const;

    /*!
     * Unit part of the value
     **/
    Unit unit() const;

    /*!
     * Convert value to a string
     *
     * \a fieldWidth width of the formatted field, padded by spaces.
     *                   Positive value aligns right, negative aligns left
     *
     * \a format type of floating point formatting, like in \l QString::arg
     *
     * \a precision number of digits after the decimal separator
     *
     * \a fillChar the character used to fill up the empty places when
     *                 field width is greater than argument width
     *
     * Returns value as a string
     **/
    QString toString(int fieldWidth = 0, char format = 'g', int precision = -1, const QChar &fillChar = QLatin1Char(' ')) const;

    /*!
     * Convert value to a string with symbol
     *
     * \a fieldWidth width of the formatted field, padded by spaces.
     *                   Positive value aligns right, negative aligns left
     * \a format type of floating point formatting, like in \l QString::arg
     *
     * \a precision number of digits after the decimal separator
     *
     * \a fillChar the character used to fill up the empty places when
     *                 field width is greater than argument width
     *
     * Returns value as a string
     **/
    QString toSymbolString(int fieldWidth = 0, char format = 'g', int precision = -1, const QChar &fillChar = QLatin1Char(' ')) const;

    /*!
     * Rounds value to decimal count
     *
     * \a decimals decimal count.
     **/
    Value &round(uint decimals);

    /*!
     * Convert to another unit
     **/
    Value convertTo(const Unit &unit) const;

    /*!
     * Convert to another unit
     **/
    Value convertTo(UnitId unit) const;

    /*!
     * Convert to another unit
     **/
    Value convertTo(const QString &unit) const;

private:
    QSharedDataPointer<ValuePrivate> d;
};

} // KUnitConversion namespace

#endif
