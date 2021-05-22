/*
 *   SPDX-FileCopyrightText: 2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef CURRENCY_P_H
#define CURRENCY_P_H

#include "unitcategory_p.h"
#include <QDateTime>

namespace KUnitConversion
{
class KUNITCONVERSION_EXPORT Currency : public CustomCategory
{
public:
    Currency();
    /**
     * @brief Provides time of last conversion table update for usage in tests
     *
     * If no conversion table is available the QDateTime object is a null datetime.
     */
    static QDateTime lastConversionTableUpdate();
};

}

#endif
