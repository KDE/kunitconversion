/*
 *   SPDX-FileCopyrightText: 2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "power_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>
#include <QtMath>

namespace KUnitConversion
{
class DecibelUnitPrivate : public UnitPrivate
{
public:
    DecibelUnitPrivate(CategoryId categoryId,
                       UnitId id,
                       qreal multiplier,
                       const QString &symbol,
                       const QString &description,
                       const QString &matchString,
                       const KLocalizedString &symbolString,
                       const KLocalizedString &realString,
                       const KLocalizedString &integerString)
        : UnitPrivate(categoryId, id, multiplier, symbol, description, matchString, symbolString, realString, integerString)
    {
    }

    qreal toDefault(qreal value) const override
    {
        // y[W] = 10 ^ (value[dBW] / 10)
        return qPow(10, value / 10) * m_multiplier;
    }

    qreal fromDefault(qreal value) const override
    {
        // y[dBW] = 10 * log10(value[W])
        // QMath only provides natural log function (qLn) and constant M_LN10 = ln(10)
        // We use the logarithm change of base: log10(x) = ln(x) / ln(10)
        return 10 * qLn(value / m_multiplier) / M_LN10;
    }
};

Power::Power()
    : CustomCategory(PowerCategory, i18n("Power"), i18n("Power"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (power)", "%1 %2");

    addUnit(CustomUnit(PowerCategory,
                       Yottawatt,
                       1e+24,
                       i18nc("power unit symbol", "YW"),
                       i18nc("unit description in lists", "yottawatts"),
                       i18nc("unit synonyms for matching user input", "yottawatt;yottawatts;YW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yottawatts"),
                       ki18ncp("amount in units (integer)", "%1 yottawatt", "%1 yottawatts")));

    addUnit(CustomUnit(PowerCategory,
                       Zettawatt,
                       1e+21,
                       i18nc("power unit symbol", "ZW"),
                       i18nc("unit description in lists", "zettawatts"),
                       i18nc("unit synonyms for matching user input", "zettawatt;zettawatts;ZW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zettawatts"),
                       ki18ncp("amount in units (integer)", "%1 zettawatt", "%1 zettawatts")));

    addUnit(CustomUnit(PowerCategory,
                       Exawatt,
                       1e+18,
                       i18nc("power unit symbol", "EW"),
                       i18nc("unit description in lists", "exawatts"),
                       i18nc("unit synonyms for matching user input", "exawatt;exawatts;EW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 exawatts"),
                       ki18ncp("amount in units (integer)", "%1 exawatt", "%1 exawatts")));

    addUnit(CustomUnit(PowerCategory,
                       Petawatt,
                       1e+15,
                       i18nc("power unit symbol", "PW"),
                       i18nc("unit description in lists", "petawatts"),
                       i18nc("unit synonyms for matching user input", "petawatt;petawatts;PW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 petawatts"),
                       ki18ncp("amount in units (integer)", "%1 petawatt", "%1 petawatts")));

    addUnit(CustomUnit(PowerCategory,
                       Terawatt,
                       1e+12,
                       i18nc("power unit symbol", "TW"),
                       i18nc("unit description in lists", "terawatts"),
                       i18nc("unit synonyms for matching user input", "terawatt;terawatts;TW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 terawatts"),
                       ki18ncp("amount in units (integer)", "%1 terawatt", "%1 terawatts")));

    addUnit(CustomUnit(PowerCategory,
                       Gigawatt,
                       1e+09,
                       i18nc("power unit symbol", "GW"),
                       i18nc("unit description in lists", "gigawatts"),
                       i18nc("unit synonyms for matching user input", "gigawatt;gigawatts;GW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 gigawatts"),
                       ki18ncp("amount in units (integer)", "%1 gigawatt", "%1 gigawatts")));

    addUnit(CustomUnit(PowerCategory,
                       Megawatt,
                       1e+06,
                       i18nc("power unit symbol", "MW"),
                       i18nc("unit description in lists", "megawatts"),
                       i18nc("unit synonyms for matching user input", "megawatt;megawatts;MW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 megawatts"),
                       ki18ncp("amount in units (integer)", "%1 megawatt", "%1 megawatts")));

    addCommonUnit(CustomUnit(PowerCategory,
                             Kilowatt,
                             1000,
                             i18nc("power unit symbol", "kW"),
                             i18nc("unit description in lists", "kilowatts"),
                             i18nc("unit synonyms for matching user input", "kilowatt;kilowatts;kW"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kilowatts"),
                             ki18ncp("amount in units (integer)", "%1 kilowatt", "%1 kilowatts")));

    addUnit(CustomUnit(PowerCategory,
                       Hectowatt,
                       100,
                       i18nc("power unit symbol", "hW"),
                       i18nc("unit description in lists", "hectowatts"),
                       i18nc("unit synonyms for matching user input", "hectowatt;hectowatts;hW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 hectowatts"),
                       ki18ncp("amount in units (integer)", "%1 hectowatt", "%1 hectowatts")));

    addUnit(CustomUnit(PowerCategory,
                       Decawatt,
                       10,
                       i18nc("power unit symbol", "daW"),
                       i18nc("unit description in lists", "decawatts"),
                       i18nc("unit synonyms for matching user input", "decawatt;decawatts;daW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 decawatts"),
                       ki18ncp("amount in units (integer)", "%1 decawatt", "%1 decawatts")));

    addDefaultUnit(CustomUnit(PowerCategory,
                              Watt,
                              1,
                              i18nc("power unit symbol", "W"),
                              i18nc("unit description in lists", "watts"),
                              i18nc("unit synonyms for matching user input", "watt;watts;W"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 watts"),
                              ki18ncp("amount in units (integer)", "%1 watt", "%1 watts")));

    addUnit(CustomUnit(PowerCategory,
                       Deciwatt,
                       0.1,
                       i18nc("power unit symbol", "dW"),
                       i18nc("unit description in lists", "deciwatts"),
                       i18nc("unit synonyms for matching user input", "deciwatt;deciwatts;dW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 deciwatts"),
                       ki18ncp("amount in units (integer)", "%1 deciwatt", "%1 deciwatts")));

    addUnit(CustomUnit(PowerCategory,
                       Centiwatt,
                       0.01,
                       i18nc("power unit symbol", "cW"),
                       i18nc("unit description in lists", "centiwatts"),
                       i18nc("unit synonyms for matching user input", "centiwatt;centiwatts;cW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 centiwatts"),
                       ki18ncp("amount in units (integer)", "%1 centiwatt", "%1 centiwatts")));

    addUnit(CustomUnit(PowerCategory,
                       Milliwatt,
                       0.001,
                       i18nc("power unit symbol", "mW"),
                       i18nc("unit description in lists", "milliwatts"),
                       i18nc("unit synonyms for matching user input", "milliwatt;milliwatts;mW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 milliwatts"),
                       ki18ncp("amount in units (integer)", "%1 milliwatt", "%1 milliwatts")));

    addUnit(CustomUnit(PowerCategory,
                       Microwatt,
                       1e-06,
                       i18nc("power unit symbol", "µW"),
                       i18nc("unit description in lists", "microwatts"),
                       i18nc("unit synonyms for matching user input", "microwatt;microwatts;µW;uW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 microwatts"),
                       ki18ncp("amount in units (integer)", "%1 microwatt", "%1 microwatts")));

    addUnit(CustomUnit(PowerCategory,
                       Nanowatt,
                       1e-09,
                       i18nc("power unit symbol", "nW"),
                       i18nc("unit description in lists", "nanowatts"),
                       i18nc("unit synonyms for matching user input", "nanowatt;nanowatts;nW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 nanowatts"),
                       ki18ncp("amount in units (integer)", "%1 nanowatt", "%1 nanowatts")));

    addUnit(CustomUnit(PowerCategory,
                       Picowatt,
                       1e-12,
                       i18nc("power unit symbol", "pW"),
                       i18nc("unit description in lists", "picowatts"),
                       i18nc("unit synonyms for matching user input", "picowatt;picowatts;pW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 picowatts"),
                       ki18ncp("amount in units (integer)", "%1 picowatt", "%1 picowatts")));

    addUnit(CustomUnit(PowerCategory,
                       Femtowatt,
                       1e-15,
                       i18nc("power unit symbol", "fW"),
                       i18nc("unit description in lists", "femtowatts"),
                       i18nc("unit synonyms for matching user input", "femtowatt;femtowatts;fW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 femtowatts"),
                       ki18ncp("amount in units (integer)", "%1 femtowatt", "%1 femtowatts")));

    addUnit(CustomUnit(PowerCategory,
                       Attowatt,
                       1e-18,
                       i18nc("power unit symbol", "aW"),
                       i18nc("unit description in lists", "attowatts"),
                       i18nc("unit synonyms for matching user input", "attowatt;attowatts;aW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 attowatts"),
                       ki18ncp("amount in units (integer)", "%1 attowatt", "%1 attowatts")));

    addUnit(CustomUnit(PowerCategory,
                       Zeptowatt,
                       1e-21,
                       i18nc("power unit symbol", "zW"),
                       i18nc("unit description in lists", "zeptowatts"),
                       i18nc("unit synonyms for matching user input", "zeptowatt;zeptowatts;zW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zeptowatts"),
                       ki18ncp("amount in units (integer)", "%1 zeptowatt", "%1 zeptowatts")));

    addUnit(CustomUnit(PowerCategory,
                       Yoctowatt,
                       1e-24,
                       i18nc("power unit symbol", "yW"),
                       i18nc("unit description in lists", "yoctowatts"),
                       i18nc("unit synonyms for matching user input", "yoctowatt;yoctowatts;yW"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yoctowatts"),
                       ki18ncp("amount in units (integer)", "%1 yoctowatt", "%1 yoctowatts")));

    addCommonUnit(CustomUnit(PowerCategory,
                             Horsepower,
                             735.499,
                             i18nc("power unit symbol", "hp"),
                             i18nc("unit description in lists", "horsepowers"),
                             i18nc("unit synonyms for matching user input", "horsepower;horsepowers;hp"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 horsepowers"),
                             ki18ncp("amount in units (integer)", "%1 horsepower", "%1 horsepowers")));

    // Logarithmic Power Units (http://en.wikipedia.org/wiki/Decibel)

    addUnit(CustomUnit(new DecibelUnitPrivate(PowerCategory,
                                              DecibelKilowatt,
                                              1000,
                                              i18nc("power unit symbol", "dBk"),
                                              i18nc("unit description in lists", "decibel kilowatts"),
                                              i18nc("unit synonyms for matching user input", "dBk;dBkW;dB(kW)"),
                                              symbolString,
                                              ki18nc("amount in units (real)", "%1 decibel kilowatts"),
                                              ki18ncp("amount in units (integer)", "%1 decibel kilowatt", "%1 decibel kilowatts"))));

    addUnit(CustomUnit(new DecibelUnitPrivate(PowerCategory,
                                              DecibelWatt,
                                              1,
                                              i18nc("power unit symbol", "dBW"),
                                              i18nc("unit description in lists", "decibel watts"),
                                              i18nc("unit synonyms for matching user input", "dBW;dB(W)"),
                                              symbolString,
                                              ki18nc("amount in units (real)", "%1 decibel watts"),
                                              ki18ncp("amount in units (integer)", "%1 decibel watt", "%1 decibel watts"))));

    addCommonUnit(CustomUnit(new DecibelUnitPrivate(PowerCategory,
                                                    DecibelMilliwatt,
                                                    0.001,
                                                    i18nc("power unit symbol", "dBm"),
                                                    i18nc("unit description in lists", "decibel milliwatts"),
                                                    i18nc("unit synonyms for matching user input", "dBm;dBmW;dB(mW)"),
                                                    symbolString,
                                                    ki18nc("amount in units (real)", "%1 decibel milliwatts"),
                                                    ki18ncp("amount in units (integer)", "%1 decibel milliwatt", "%1 decibel milliwatts"))));

    addUnit(CustomUnit(new DecibelUnitPrivate(PowerCategory,
                                              DecibelMicrowatt,
                                              1e-6,
                                              i18nc("power unit symbol", "dBµW"),
                                              i18nc("unit description in lists", "decibel microwatts"),
                                              i18nc("unit synonyms for matching user input", "dBuW;dBµW;dB(uW);dB(µW)"),
                                              symbolString,
                                              ki18nc("amount in units (real)", "%1 decibel microwatts"),
                                              ki18ncp("amount in units (integer)", "%1 decibel microwatt", "%1 decibel microwatts"))));
}

} // KUnitConversion namespace
