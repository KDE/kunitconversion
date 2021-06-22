/*
 *   SPDX-FileCopyrightText: 2010 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *   SPDX-FileCopyrightText: 2014 Garret Wassermann <gwasser@gmail.com>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "electrical_resistance_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{
ElectricalResistance::ElectricalResistance()
    : CustomCategory(ElectricalResistanceCategory, i18n("Resistance"), i18n("Resistance"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (electrical resistance", "%1 %2");

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Yottaohms,
                       1e+24,
                       i18nc("electrical resistance unit symbol", "YΩ"),
                       i18nc("unit description in lists", "yottaohms"),
                       i18nc("unit synonyms for matching user input", "yottaohm;yottaohms;YΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yottaohms"),
                       ki18ncp("amount in units (integer)", "%1 yottaohm", "%1 yottaohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Zettaohms,
                       1e+21,
                       i18nc("electrical resistance unit symbol", "ZΩ"),
                       i18nc("unit description in lists", "zettaohms"),
                       i18nc("unit synonyms for matching user input", "zettaohm;zettaohms;ZΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zettaohms"),
                       ki18ncp("amount in units (integer)", "%1 zettaohm", "%1 zettaohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Exaohms,
                       1e+18,
                       i18nc("electrical resistance unit symbol", "EΩ"),
                       i18nc("unit description in lists", "exaohms"),
                       i18nc("unit synonyms for matching user input", "exaohm;exaohms;EΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 exaohms"),
                       ki18ncp("amount in units (integer)", "%1 exaohm", "%1 exaohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Petaohms,
                       1e+15,
                       i18nc("electrical resistance unit symbol", "PΩ"),
                       i18nc("unit description in lists", "petaohms"),
                       i18nc("unit synonyms for matching user input", "petaohm;petaohms;PΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 petaohms"),
                       ki18ncp("amount in units (integer)", "%1 petaohm", "%1 petaohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Teraohms,
                       1e+12,
                       i18nc("electrical resistance unit symbol", "TΩ"),
                       i18nc("unit description in lists", "teraohms"),
                       i18nc("unit synonyms for matching user input", "teraohm;teraohms;TΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 teraohms"),
                       ki18ncp("amount in units (integer)", "%1 teraohm", "%1 teraohms")));

    addCommonUnit(CustomUnit(ElectricalResistanceCategory,
                             Gigaohms,
                             1e+09,
                             i18nc("electrical resistance unit symbol", "GΩ"),
                             i18nc("unit description in lists", "gigaohms"),
                             i18nc("unit synonyms for matching user input", "gigaohm;gigaohms;GΩ"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 gigaohms"),
                             ki18ncp("amount in units (integer)", "%1 gigaohm", "%1 gigaohms")));

    addCommonUnit(CustomUnit(ElectricalResistanceCategory,
                             Megaohms,
                             1e+06,
                             i18nc("electrical resistance unit symbol", "MΩ"),
                             i18nc("unit description in lists", "megaohms"),
                             i18nc("unit synonyms for matching user input", "megaohm;megaohms;MΩ"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 megaohms"),
                             ki18ncp("amount in units (integer)", "%1 megaohm", "%1 megaohms")));

    addCommonUnit(CustomUnit(ElectricalResistanceCategory,
                             Kiloohms,
                             1000,
                             i18nc("electrical resistance unit symbol", "kΩ"),
                             i18nc("unit description in lists", "kiloohms"),
                             i18nc("unit synonyms for matching user input", "kiloohm;kiloohms;kΩ"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kiloohms"),
                             ki18ncp("amount in units (integer)", "%1 kiloohm", "%1 kiloohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Hectoohms,
                       100,
                       i18nc("electrical resistance unit symbol", "hΩ"),
                       i18nc("unit description in lists", "hectoohms"),
                       i18nc("unit synonyms for matching user input", "hectoohm;hectoohms;hΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 hectoohms"),
                       ki18ncp("amount in units (integer)", "%1 hectoohm", "%1 hectoohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Decaohms,
                       10,
                       i18nc("electrical resistance unit symbol", "daΩ"),
                       i18nc("unit description in lists", "decaohms"),
                       i18nc("unit synonyms for matching user input", "decaohm;decaohms;daΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 decaohms"),
                       ki18ncp("amount in units (integer)", "%1 decaohm", "%1 decaohms")));

    addDefaultUnit(CustomUnit(ElectricalResistanceCategory,
                              Ohms,
                              1,
                              i18nc("electrical resistance unit symbol", "Ω"),
                              i18nc("unit description in lists", "ohms"),
                              i18nc("unit synonyms for matching user input", "ohm;ohms;Ω"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 ohms"),
                              ki18ncp("amount in units (integer)", "%1 ohm", "%1 ohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Deciohms,
                       0.1,
                       i18nc("electrical resistance unit symbol", "dΩ"),
                       i18nc("unit description in lists", "deciohms"),
                       i18nc("unit synonyms for matching user input", "deciohm;deciohms;dΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 deciohms"),
                       ki18ncp("amount in units (integer)", "%1 deciohm", "%1 deciohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Centiohms,
                       0.01,
                       i18nc("electrical resistance unit symbol", "cΩ"),
                       i18nc("unit description in lists", "centiohms"),
                       i18nc("unit synonyms for matching user input", "centiohm;centiohms;cΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 centiohms"),
                       ki18ncp("amount in units (integer)", "%1 centiohm", "%1 centiohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Milliohms,
                       0.001,
                       i18nc("electrical resistance unit symbol", "mΩ"),
                       i18nc("unit description in lists", "milliohms"),
                       i18nc("unit synonyms for matching user input", "milliohm;milliohms;mΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 milliohms"),
                       ki18ncp("amount in units (integer)", "%1 milliohm", "%1 milliohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Microohms,
                       1e-06,
                       i18nc("electrical resistance unit symbol", "µΩ"),
                       i18nc("unit description in lists", "microohms"),
                       i18nc("unit synonyms for matching user input", "microohm;microohms;µΩ;uΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 microohms"),
                       ki18ncp("amount in units (integer)", "%1 microohm", "%1 microohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Nanoohms,
                       1e-09,
                       i18nc("electrical resistance unit symbol", "nΩ"),
                       i18nc("unit description in lists", "nanoohms"),
                       i18nc("unit synonyms for matching user input", "nanoohm;nanoohms;nΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 nanoohms"),
                       ki18ncp("amount in units (integer)", "%1 nanoohm", "%1 nanoohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Picoohms,
                       1e-12,
                       i18nc("electrical resistance unit symbol", "pΩ"),
                       i18nc("unit description in lists", "picoohms"),
                       i18nc("unit synonyms for matching user input", "picoohm;picoohms;pΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 picoohms"),
                       ki18ncp("amount in units (integer)", "%1 picoohm", "%1 picoohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Femtoohms,
                       1e-15,
                       i18nc("electrical resistance unit symbol", "fΩ"),
                       i18nc("unit description in lists", "femtoohms"),
                       i18nc("unit synonyms for matching user input", "femtoohm;femtoohms;fΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 femtoohms"),
                       ki18ncp("amount in units (integer)", "%1 femtoohm", "%1 femtoohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Attoohms,
                       1e-18,
                       i18nc("electrical resistance unit symbol", "aΩ"),
                       i18nc("unit description in lists", "attoohms"),
                       i18nc("unit synonyms for matching user input", "attoohm;attoohms;aΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 attoohms"),
                       ki18ncp("amount in units (integer)", "%1 attoohm", "%1 attoohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Zeptoohms,
                       1e-21,
                       i18nc("electrical resistance unit symbol", "zΩ"),
                       i18nc("unit description in lists", "zeptoohms"),
                       i18nc("unit synonyms for matching user input", "zeptoohm;zeptoohms;zΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zeptoohms"),
                       ki18ncp("amount in units (integer)", "%1 zeptoohm", "%1 zeptoohms")));

    addUnit(CustomUnit(ElectricalResistanceCategory,
                       Yoctoohms,
                       1e-24,
                       i18nc("electrical resistance unit symbol", "yΩ"),
                       i18nc("unit description in lists", "yoctoohms"),
                       i18nc("unit synonyms for matching user input", "yoctoohm;yoctoohms;yΩ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yoctoohms"),
                       ki18ncp("amount in units (integer)", "%1 yoctoohm", "%1 yoctoohms")));
}

} // KUnitConversion namespace
