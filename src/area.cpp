/*
 *   SPDX-FileCopyrightText: 2007-2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#include "area_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

namespace KUnitConversion
{
Area::Area()
    : CustomCategory(AreaCategory,
                     i18nc("Unit Category: two dimensional size of a surface", "Area"),
                     i18nc("Unit Category: two dimensional size of a surface", "Area"))
{
    // i18n: Used when converting to symbol string e.g. 2.34 m²
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (area)", "%1 %2");

    addUnit(CustomUnit(AreaCategory,
                       SquareYottameter,
                       1e+48,
                       // i18n: Used when unit symbol is needed.
                       i18nc("area unit symbol", "Ym²"),
                       // i18n: unit as it will be shown to user wherever units are to
                       // be explicitly selected (listbox, radio buttons, checkboxes...).
                       // E.g. an application may give option "Unit of wind speed: [unit-list-box]"
                       i18nc("unit description in lists", "square yottameters"),
                       // i18n: Messages such as this one provide synonyms for each unit,
                       // in order to guess the unit from the text that the user inputs.
                       // Synonyms are semicolon-separated, and you can add as many as
                       // you need (either equal to, more, or less than in the original).
                       // Note that any gramatical inflections of unit names
                       // (such as plural and cases) should also be listed.
                       i18nc("unit synonyms for matching user input", "square yottameter;square yottameters;Ym²;Ym/-2;Ym^2;Ym2"),
                       symbolString,
                       // i18n: This is used when a real-valued amount in units is given,
                       // such as "0.37 miles".
                       ki18nc("amount in units (real)", "%1 square yottameters"),
                       // i18n: This is used when a integer-valued amount in units is given,
                       // such as "1 mile" or "21 miles".
                       ki18ncp("amount in units (integer)", "%1 square yottameter", "%1 square yottameters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareZettameter,
                       1e+42,
                       i18nc("area unit symbol", "Zm²"),
                       i18nc("unit description in lists", "square zettameters"),
                       i18nc("unit synonyms for matching user input", "square zettameter;square zettameters;Zm²;Zm/-2;Zm^2;Zm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square zettameters"),
                       ki18ncp("amount in units (integer)", "%1 square zettameter", "%1 square zettameters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareExameter,
                       1e+36,
                       i18nc("area unit symbol", "Em²"),
                       i18nc("unit description in lists", "square exameters"),
                       i18nc("unit synonyms for matching user input", "square exameter;square exameters;Em²;Em/-2;Em^2;Em2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square exameters"),
                       ki18ncp("amount in units (integer)", "%1 square exameter", "%1 square exameters")));

    addUnit(CustomUnit(AreaCategory,
                       SquarePetameter,
                       1e+30,
                       i18nc("area unit symbol", "Pm²"),
                       i18nc("unit description in lists", "square petameters"),
                       i18nc("unit synonyms for matching user input", "square petameter;square petameters;Pm²;Pm/-2;Pm^2;Pm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square petameters"),
                       ki18ncp("amount in units (integer)", "%1 square petameter", "%1 square petameters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareTerameter,
                       1e+24,
                       i18nc("area unit symbol", "Tm²"),
                       i18nc("unit description in lists", "square terameters"),
                       i18nc("unit synonyms for matching user input", "square terameter;square terameters;Tm²;Tm/-2;Tm^2;Tm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square terameters"),
                       ki18ncp("amount in units (integer)", "%1 square terameter", "%1 square terameters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareGigameter,
                       1e+18,
                       i18nc("area unit symbol", "Gm²"),
                       i18nc("unit description in lists", "square gigameters"),
                       i18nc("unit synonyms for matching user input", "square gigameter;square gigameters;Gm²;Gm/-2;Gm^2;Gm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square gigameters"),
                       ki18ncp("amount in units (integer)", "%1 square gigameter", "%1 square gigameters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareMegameter,
                       1e+12,
                       i18nc("area unit symbol", "Mm²"),
                       i18nc("unit description in lists", "square megameters"),
                       i18nc("unit synonyms for matching user input", "square megameter;square megameters;Mm²;Mm/-2;Mm^2;Mm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square megameters"),
                       ki18ncp("amount in units (integer)", "%1 square megameter", "%1 square megameters")));

    addCommonUnit(CustomUnit(AreaCategory,
                             SquareKilometer,
                             1e+06,
                             i18nc("area unit symbol", "km²"),
                             i18nc("unit description in lists", "square kilometers"),
                             i18nc("unit synonyms for matching user input", "square kilometer;square kilometers;km²;km/-2;km^2;km2"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 square kilometers"),
                             ki18ncp("amount in units (integer)", "%1 square kilometer", "%1 square kilometers")));

    addCommonUnit(CustomUnit(AreaCategory,
                             SquareHectometer,
                             10000,
                             i18nc("area unit symbol", "hm²"),
                             i18nc("unit description in lists", "square hectometers"),
                             i18nc("unit synonyms for matching user input", "square hectometer;square hectometers;hm²;hm/-2;hm^2;hm2;hectare;hectares"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 square hectometers"),
                             ki18ncp("amount in units (integer)", "%1 square hectometer", "%1 square hectometers")));

    addUnit(CustomUnit(AreaCategory,
                       SquareDecameter,
                       100,
                       i18nc("area unit symbol", "dam²"),
                       i18nc("unit description in lists", "square decameters"),
                       i18nc("unit synonyms for matching user input", "square decameter;square decameters;dam²;dam/-2;dam^2;dam2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square decameters"),
                       ki18ncp("amount in units (integer)", "%1 square decameter", "%1 square decameters")));

    addDefaultUnit(CustomUnit(AreaCategory,
                              SquareMeter,
                              1,
                              i18nc("area unit symbol", "m²"),
                              i18nc("unit description in lists", "square meters"),
                              i18nc("unit synonyms for matching user input", "square meter;square meters;m²;m/-2;m^2;m2"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 square meters"),
                              ki18ncp("amount in units (integer)", "%1 square meter", "%1 square meters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareDecimeter,
                       0.01,
                       i18nc("area unit symbol", "dm²"),
                       i18nc("unit description in lists", "square decimeters"),
                       i18nc("unit synonyms for matching user input", "square decimeter;square decimeters;dm²;dm/-2;dm^2;dm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square decimeters"),
                       ki18ncp("amount in units (integer)", "%1 square decimeter", "%1 square decimeters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareCentimeter,
                       0.0001,
                       i18nc("area unit symbol", "cm²"),
                       i18nc("unit description in lists", "square centimeters"),
                       i18nc("unit synonyms for matching user input", "square centimeter;square centimeters;cm²;cm/-2;cm^2;cm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square centimeters"),
                       ki18ncp("amount in units (integer)", "%1 square centimeter", "%1 square centimeters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareMillimeter,
                       1e-06,
                       i18nc("area unit symbol", "mm²"),
                       i18nc("unit description in lists", "square millimeters"),
                       i18nc("unit synonyms for matching user input", "square millimeter;square millimeters;mm²;mm/-2;mm^2;mm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square millimeters"),
                       ki18ncp("amount in units (integer)", "%1 square millimeter", "%1 square millimeters")));

    addUnit(CustomUnit(AreaCategory,
                       SquareMicrometer,
                       1e-12,
                       i18nc("area unit symbol", "µm²"),
                       i18nc("unit description in lists", "square micrometers"),
                       i18nc("unit synonyms for matching user input", "square micrometer;square micrometers;µm²;um²;µm/-2;µm^2;µm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square micrometers"),
                       ki18ncp("amount in units (integer)", "%1 square micrometer", "%1 square micrometers")));

    addUnit(CustomUnit(AreaCategory,
                       SquareNanometer,
                       1e-18,
                       i18nc("area unit symbol", "nm²"),
                       i18nc("unit description in lists", "square nanometers"),
                       i18nc("unit synonyms for matching user input", "square nanometer;square nanometers;nm²;nm/-2;nm^2;nm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square nanometers"),
                       ki18ncp("amount in units (integer)", "%1 square nanometer", "%1 square nanometers")));

    addUnit(CustomUnit(AreaCategory,
                       SquarePicometer,
                       1e-24,
                       i18nc("area unit symbol", "pm²"),
                       i18nc("unit description in lists", "square picometers"),
                       i18nc("unit synonyms for matching user input", "square picometer;square picometers;pm²;pm/-2;pm^2;pm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square picometers"),
                       ki18ncp("amount in units (integer)", "%1 square picometer", "%1 square picometers")));

    addUnit(CustomUnit(AreaCategory,
                       SquareFemtometer,
                       1e-30,
                       i18nc("area unit symbol", "fm²"),
                       i18nc("unit description in lists", "square femtometers"),
                       i18nc("unit synonyms for matching user input", "square femtometer;square femtometers;fm²;fm/-2;fm^2;fm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square femtometers"),
                       ki18ncp("amount in units (integer)", "%1 square femtometer", "%1 square femtometers")));

    addUnit(CustomUnit(AreaCategory,
                       SquareAttometer,
                       1e-36,
                       i18nc("area unit symbol", "am²"),
                       i18nc("unit description in lists", "square attometers"),
                       i18nc("unit synonyms for matching user input", "square attometer;square attometers;am²;am/-2;am^2;am2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square attometers"),
                       ki18ncp("amount in units (integer)", "%1 square attometer", "%1 square attometers")));

    addUnit(CustomUnit(AreaCategory,
                       SquareZeptometer,
                       1e-42,
                       i18nc("area unit symbol", "zm²"),
                       i18nc("unit description in lists", "square zeptometers"),
                       i18nc("unit synonyms for matching user input", "square zeptometer;square zeptometers;zm²;zm/-2;zm^2;zm2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square zeptometers"),
                       ki18ncp("amount in units (integer)", "%1 square zeptometer", "%1 square zeptometers")));

    addUnit(CustomUnit(AreaCategory,
                       SquareYoctometer,
                       1e-48,
                       i18nc("area unit symbol", "ym²"),
                       i18nc("unit description in lists", "square yoctometers"),
                       i18nc("unit synonyms for matching user input", "square yoctometer;square yoctometers;ym²;ym/-2;ym^2;ym2"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square yoctometers"),
                       ki18ncp("amount in units (integer)", "%1 square yoctometer", "%1 square yoctometers")));

    addCommonUnit(CustomUnit(AreaCategory,
                             Acre,
                             4046.86,
                             i18nc("area unit symbol", "acre"),
                             i18nc("unit description in lists", "acres"),
                             i18nc("unit synonyms for matching user input", "acre;acres"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 acres"),
                             ki18ncp("amount in units (integer)", "%1 acre", "%1 acres")));

    addCommonUnit(CustomUnit(AreaCategory,
                             SquareFoot,
                             0.092903,
                             i18nc("area unit symbol", "ft²"),
                             i18nc("unit description in lists", "square feet"),
                             i18nc("unit synonyms for matching user input", "square foot;square feet;ft²;square ft;sq foot;sq ft;sq feet;feet²"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 square feet"),
                             ki18ncp("amount in units (integer)", "%1 square foot", "%1 square feet")));

    addUnit(CustomUnit(AreaCategory,
                       SquareInch,
                       0.00064516,
                       i18nc("area unit symbol", "in²"),
                       i18nc("unit description in lists", "square inches"),
                       i18nc("unit synonyms for matching user input", "square inch;square inches;in²;square inch;square in;sq inches;sq inch;sq in;inch²"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 square inches"),
                       ki18ncp("amount in units (integer)", "%1 square inch", "%1 square inches")));

    addCommonUnit(CustomUnit(AreaCategory,
                             SquareMile,
                             2.58999e+06,
                             i18nc("area unit symbol", "mi²"),
                             i18nc("unit description in lists", "square miles"),
                             i18nc("unit synonyms for matching user input", "square mile;square miles;mi²;square mi;sq miles;sq mile;sq mi;mile²"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 square miles"),
                             ki18ncp("amount in units (integer)", "%1 square mile", "%1 square miles")));
}

} // KUnitConversion namespace
