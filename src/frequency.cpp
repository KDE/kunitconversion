/*
 *   SPDX-FileCopyrightText: 2010 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "frequency_p.h"
#include "unit_p.h"

#include <KLocalizedString>

namespace KUnitConversion
{

UnitCategory Frequency::makeCategory()
{
    auto c = UnitCategoryPrivate::makeCategory(FrequencyCategory, i18n("Frequency"), i18n("Frequency"));
    auto d = UnitCategoryPrivate::get(c);
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (frequency", "%1 %2");

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Yottahertz,
                       1e+24,
                       i18nc("frequency unit symbol", "YHz"),
                       i18nc("unit description in lists", "yottahertz"),
                       i18nc("unit synonyms for matching user input", "yottahertz;yottahertzs;YHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yottahertz"),
                       ki18ncp("amount in units (integer)", "%1 yottahertz", "%1 yottahertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Zettahertz,
                       1e+21,
                       i18nc("frequency unit symbol", "ZHz"),
                       i18nc("unit description in lists", "zettahertz"),
                       i18nc("unit synonyms for matching user input", "zettahertz;zettahertzs;ZHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zettahertz"),
                       ki18ncp("amount in units (integer)", "%1 zettahertz", "%1 zettahertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Exahertz,
                       1e+18,
                       i18nc("frequency unit symbol", "EHz"),
                       i18nc("unit description in lists", "exahertz"),
                       i18nc("unit synonyms for matching user input", "exahertz;exahertzs;EHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 exahertz"),
                       ki18ncp("amount in units (integer)", "%1 exahertz", "%1 exahertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Petahertz,
                       1e+15,
                       i18nc("frequency unit symbol", "PHz"),
                       i18nc("unit description in lists", "petahertz"),
                       i18nc("unit synonyms for matching user input", "petahertz;petahertzs;PHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 petahertz"),
                       ki18ncp("amount in units (integer)", "%1 petahertz", "%1 petahertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Terahertz,
                       1e+12,
                       i18nc("frequency unit symbol", "THz"),
                       i18nc("unit description in lists", "terahertz"),
                       i18nc("unit synonyms for matching user input", "terahertz;terahertzs;THz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 terahertz"),
                       ki18ncp("amount in units (integer)", "%1 terahertz", "%1 terahertz")));

    d->addCommonUnit(UnitPrivate::makeUnit(FrequencyCategory,
                             Gigahertz,
                             1e+09,
                             i18nc("frequency unit symbol", "GHz"),
                             i18nc("unit description in lists", "gigahertz"),
                             i18nc("unit synonyms for matching user input", "gigahertz;gigahertzs;GHz"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 gigahertz"),
                             ki18ncp("amount in units (integer)", "%1 gigahertz", "%1 gigahertz")));

    d->addCommonUnit(UnitPrivate::makeUnit(FrequencyCategory,
                             Megahertz,
                             1e+06,
                             i18nc("frequency unit symbol", "MHz"),
                             i18nc("unit description in lists", "megahertz"),
                             i18nc("unit synonyms for matching user input", "megahertz;megahertzs;MHz"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 megahertz"),
                             ki18ncp("amount in units (integer)", "%1 megahertz", "%1 megahertz")));

    d->addCommonUnit(UnitPrivate::makeUnit(FrequencyCategory,
                             Kilohertz,
                             1000,
                             i18nc("frequency unit symbol", "kHz"),
                             i18nc("unit description in lists", "kilohertz"),
                             i18nc("unit synonyms for matching user input", "kilohertz;kilohertzs;kHz"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kilohertz"),
                             ki18ncp("amount in units (integer)", "%1 kilohertz", "%1 kilohertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Hectohertz,
                       100,
                       i18nc("frequency unit symbol", "hHz"),
                       i18nc("unit description in lists", "hectohertz"),
                       i18nc("unit synonyms for matching user input", "hectohertz;hectohertzs;hHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 hectohertz"),
                       ki18ncp("amount in units (integer)", "%1 hectohertz", "%1 hectohertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Decahertz,
                       10,
                       i18nc("frequency unit symbol", "daHz"),
                       i18nc("unit description in lists", "decahertz"),
                       i18nc("unit synonyms for matching user input", "decahertz;decahertz;daHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 decahertz"),
                       ki18ncp("amount in units (integer)", "%1 decahertz", "%1 decahertz")));

    d->addDefaultUnit(UnitPrivate::makeUnit(FrequencyCategory,
                              Hertz,
                              1,
                              i18nc("frequency unit symbol", "Hz"),
                              i18nc("unit description in lists", "hertz"),
                              i18nc("unit synonyms for matching user input", "hertz;hertzs;Hz"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 hertz"),
                              ki18ncp("amount in units (integer)", "%1 hertz", "%1 hertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Decihertz,
                       0.1,
                       i18nc("frequency unit symbol", "dHz"),
                       i18nc("unit description in lists", "decihertz"),
                       i18nc("unit synonyms for matching user input", "decihertz;decihertzs;dHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 decihertz"),
                       ki18ncp("amount in units (integer)", "%1 decihertz", "%1 decihertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Centihertz,
                       0.01,
                       i18nc("frequency unit symbol", "cHz"),
                       i18nc("unit description in lists", "centihertz"),
                       i18nc("unit synonyms for matching user input", "centihertz;centihertzs;cHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 centihertz"),
                       ki18ncp("amount in units (integer)", "%1 centihertz", "%1 centihertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Millihertz,
                       0.001,
                       i18nc("frequency unit symbol", "mHz"),
                       i18nc("unit description in lists", "millihertz"),
                       i18nc("unit synonyms for matching user input", "millihertz;millihertzs;mHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 millihertz"),
                       ki18ncp("amount in units (integer)", "%1 millihertz", "%1 millihertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Microhertz,
                       1e-06,
                       i18nc("frequency unit symbol", "µHz"),
                       i18nc("unit description in lists", "microhertz"),
                       i18nc("unit synonyms for matching user input", "microhertz;microhertzs;µHz;uHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 microhertz"),
                       ki18ncp("amount in units (integer)", "%1 microhertz", "%1 microhertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Nanohertz,
                       1e-09,
                       i18nc("frequency unit symbol", "nHz"),
                       i18nc("unit description in lists", "nanohertz"),
                       i18nc("unit synonyms for matching user input", "nanohertz;nanohertzs;nHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 nanohertz"),
                       ki18ncp("amount in units (integer)", "%1 nanohertz", "%1 nanohertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Picohertz,
                       1e-12,
                       i18nc("frequency unit symbol", "pHz"),
                       i18nc("unit description in lists", "picohertz"),
                       i18nc("unit synonyms for matching user input", "picohertz;picohertzs;pHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 picohertz"),
                       ki18ncp("amount in units (integer)", "%1 picohertz", "%1 picohertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Femtohertz,
                       1e-15,
                       i18nc("frequency unit symbol", "fHz"),
                       i18nc("unit description in lists", "femtohertz"),
                       i18nc("unit synonyms for matching user input", "femtohertz;femtohertzs;fHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 femtohertz"),
                       ki18ncp("amount in units (integer)", "%1 femtohertz", "%1 femtohertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Attohertz,
                       1e-18,
                       i18nc("frequency unit symbol", "aHz"),
                       i18nc("unit description in lists", "attohertz"),
                       i18nc("unit synonyms for matching user input", "attohertz;attohertzs;aHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 attohertz"),
                       ki18ncp("amount in units (integer)", "%1 attohertz", "%1 attohertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Zeptohertz,
                       1e-21,
                       i18nc("frequency unit symbol", "zHz"),
                       i18nc("unit description in lists", "zeptohertz"),
                       i18nc("unit synonyms for matching user input", "zeptohertz;zeptohertzs;zHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zeptohertz"),
                       ki18ncp("amount in units (integer)", "%1 zeptohertz", "%1 zeptohertz")));

    d->addUnit(UnitPrivate::makeUnit(FrequencyCategory,
                       Yoctohertz,
                       1e-24,
                       i18nc("frequency unit symbol", "yHz"),
                       i18nc("unit description in lists", "yoctohertz"),
                       i18nc("unit synonyms for matching user input", "yoctohertz;yoctohertzs;yHz"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yoctohertz"),
                       ki18ncp("amount in units (integer)", "%1 yoctohertz", "%1 yoctohertz")));

    d->addCommonUnit(UnitPrivate::makeUnit(FrequencyCategory,
                             RPM,
                             1.0 / 60.0,
                             i18nc("frequency unit symbol", "RPM"),
                             i18nc("unit description in lists", "revolutions per minute"),
                             i18nc("unit synonyms for matching user input", "revolutions per minute;revolution per minute;RPM"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 revolutions per minute"),
                             ki18ncp("amount in units (integer)", "%1 revolution per minute", "%1 revolutions per minute")));

    return c;
}

} // KUnitConversion namespace
