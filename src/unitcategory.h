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
#include <QObject>
#include <QString>
#include <QStringList>

#include <chrono>

class QNetworkReply;

namespace KUnitConversion
{
class UnitCategoryPrivate;
class UpdateJob;

/*!
 * \class KUnitConversion::UnitCategory
 * \inmodule KUnitConversion
 *
 * \brief Class to define a category of units of measurement.
 *
 * This is a class to define a category of units of measurement.
 *
 * \sa Converter, Unit, Value
 */
class KUNITCONVERSION_EXPORT UnitCategory
{
public:
    /*!
     * Null constructor
     **/
    UnitCategory();

    UnitCategory(const UnitCategory &other);

    ~UnitCategory();

    UnitCategory &operator=(const UnitCategory &other);

    UnitCategory &operator=(UnitCategory &&other);

    /*!
     * Returns true if this UnitCategory is equal to the \a other UnitCategory.
     **/
    bool operator==(const UnitCategory &other) const;

    bool operator!=(const UnitCategory &other) const;

    /*!
     * Returns true if this UnitCategory is null
     **/
    bool isNull() const;

    /*!
     * Returns category id.
     **/
    CategoryId id() const;

    /*!
     * Returns translated name for the unit category.
     **/
    QString name() const;

    /*!
     * Returns unit category description
     **/
    QString description() const;

    /*!
     * Returns default unit.
     **/
    Unit defaultUnit() const;

    /*!
     * Returns if unit category has a unit.
     **/
    bool hasUnit(const QString &unit) const;

    /*!
     * Returns unit for string.
     **/
    Unit unit(const QString &s) const;

    /*!
     * Returns unit for unit enum.
     **/
    Unit unit(UnitId unitId) const;

    /*!
     * Returns units in this category.
     **/
    QList<Unit> units() const;

    /*!
     * Returns most common units in this category.
     **/
    QList<Unit> mostCommonUnits() const;

    /*!
     * Returns all unit names, short names and unit synonyms in this category.
     **/
    QStringList allUnits() const;

    /*!
     * Convert value to another unit selected by string.
     *
     * \a value value to convert
     *
     * \a toUnit unit to convert to. If empty default unit is used.
     *
     * Returns converted value
     **/
    Value convert(const Value &value, const QString &toUnit = QString()) const;

    /*!
     * \overload UnitCategory::convert()
     *
     * Convert value to another unit selected by enum.
     *
     * \a value value to convert
     *
     * \a toUnit unit to convert to.
     *
     * Returns converted value
     **/
    Value convert(const Value &value, UnitId toUnit) const;

    /*!
     * \overload UnitCategory::convert()
     *
     * Convert value to another unit.
     *
     * \a value value to convert
     *
     * \a toUnit unit to be used for conversion
     *
     * Returns converted value
     **/
    Value convert(const Value &value, const Unit &toUnit) const;

    /*!
     * Returns true if category has conversion table that needs to be updated via online access, otherwise false
     * \sa syncConversionTable()
     */
    bool hasOnlineConversionTable() const;

    /*!
     * Request an update of the online conversion table when it is older than \a updateSkipPeriod.
     *
     * Returned jobs are automatically deleted, ie. it is safe to ignore the return value if you
     * do not care about being notified about the completion (or failure) of the update process.
     * Calling this method while another update is already in progress will not trigger another update
     * but instead allows you to watch the already ongoing update.
     *
     * Performing conversions before the update has completed will return results based on the old
     * conversion table, if available.
     *
     * \note This method must be called from the main thread!
     *
     * Returns an UpdateJob if an update is necessary or already running, nullptr otherwise.
     *
     * \sa UpdateJob
     * \since 6.0
     */
    UpdateJob *syncConversionTable(std::chrono::seconds updateSkipPeriod = std::chrono::hours(24));

private:
    friend class Unit;
    friend class UnitCategoryPrivate;

    KUNITCONVERSION_NO_EXPORT explicit UnitCategory(UnitCategoryPrivate *dd);

protected:
    QExplicitlySharedDataPointer<UnitCategoryPrivate> d;
};

/*!
 * \class KUnitConversion::UpdateJob
 * \inmodule KUnitConversion
 * \inheaderfile KUnitConversion/UnitCategory
 *
 * \brief Dynamic conversion data update job.
 *
 * Created via the factory methods in KUnitConversion::Updater, useful for
 * getting notified about an update having completed.
 * Update jobs are automatically deleted on completion, but it is also save to delete
 * instances manually.
 *
 * \sa UnitCategory
 * \since 6.0
 */
class KUNITCONVERSION_EXPORT UpdateJob : public QObject
{
    Q_OBJECT
public:
    ~UpdateJob();

Q_SIGNALS:
    /*! */
    void finished();

private:
    friend class UnitCategoryPrivate;
    explicit UpdateJob(QNetworkReply *dd);
    QNetworkReply *d;
};

} // KUnitConversion namespace

Q_DECLARE_TYPEINFO(KUnitConversion::UnitCategory, Q_RELOCATABLE_TYPE);

#endif
