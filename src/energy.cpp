/*
 *   SPDX-FileCopyrightText: 2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "energy_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{
class PhotoUnitPrivate : public UnitPrivate
{
public:
    PhotoUnitPrivate(CategoryId categoryId,
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
        return (2.99792458e+08 * 6.62606896e-34) / (value * 1e-09);
    }

    qreal fromDefault(qreal value) const override
    {
        return ((2.99792458e+08 * 6.62606896e-34) / value) / 1e-09;
    }
};

Energy::Energy()
    : CustomCategory(EnergyCategory, i18n("Energy"), i18n("Energy"))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (energy)", "%1 %2");

    addUnit(CustomUnit(EnergyCategory,
                       Yottajoule,
                       1e+24,
                       i18nc("energy unit symbol", "YJ"),
                       i18nc("unit description in lists", "yottajoules"),
                       i18nc("unit synonyms for matching user input", "yottajoule;yottajoules;YJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yottajoules"),
                       ki18ncp("amount in units (integer)", "%1 yottajoule", "%1 yottajoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Zettajoule,
                       1e+21,
                       i18nc("energy unit symbol", "ZJ"),
                       i18nc("unit description in lists", "zettajoules"),
                       i18nc("unit synonyms for matching user input", "zettajoule;zettajoules;ZJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zettajoules"),
                       ki18ncp("amount in units (integer)", "%1 zettajoule", "%1 zettajoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Exajoule,
                       1e+18,
                       i18nc("energy unit symbol", "EJ"),
                       i18nc("unit description in lists", "exajoules"),
                       i18nc("unit synonyms for matching user input", "exajoule;exajoules;EJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 exajoules"),
                       ki18ncp("amount in units (integer)", "%1 exajoule", "%1 exajoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Petajoule,
                       1e+15,
                       i18nc("energy unit symbol", "PJ"),
                       i18nc("unit description in lists", "petajoules"),
                       i18nc("unit synonyms for matching user input", "petajoule;petajoules;PJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 petajoules"),
                       ki18ncp("amount in units (integer)", "%1 petajoule", "%1 petajoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Terajoule,
                       1e+12,
                       i18nc("energy unit symbol", "TJ"),
                       i18nc("unit description in lists", "terajoules"),
                       i18nc("unit synonyms for matching user input", "terajoule;terajoules;TJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 terajoules"),
                       ki18ncp("amount in units (integer)", "%1 terajoule", "%1 terajoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Gigajoule,
                       1e+09,
                       i18nc("energy unit symbol", "GJ"),
                       i18nc("unit description in lists", "gigajoules"),
                       i18nc("unit synonyms for matching user input", "gigajoule;gigajoules;GJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 gigajoules"),
                       ki18ncp("amount in units (integer)", "%1 gigajoule", "%1 gigajoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Megajoule,
                       1e+06,
                       i18nc("energy unit symbol", "MJ"),
                       i18nc("unit description in lists", "megajoules"),
                       i18nc("unit synonyms for matching user input", "megajoule;megajoules;MJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 megajoules"),
                       ki18ncp("amount in units (integer)", "%1 megajoule", "%1 megajoules")));

    addCommonUnit(CustomUnit(EnergyCategory,
                             Kilojoule,
                             1000,
                             i18nc("energy unit symbol", "kJ"),
                             i18nc("unit description in lists", "kilojoules"),
                             i18nc("unit synonyms for matching user input", "kilojoule;kilojoules;kJ"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kilojoules"),
                             ki18ncp("amount in units (integer)", "%1 kilojoule", "%1 kilojoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Hectojoule,
                       100,
                       i18nc("energy unit symbol", "hJ"),
                       i18nc("unit description in lists", "hectojoules"),
                       i18nc("unit synonyms for matching user input", "hectojoule;hectojoules;hJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 hectojoules"),
                       ki18ncp("amount in units (integer)", "%1 hectojoule", "%1 hectojoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Decajoule,
                       10,
                       i18nc("energy unit symbol", "daJ"),
                       i18nc("unit description in lists", "decajoules"),
                       i18nc("unit synonyms for matching user input", "decajoule;decajoules;daJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 decajoules"),
                       ki18ncp("amount in units (integer)", "%1 decajoule", "%1 decajoules")));

    addDefaultUnit(CustomUnit(EnergyCategory,
                              Joule,
                              1,
                              i18nc("energy unit symbol", "J"),
                              i18nc("unit description in lists", "joules"),
                              i18nc("unit synonyms for matching user input", "joule;joules;J"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 joules"),
                              ki18ncp("amount in units (integer)", "%1 joule", "%1 joules")));

    addUnit(CustomUnit(EnergyCategory,
                       Decijoule,
                       0.1,
                       i18nc("energy unit symbol", "dJ"),
                       i18nc("unit description in lists", "decijoules"),
                       i18nc("unit synonyms for matching user input", "decijoule;decijoules;dJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 decijoules"),
                       ki18ncp("amount in units (integer)", "%1 decijoule", "%1 decijoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Centijoule,
                       0.01,
                       i18nc("energy unit symbol", "cJ"),
                       i18nc("unit description in lists", "centijoules"),
                       i18nc("unit synonyms for matching user input", "centijoule;centijoules;cJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 centijoules"),
                       ki18ncp("amount in units (integer)", "%1 centijoule", "%1 centijoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Millijoule,
                       0.001,
                       i18nc("energy unit symbol", "mJ"),
                       i18nc("unit description in lists", "millijoules"),
                       i18nc("unit synonyms for matching user input", "millijoule;millijoules;mJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 millijoules"),
                       ki18ncp("amount in units (integer)", "%1 millijoule", "%1 millijoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Microjoule,
                       1e-06,
                       i18nc("energy unit symbol", "µJ"),
                       i18nc("unit description in lists", "microjoules"),
                       i18nc("unit synonyms for matching user input", "microjoule;microjoules;µJ;uJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 microjoules"),
                       ki18ncp("amount in units (integer)", "%1 microjoule", "%1 microjoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Nanojoule,
                       1e-09,
                       i18nc("energy unit symbol", "nJ"),
                       i18nc("unit description in lists", "nanojoules"),
                       i18nc("unit synonyms for matching user input", "nanojoule;nanojoules;nJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 nanojoules"),
                       ki18ncp("amount in units (integer)", "%1 nanojoule", "%1 nanojoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Picojoule,
                       1e-12,
                       i18nc("energy unit symbol", "pJ"),
                       i18nc("unit description in lists", "picojoules"),
                       i18nc("unit synonyms for matching user input", "picojoule;picojoules;pJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 picojoules"),
                       ki18ncp("amount in units (integer)", "%1 picojoule", "%1 picojoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Femtojoule,
                       1e-15,
                       i18nc("energy unit symbol", "fJ"),
                       i18nc("unit description in lists", "femtojoules"),
                       i18nc("unit synonyms for matching user input", "femtojoule;femtojoules;fJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 femtojoules"),
                       ki18ncp("amount in units (integer)", "%1 femtojoule", "%1 femtojoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Attojoule,
                       1e-18,
                       i18nc("energy unit symbol", "aJ"),
                       i18nc("unit description in lists", "attojoules"),
                       i18nc("unit synonyms for matching user input", "attojoule;attojoules;aJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 attojoules"),
                       ki18ncp("amount in units (integer)", "%1 attojoule", "%1 attojoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Zeptojoule,
                       1e-21,
                       i18nc("energy unit symbol", "zJ"),
                       i18nc("unit description in lists", "zeptojoules"),
                       i18nc("unit synonyms for matching user input", "zeptojoule;zeptojoules;zJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zeptojoules"),
                       ki18ncp("amount in units (integer)", "%1 zeptojoule", "%1 zeptojoules")));

    addUnit(CustomUnit(EnergyCategory,
                       Yoctojoule,
                       1e-24,
                       i18nc("energy unit symbol", "yJ"),
                       i18nc("unit description in lists", "yoctojoules"),
                       i18nc("unit synonyms for matching user input", "yoctojoule;yoctojoules;yJ"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yoctojoules"),
                       ki18ncp("amount in units (integer)", "%1 yoctojoule", "%1 yoctojoules")));

    addCommonUnit(CustomUnit(EnergyCategory,
                             GuidelineDailyAmount,
                             8.3736e+06,
                             i18nc("energy unit symbol", "GDA"),
                             i18nc("unit description in lists", "guideline daily amount"),
                             i18nc("unit synonyms for matching user input", "guideline daily amount;guideline daily amount;GDA"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 guideline daily amount"),
                             ki18ncp("amount in units (integer)", "%1 guideline daily amount", "%1 guideline daily amount")));

    addUnit(CustomUnit(EnergyCategory,
                       Electronvolt,
                       1.60218e-19,
                       i18nc("energy unit symbol", "eV"),
                       i18nc("unit description in lists", "electronvolts"),
                       i18nc("unit synonyms for matching user input", "electronvolt;electronvolts;eV"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 electronvolts"),
                       ki18ncp("amount in units (integer)", "%1 electronvolt", "%1 electronvolts")));

    addUnit(CustomUnit(EnergyCategory,
                       JoulePerMole,
                       1.66054238581e-24,
                       i18nc("energy unit symbol", "J/mol"),
                       i18nc("unit description in lists", "joule per mole"),
                       i18nc("unit synonyms for matching user input", "joule per mole;joulepermole;joulemol;jmol;j/mol"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 joules per mole"),
                       ki18ncp("amount in units (integer)", "%1 joule per mole", "%1 joules per mole")));

    addUnit(CustomUnit(EnergyCategory,
                       KiloJoulePerMole,
                       1.66054238581e-21,
                       i18nc("energy unit symbol", "kJ/mol"),
                       i18nc("unit description in lists", "kilojoule per mole"),
                       i18nc("unit synonyms for matching user input", "kilojoule per mole;kilojoulepermole;kilojoule per mole;kilojoulemol;kjmol;kj/mol"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 kilojoules per mole"),
                       ki18ncp("amount in units (integer)", "%1 kilojoule per mole", "%1 kilojoules per mole")));

    addUnit(CustomUnit(EnergyCategory,
                       Rydberg,
                       2.17987e-18,
                       i18nc("energy unit symbol", "Ry"),
                       i18nc("unit description in lists", "rydbergs"),
                       i18nc("unit synonyms for matching user input", "rydberg;rydbergs;Ry"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 rydbergs"),
                       ki18ncp("amount in units (integer)", "%1 rydberg", "%1 rydbergs")));

    addCommonUnit(CustomUnit(EnergyCategory,
                             Kilocalorie,
                             4186.8,
                             i18nc("energy unit symbol", "kcal"),
                             i18nc("unit description in lists", "kilocalories"),
                             i18nc("unit synonyms for matching user input", "kilocalorie;kilocalories;kcal"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 kilocalories"),
                             ki18ncp("amount in units (integer)", "%1 kilocalorie", "%1 kilocalories")));

    addCommonUnit(CustomUnit(EnergyCategory,
                             Btu,
                             1055.05585,
                             i18nc("energy unit symbol", "BTU"),
                             i18nc("unit description in lists", "British Thermal Unit"),
                             i18nc("unit synonyms for matching user input", "Btu;BTU;Btus;BTUs"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 BTU"),
                             ki18ncp("amount in units (integer)", "%1 BTU", "%1 BTU")));

    addCommonUnit(CustomUnit(EnergyCategory,
                             Erg,
                             1.0e-7,
                             i18nc("energy unit symbol", "Erg"),
                             i18nc("unit description in lists", "ergs"),
                             i18nc("unit synonyms for matching user input", "Erg;erg;Ergs;ergs"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 ergs"),
                             ki18ncp("amount in units (integer)", "%1 erg", "%1 erg")));

    addUnit(CustomUnit(new PhotoUnitPrivate(EnergyCategory,
                                            PhotonWavelength,
                                            1.0,
                                            i18nc("energy unit symbol", "nm"),
                                            i18nc("unit description in lists", "photon wavelength in nanometers"),
                                            i18nc("unit synonyms for matching user input", "nm;photon wavelength"),
                                            symbolString,
                                            ki18nc("amount in units (real)", "%1 nanometers"),
                                            ki18ncp("amount in units (integer)", "%1 nanometer", "%1 nanometers"))));
}

} // KUnitConversion namespace
