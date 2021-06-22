/*
 *   SPDX-FileCopyrightText: 2010 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *   SPDX-FileCopyrightText: 2014 Garret Wassermann <gwasser@gmail.com>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "electrical_current_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{
ElectricalCurrent::ElectricalCurrent()
    : CustomCategory(ElectricalCurrentCategory, i18n("ElectricalCurrent"), i18n("ElectricalCurrent"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (electrical current", "%1 %2");

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Yottaampere,
                       1e+24,
                       i18nc("electrical current unit symbol", "YA"),
                       i18nc("unit description in lists", "yottaamperes"),
                       i18nc("unit synonyms for matching user input", "yottaampere;yottaamperes;YA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yottaamperes"),
                       ki18ncp("amount in units (integer)", "%1 yottaampere", "%1 yottaamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Zettaampere,
                       1e+21,
                       i18nc("electrical current unit symbol", "ZA"),
                       i18nc("unit description in lists", "zettaamperes"),
                       i18nc("unit synonyms for matching user input", "zettaampere;zettaamperes;ZA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zettaamperes"),
                       ki18ncp("amount in units (integer)", "%1 zettaampere", "%1 zettaamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Exaampere,
                       1e+18,
                       i18nc("electrical current unit symbol", "EA"),
                       i18nc("unit description in lists", "exaamperes"),
                       i18nc("unit synonyms for matching user input", "exaampere;exaamperes;EA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 exaamperes"),
                       ki18ncp("amount in units (integer)", "%1 exaampere", "%1 exaamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Petaampere,
                       1e+15,
                       i18nc("electrical current unit symbol", "PA"),
                       i18nc("unit description in lists", "petaamperes"),
                       i18nc("unit synonyms for matching user input", "petaampere;petaamperes;PA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 petaamperes"),
                       ki18ncp("amount in units (integer)", "%1 petaampere", "%1 petaamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Teraampere,
                       1e+12,
                       i18nc("electrical current unit symbol", "TA"),
                       i18nc("unit description in lists", "teraamperes"),
                       i18nc("unit synonyms for matching user input", "teraampere;teraamperes;TA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 teraamperes"),
                       ki18ncp("amount in units (integer)", "%1 teraampere", "%1 teraamperes")));

    addCommonUnit(CustomUnit(ElectricalCurrentCategory,
                             Gigaampere,
                             1e+09,
                             i18nc("electrical current unit symbol", "GA"),
                             i18nc("unit description in lists", "gigaamperes"),
                             i18nc("unit synonyms for matching user input", "gigaampere;gigaamperes;GA"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 gigaamperes"),
                             ki18ncp("amount in units (integer)", "%1 gigaampere", "%1 gigaamperes")));

    addCommonUnit(CustomUnit(ElectricalCurrentCategory,
                             Megaampere,
                             1e+06,
                             i18nc("electrical current unit symbol", "MA"),
                             i18nc("unit description in lists", "megaamperes"),
                             i18nc("unit synonyms for matching user input", "megaampere;megaamperes;MA"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 megaamperes"),
                             ki18ncp("amount in units (integer)", "%1 megaampere", "%1 megaamperes")));

    addCommonUnit(CustomUnit(ElectricalCurrentCategory,
                             Kiloampere,
                             1000,
                             i18nc("electrical current unit symbol", "kA"),
                             i18nc("unit description in lists", "kiloamperes"),
                             i18nc("unit synonyms for matching user input", "kiloampere;kiloamperes;kA"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kiloamperes"),
                             ki18ncp("amount in units (integer)", "%1 kiloampere", "%1 kiloamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Hectoampere,
                       100,
                       i18nc("electrical current unit symbol", "hA"),
                       i18nc("unit description in lists", "hectoamperes"),
                       i18nc("unit synonyms for matching user input", "hectoampere;hectoamperes;hA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 hectoamperes"),
                       ki18ncp("amount in units (integer)", "%1 hectoampere", "%1 hectoamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Decaampere,
                       10,
                       i18nc("electrical current unit symbol", "daA"),
                       i18nc("unit description in lists", "decaamperes"),
                       i18nc("unit synonyms for matching user input", "decaampere;decaamperes;daA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 decaamperes"),
                       ki18ncp("amount in units (integer)", "%1 decaampere", "%1 decaamperes")));

    addDefaultUnit(CustomUnit(ElectricalCurrentCategory,
                              Ampere,
                              1,
                              i18nc("electrical current unit symbol", "A"),
                              i18nc("unit description in lists", "amperes"),
                              i18nc("unit synonyms for matching user input", "amp;amps;ampere;amperes;A"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 amperes"),
                              ki18ncp("amount in units (integer)", "%1 ampere", "%1 amperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Deciampere,
                       0.1,
                       i18nc("electrical current unit symbol", "dA"),
                       i18nc("unit description in lists", "deciamperes"),
                       i18nc("unit synonyms for matching user input", "deciampere;deciamperes;dA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 deciamperes"),
                       ki18ncp("amount in units (integer)", "%1 deciampere", "%1 deciamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Centiampere,
                       0.01,
                       i18nc("electrical current unit symbol", "cA"),
                       i18nc("unit description in lists", "centiamperes"),
                       i18nc("unit synonyms for matching user input", "centiampere;centiamperes;cA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 centiamperes"),
                       ki18ncp("amount in units (integer)", "%1 centiampere", "%1 centiamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Milliampere,
                       0.001,
                       i18nc("electrical current unit symbol", "mA"),
                       i18nc("unit description in lists", "milliamperes"),
                       i18nc("unit synonyms for matching user input", "milliamp;milliamps;milliampere;milliamperes;mA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 milliamperes"),
                       ki18ncp("amount in units (integer)", "%1 milliampere", "%1 milliamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Microampere,
                       1e-06,
                       i18nc("electrical current unit symbol", "µA"),
                       i18nc("unit description in lists", "microamperes"),
                       i18nc("unit synonyms for matching user input", "microamp;microamps;microampere;microamperes;µA;uA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 microamperes"),
                       ki18ncp("amount in units (integer)", "%1 microampere", "%1 microamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Nanoampere,
                       1e-09,
                       i18nc("electrical current unit symbol", "nA"),
                       i18nc("unit description in lists", "nanoamperes"),
                       i18nc("unit synonyms for matching user input", "nanoamp;nanoamps;nanoampere;nanoamperes;nA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 nanoamperes"),
                       ki18ncp("amount in units (integer)", "%1 nanoampere", "%1 nanoamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Picoampere,
                       1e-12,
                       i18nc("electrical current unit symbol", "pA"),
                       i18nc("unit description in lists", "picoamperes"),
                       i18nc("unit synonyms for matching user input", "picoamp;picoamps;picoampere;picoamperes;pA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 picoamperes"),
                       ki18ncp("amount in units (integer)", "%1 picoampere", "%1 picoamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Femtoampere,
                       1e-15,
                       i18nc("electrical current unit symbol", "fA"),
                       i18nc("unit description in lists", "femtoamperes"),
                       i18nc("unit synonyms for matching user input", "femtoampere;femtoamperes;fA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 femtoamperes"),
                       ki18ncp("amount in units (integer)", "%1 femtoampere", "%1 femtoamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Attoampere,
                       1e-18,
                       i18nc("electrical current unit symbol", "aA"),
                       i18nc("unit description in lists", "attoamperes"),
                       i18nc("unit synonyms for matching user input", "attoampere;attoamperes;aA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 attoamperes"),
                       ki18ncp("amount in units (integer)", "%1 attoampere", "%1 attoamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Zeptoampere,
                       1e-21,
                       i18nc("electrical current unit symbol", "zA"),
                       i18nc("unit description in lists", "zeptoamperes"),
                       i18nc("unit synonyms for matching user input", "zeptoampere;zeptoamperes;zA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zeptoamperes"),
                       ki18ncp("amount in units (integer)", "%1 zeptoampere", "%1 zeptoamperes")));

    addUnit(CustomUnit(ElectricalCurrentCategory,
                       Yoctoampere,
                       1e-24,
                       i18nc("electrical current unit symbol", "yA"),
                       i18nc("unit description in lists", "yoctoamperes"),
                       i18nc("unit synonyms for matching user input", "yoctoampere;yoctoamperes;yA"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yoctoamperes"),
                       ki18ncp("amount in units (integer)", "%1 yoctoampere", "%1 yoctoamperes")));
}

} // KUnitConversion namespace
