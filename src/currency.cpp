/*
 *   Copyright (C) 2009 Petri Damstén <damu@iki.fi>
 *   Copyright (C) 2014 John Layt <jlayt@kde.org>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Library General Public License as
 *   published by the Free Software Foundation; either version 2, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "currency_p.h"
#include "unit_p.h"

#include <KI18n/klocalizedstring.h>

#include <QtCore/QDateTime>
#include <QtCore/QDir>
#include <QtCore/QEventLoop>
#include <QtCore/QFileInfo>
#include <QtCore/QLocale>
#include <QtCore/QMutex>
#include <QtCore/QSaveFile>
#include <QtCore/QStandardPaths>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtXml/QDomDocument>

namespace KUnitConversion
{

static const char URL[] = "http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml";

class CurrencyCategoryPrivate : public UnitCategoryPrivate
{
public:
    CurrencyCategoryPrivate(CategoryId id, const QString &name, const QString &description)
        : UnitCategoryPrivate(id, name, description),
          m_update(true)
    {
        m_cache = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation)
                  + QStringLiteral("/libkunitconversion/currency.xml");
    }

    Value convert(const Value &value, const Unit &toUnit) Q_DECL_OVERRIDE;

    QString m_cache;
    bool m_update;
};

Currency::Currency() : CustomCategory(new CurrencyCategoryPrivate(CurrencyCategory, i18n("Currency"), i18n("From ECB")))
{
    KLocalizedString symbolString = ki18nc("%1 value, %2 unit symbol (currency)", "%1 %2");

    // Static rates
    addDefaultUnit(CustomUnit(CurrencyCategory, Eur, 1.0,
                              QStringLiteral("EUR"),
                              i18nc("currency name", "Euro"),
                              i18nc("EUR Euro - unit synonyms for matching user input", "euro;euros")
                              + ";EUR;"
                              + QStringLiteral("€") + ';'
                              + i18nc("currency name", "Euro"),
                              symbolString,
                              ki18nc("amount in units (real)", "%1 euros"),
                              ki18ncp("amount in units (integer)", "%1 euro", "%1 euros")));

    addUnit(CustomUnit(CurrencyCategory, Ats, 0.0726728,
                       QStringLiteral("ATS"),
                       i18nc("currency name", "Austrian Schilling"),
                       i18nc("ATS Austrian Schilling - unit synonyms for matching user input", "schilling;schillings")
                       + ";ATS;"
                       + QLocale::countryToString(QLocale::Austria) + ';'
                       + i18nc("currency name", "Austrian Schilling"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 schillings"),
                       ki18ncp("amount in units (integer)", "%1 schilling", "%1 schillings")));

    addUnit(CustomUnit(CurrencyCategory, Bef, 0.0247894,
                       QStringLiteral("BEF"),
                       i18nc("currency name", "Belgian Franc"),
                       i18nc("BEF Belgian Franc - unit synonyms for matching user input", "franc;francs")
                       + ";BEF;"
                       + QLocale::countryToString(QLocale::Belgium) + ';'
                       + i18nc("currency name", "Belgian Franc"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Belgian francs"),
                       ki18ncp("amount in units (integer)", "%1 Belgian franc", "%1 Belgian francs")));

    addUnit(CustomUnit(CurrencyCategory, Nlg, 0.45378,
                       QStringLiteral("NLG"),
                       i18nc("currency name", "Netherlands Guilder"),
                       i18nc("NLG Netherlands Guilder - unit synonyms for matching user input", "guilder;guilders")
                       + ";NLG;"
                       + QLocale::countryToString(QLocale::Netherlands) + ';'
                       + i18nc("currency name", "Netherlands Guilder"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 guilders"),
                       ki18ncp("amount in units (integer)", "%1 guilder", "%1 guilders")));

    addUnit(CustomUnit(CurrencyCategory, Fim, 0.168188,
                       QStringLiteral("FIM"),
                       i18nc("currency name", "Finnish Markka"),
                       i18nc("FIM Finnish Markka - unit synonyms for matching user input", "markka;markkas;markkaa")
                       + ";FIM;"
                       + QLocale::countryToString(QLocale::Finland) + ';'
                       + i18nc("currency name", "Finnish Markka"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 markkas"),
                       ki18ncp("amount in units (integer)", "%1 markka", "%1 markkas")));  // Alternative = markkaa

    addUnit(CustomUnit(CurrencyCategory, Frf, 0.152449,
                       QStringLiteral("FRF"),
                       i18nc("currency name", "French Franc"),
                       i18nc("FRF French Franc - unit synonyms for matching user input", "franc;francs")
                       + ";FRF;"
                       + QLocale::countryToString(QLocale::France) + ';'
                       + i18nc("currency name", "French Franc"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 French francs"),
                       ki18ncp("amount in units (integer)", "%1 French franc", "%1 French francs")));

    addUnit(CustomUnit(CurrencyCategory, Dem, 0.511292,
                       QStringLiteral("DEM"),
                       i18nc("currency name", "German Mark"),
                       i18nc("DEM German Mark - unit synonyms for matching user input", "mark;marks")
                       + ";DEM;"
                       + QLocale::countryToString(QLocale::Germany) + ';'
                       + i18nc("currency name", "German Mark"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 marks"),
                       ki18ncp("amount in units (integer)", "%1 mark", "%1 marks")));

    addUnit(CustomUnit(CurrencyCategory, Iep, 1.26974,
                       QStringLiteral("IEP"),
                       i18nc("currency name", "Irish Pound"),
                       i18nc("IEP Irish Pound - unit synonyms for matching user input", "Irish pound;Irish pounds")
                       + ";IEP;"
                       + QLocale::countryToString(QLocale::Ireland) + ';'
                       + i18nc("currency name", "Irish Pound"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Irish pounds"),
                       ki18ncp("amount in units (integer)", "%1 Irish pound", "%1 Irish pounds")));

    addUnit(CustomUnit(CurrencyCategory, Itl, 0.000516457,
                       QStringLiteral("ITL"),
                       i18nc("currency name", "Italian Lira"),
                       i18nc("ITL Italian Lira - unit synonyms for matching user input", "lira;liras")
                       + ";ITL;"
                       + QLocale::countryToString(QLocale::Italy) + ';'
                       + i18nc("currency name", "Italian Lira"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Italian lira"),
                       ki18ncp("amount in units (integer)", "%1 Italian lira", "%1 Italian lira")));

    addUnit(CustomUnit(CurrencyCategory, Luf, 0.0247894,
                       QStringLiteral("LUF"),
                       i18nc("currency name", "Luxembourgish Franc"),
                       i18nc("LUF Luxembourgish Franc - unit synonyms for matching user input", "franc;francs")
                       + ";LUF;"
                       + QLocale::countryToString(QLocale::Luxembourg) + ';'
                       + i18nc("currency name", "Luxembourgish Franc"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Luxembourgish francs"),
                       ki18ncp("amount in units (integer)", "%1 Luxembourgish franc", "%1 Luxembourgish francs")));

    addUnit(CustomUnit(CurrencyCategory, Pte, 0.00498798,
                       QStringLiteral("PTE"),
                       i18nc("currency name", "Portuguese Escudo"),
                       i18nc("PTE Portuguese Escudo - unit synonyms for matching user input", "escudo;escudos")
                       + ";PTE;"
                       + QLocale::countryToString(QLocale::Portugal) + ';'
                       + i18nc("currency name", "Portuguese Escudo"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 escudos"),
                       ki18ncp("amount in units (integer)", "%1 escudo", "%1 escudos")));

    addUnit(CustomUnit(CurrencyCategory, Esp, 0.00601012,
                       QStringLiteral("ESP"),
                       i18nc("currency name", "Spanish Peseta"),
                       i18nc("ESP Spanish Peseta - unit synonyms for matching user input", "peseta;pesetas")
                       + ";ESP;"
                       + QLocale::countryToString(QLocale::Spain) + ';'
                       + i18nc("currency name", "Spanish Peseta"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 pesetas"),
                       ki18ncp("amount in units (integer)", "%1 peseta", "%1 pesetas")));

    addUnit(CustomUnit(CurrencyCategory, Grd, 0.0029347,
                       QStringLiteral("GRD"),
                       i18nc("currency name", "Greek Drachma"),
                       i18nc("GRD Greek Drachma - unit synonyms for matching user input", "drachma;drachmas")
                       + ";GRD;"
                       + QLocale::countryToString(QLocale::Greece) + ';'
                       + i18nc("currency name", "Greek Drachma"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 drachmas"),
                       ki18ncp("amount in units (integer)", "%1 drachma", "%1 drachmas")));

    addUnit(CustomUnit(CurrencyCategory, Sit, 0.00417293,
                       QStringLiteral("SIT"),
                       i18nc("currency name", "Slovenian Tolar"),
                       i18nc("SIT Slovenian Tolar - unit synonyms for matching user input", "tolar;tolars;tolarjev")
                       + ";SIT;"
                       + QLocale::countryToString(QLocale::Slovenia) +  ';'
                       + i18nc("currency name", "Slovenian Tolar"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 tolars"),
                       ki18ncp("amount in units (integer)", "%1 tolar", "%1 tolars")));  //Alt: tolarjev/tolarja/tolarji

    addUnit(CustomUnit(CurrencyCategory, Cyp, 1.7086,
                       QStringLiteral("CYP"),
                       i18nc("currency name", "Cypriot Pound"),
                       i18nc("CYP Cypriot Pound - unit synonyms for matching user input",
                             "Cypriot pound;Cypriot pounds")
                       + ";CYP;"
                       + QLocale::countryToString(QLocale::Cyprus) + ';'
                       + i18nc("currency name", "Cypriot Pound"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Cypriot pounds"),
                       ki18ncp("amount in units (integer)", "%1 Cypriot pound", "%1 Cypriot pounds")));

    addUnit(CustomUnit(CurrencyCategory, Mtl, 2.32937,
                       QStringLiteral("MTL"),
                       i18nc("currency name", "Maltese Lira"),
                       i18nc("MTL Maltese Lira - unit synonyms for matching user input", "Maltese lira")
                       + ";MTL;"
                       + QLocale::countryToString(QLocale::Malta) + ';'
                       + i18nc("currency name", "Maltese Lira"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Maltese lira"),
                       ki18ncp("amount in units (integer)", "%1 Maltese lira", "%1 Maltese lira")));

    addUnit(CustomUnit(CurrencyCategory, Skk, 0.0331939,
                       QStringLiteral("SKK"),
                       i18nc("currency name", "Slovak Koruna"),
                       i18nc("SKK Slovak Koruna - unit synonyms for matching user input",
                             "koruna;korunas;koruny;korun")
                       + ";SKK;"
                       + QLocale::countryToString(QLocale::Slovakia) + ';'
                       + i18nc("currency name", "Slovak Koruna"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Slovak korunas"),
                       ki18ncp("amount in units (integer)", "%1 Slovak koruna", "%1 Slovak korunas"))); // Alt: koruny, korun


    // From ECB
    addCommonUnit(CustomUnit(CurrencyCategory, Usd, qSNaN(),
                             QStringLiteral("USD"),
                             i18nc("currency name", "United States Dollar"),
                             i18nc("USD United States Dollar - unit synonyms for matching user input", "dollar;dollars")
                             + ";USD;$;"
                             + QLocale::countryToString(QLocale::UnitedStates) + ';'
                             + i18nc("currency name", "United States Dollar"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 United States dollars"),
                             ki18ncp("amount in units (integer)", "%1 United States dollar", "%1 United States dollars")));

    addCommonUnit(CustomUnit(CurrencyCategory, Jpy, qSNaN(),
                             QStringLiteral("JPY"),
                             i18nc("currency name", "Japanese Yen"),
                             i18nc("JPY Japanese Yen - unit synonyms for matching user input", "yen")
                             + ";JPY;"
                             + QStringLiteral("¥") + ';'
                             + QLocale::countryToString(QLocale::Japan) + ';'
                             + i18nc("currency name", "Japanese Yen"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 yen"),
                             ki18ncp("amount in units (integer)", "%1 yen", "%1 yen")));

    addUnit(CustomUnit(CurrencyCategory, Bgn, qSNaN(),
                       QStringLiteral("BGN"),
                       i18nc("currency name", "Bulgarian Lev"),
                       i18nc("BGN Bulgarian Lev - unit synonyms for matching user input", "lev;leva")
                       + ";BGN;"
                       + QLocale::countryToString(QLocale::Bulgaria) + ';'
                       + i18nc("currency name", "Bulgarian Lev"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 leva"),
                       ki18ncp("amount in units (integer)", "%1 lev", "%1 leva")));

    addUnit(CustomUnit(CurrencyCategory, Czk, qSNaN(),
                       QStringLiteral("CZK"),
                       i18nc("currency name", "Czech Koruna"),
                       i18nc("CZK Czech Koruna - unit synonyms for matching user input", "koruna;korunas")
                       + ";CZK;"
                       + QLocale::countryToString(QLocale::CzechRepublic) + ';'
                       + i18nc("currency name", "Czech Koruna"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Czech korunas"),
                       // Alt: koruny, korun
                       ki18ncp("amount in units (integer)", "%1 Czech koruna", "%1 Czech korunas")));

    addUnit(CustomUnit(CurrencyCategory, Dkk, qSNaN(),
                       QStringLiteral("DKK"),
                       i18nc("currency name", "Danish Krone"),
                       i18nc("DKK Danish Krone - unit synonyms for matching user input", "Danish krone;Danish kroner")
                       + ";DKK;"
                       + QLocale::countryToString(QLocale::Denmark) + ';'
                       + i18nc("currency name", "Danish Krone"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Danish kroner"),
                       ki18ncp("amount in units (integer)", "%1 Danish krone", "%1 Danish kroner")));

    addUnit(CustomUnit(CurrencyCategory, Eek, qSNaN(),
                       QStringLiteral("EEK"),
                       i18nc("currency name", "Estonian Kroon"),
                       i18nc("EEK Estonian Kroon - unit synonyms for matching user input", "kroon;kroons;krooni")
                       + ";EEK;"
                       + QLocale::countryToString(QLocale::Estonia) + ';'
                       + i18nc("currency name", "Estonian Kroon"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 kroons"),
                       ki18ncp("amount in units (integer)", "%1 kroon", "%1 kroons"))); // Alt: krooni

    addCommonUnit(CustomUnit(CurrencyCategory, Gbp, qSNaN(),
                             QStringLiteral("GBP"),
                             i18nc("currency name", "British Pound"),
                             i18nc("GBP British Pound - unit synonyms for matching user input",
                                   "pound;pounds;pound sterling;pounds sterling")
                             + ";GBP;"
                             + QStringLiteral("£") + ';'
                             + QLocale::countryToString(QLocale::UnitedKingdom) + ';'
                             + i18nc("currency name", "British Pound"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 pounds sterling"),
                             ki18ncp("amount in units (integer)", "%1 pound sterling", "%1 pounds sterling")));

    addUnit(CustomUnit(CurrencyCategory, Huf, qSNaN(),
                       QStringLiteral("HUF"),
                       i18nc("currency name", "Hungarian Forint"),
                       i18nc("HUF hungarian Forint - unit synonyms for matching user input", "forint")
                       + ";HUF;"
                       + QLocale::countryToString(QLocale::Hungary) + ';'
                       + i18nc("currency name", "Hungarian Forint"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 forint"),
                       ki18ncp("amount in units (integer)", "%1 forint", "%1 forint")));

    addUnit(CustomUnit(CurrencyCategory, Ils, qSNaN(),
                       QStringLiteral("ILS"),
                       i18nc("currency name", "Israeli New Shekel"),
                       i18nc("ILS Israeli New Shekel - unit synonyms for matching user input", "shekel;shekels;sheqel;sheqels;sheqalim")
                       + ";ILS;"
                       + QLocale::countryToString(QLocale::Israel) + ';'
                       + i18nc("currency name", "Israeli New Shekel"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 shekels"),
                       ki18ncp("amount in units (integer)", "%1 shekel", "%1 shekels")));

    addUnit(CustomUnit(CurrencyCategory, Ltl, qSNaN(),
                       QStringLiteral("LTL"),
                       i18nc("currency name", "Lithuanian Litas"),
                       i18nc("LTL Lithuanian Litas - unit synonyms for matching user input", "litas;litai;litu")
                       + ";LTL;"
                       + QLocale::countryToString(QLocale::Lithuania) + ';'
                       + i18nc("currency name", "Lithuanian Litas"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 litas"),
                       ki18ncp("amount in units (integer)", "%1 litas", "%1 litai"))); // Alt: litu

    addUnit(CustomUnit(CurrencyCategory, Lvl, qSNaN(),
                       QStringLiteral("LVL"),
                       i18nc("currency name", "Latvian Lats"),
                       i18nc("LVL Latvian Lats - unit synonyms for matching user input", "lats;lati")
                       + ";LVL;"
                       + QLocale::countryToString(QLocale::Latvia) + ';'
                       + i18nc("currency name", "Latvian Lats"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 lati"),
                       ki18ncp("amount in units (integer)", "%1 lats", "%1 lati")));

    addUnit(CustomUnit(CurrencyCategory, Pln, qSNaN(),
                       QStringLiteral("PLN"),
                       i18nc("currency name", "Polish Zloty"),
                       i18nc("PLN Polish Zloty - unit synonyms for matching user input", "zloty;zlotys;zloties")
                       + ";PLN;"
                       + QLocale::countryToString(QLocale::Poland) + ';'
                       + i18nc("currency name", "Polish Zloty"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 zlotys"),
                       ki18ncp("amount in units (integer)", "%1 zloty", "%1 zlotys"))); // Alt: zloty, zlote, zlotych

    addUnit(CustomUnit(CurrencyCategory, Ron, qSNaN(),
                       QStringLiteral("RON"),
                       i18nc("currency name", "Romanian Leu"),
                       i18nc("RON Romanian Leu - unit synonyms for matching user input", "leu;lei")
                       + ";RON;"
                       + QLocale::countryToString(QLocale::Romania) + ';'
                       + i18nc("currency name", "Romanian Leu"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 lei"),
                       ki18ncp("amount in units (integer)", "%1 leu", "%1 lei")));

    addUnit(CustomUnit(CurrencyCategory, Sek, qSNaN(),
                       QStringLiteral("SEK"),
                       i18nc("currency name", "Swedish Krona"),
                       i18nc("SEK Swedish Krona - unit synonyms for matching user input", "krona;kronor")
                       + ";SEK;"
                       + QLocale::countryToString(QLocale::Sweden) + ';'
                       + i18nc("currency name", "Swedish Krona"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 kronor"),
                       ki18ncp("amount in units (integer)", "%1 krona", "%1 kronor")));

    addUnit(CustomUnit(CurrencyCategory, Chf, qSNaN(),
                       QStringLiteral("CHF"),
                       i18nc("currency name", "Swiss Franc"),
                       i18nc("CHF Swiss Franc - unit synonyms for matching user input", "franc;francs")
                       + ";CHF;"
                       + QLocale::countryToString(QLocale::Switzerland) + ';'
                       + i18nc("currency name", "Swiss Franc"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Swiss francs"),
                       ki18ncp("amount in units (integer)", "%1 Swiss franc", "%1 Swiss francs")));

    addUnit(CustomUnit(CurrencyCategory, Nok, qSNaN(),
                       QStringLiteral("NOK"),
                       i18nc("currency name", "Norwegian Krone"),
                       i18nc("Norwegian Krone - unit synonyms for matching user input",
                             "Norwegian krone;Norwegian kroner")
                       + ";NOK;"
                       + QLocale::countryToString(QLocale::Norway) + ';'
                       + i18nc("currency name", "Norwegian Krone"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Norwegian kroner"),
                       ki18ncp("amount in units (integer)", "%1 Norwegian krone", "%1 Norwegian kroner")));

    addUnit(CustomUnit(CurrencyCategory, Hrk, qSNaN(),
                       QStringLiteral("HRK"),
                       i18nc("currency name", "Croatian Kuna"),
                       i18nc("HRK Croatian Kuna - unit synonyms for matching user input", "kuna;kune")
                       + ";HRK;"
                       + QLocale::countryToString(QLocale::Croatia) + ';'
                       + i18nc("currency name", "Croatian Kuna"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 kune"),
                       ki18ncp("amount in units (integer)", "%1 kuna", "%1 kune")));

    addUnit(CustomUnit(CurrencyCategory, Rub, qSNaN(),
                       QStringLiteral("RUB"),
                       i18nc("currency name", "Russian Ruble"),
                       i18nc("RUB Russian Ruble - unit synonyms for matching user input",
                             "ruble;rubles;rouble;roubles")
                       + ";RUB;"
                       + QLocale::countryToString(QLocale::Russia) + ';'
                       + i18nc("currency name", "Russian Ruble"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 rubles"),
                       ki18ncp("amount in units (integer)", "%1 ruble", "%1 rubles"))); //Alt: rouble/roubles

    addUnit(CustomUnit(CurrencyCategory, Try, qSNaN(),
                       QStringLiteral("TRY"),
                       i18nc("currency name", "Turkish Lira"),
                       i18nc("TRY Turkish Lira - unit synonyms for matching user input", "lira")
                       + ";TRY;"
                       + QLocale::countryToString(QLocale::Turkey) + ';'
                       + i18nc("currency name", "Turkish Lira"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Turkish lira"),
                       ki18ncp("amount in units (integer)", "%1 Turkish lira", "%1 Turkish lira")));

    addUnit(CustomUnit(CurrencyCategory, Aud, qSNaN(),
                       QStringLiteral("AUD"),
                       i18nc("currency name", "Australian Dollar"),
                       i18nc("AUD Australian Dollar - unit synonyms for matching user input",
                             "Australian dollar;Australian dollars")
                       + ";AUD;"
                       + QLocale::countryToString(QLocale::Australia) + ';'
                       + i18nc("currency name", "Australian Dollar"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Australian dollars"),
                       ki18ncp("amount in units (integer)", "%1 Australian dollar", "%1 Australian dollars")));

    addUnit(CustomUnit(CurrencyCategory, Brl, qSNaN(),
                       QStringLiteral("BRL"),
                       i18nc("currency name", "Brazilian Real"),
                       i18nc("BRL Brazilian Real - unit synonyms for matching user input", "real;reais")
                       + ";BRL;"
                       + QLocale::countryToString(QLocale::Brazil) + ';'
                       + i18nc("currency name", "Brazilian Real"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 reais"),
                       ki18ncp("amount in units (integer)", "%1 real", "%1 reais")));

    addCommonUnit(CustomUnit(CurrencyCategory, Cad, qSNaN(),
                             QStringLiteral("CAD"),
                             i18nc("currency name", "Canadian Dollar"),
                             i18nc("Canadian Dollar - unit synonyms for matching user input",
                                   "Canadian dollar;Canadian dollars")
                             + ";CAD;"
                             + QLocale::countryToString(QLocale::Canada) + ';'
                             + i18nc("currency name", "Canadian Dollar"),
                             symbolString,
                             ki18nc("amount in units (real)", "%1 Canadian dollars"),
                             ki18ncp("amount in units (integer)", "%1 Canadian dollar", "%1 Canadian dollars")));

    addUnit(CustomUnit(CurrencyCategory, Cny, qSNaN(),
                       QStringLiteral("CNY"),
                       i18nc("currency name", "Chinese Yuan"),
                       i18nc("Chinese Yuan - unit synonyms for matching user input", "yuan")
                       + ";CNY;"
                       + QLocale::countryToString(QLocale::China) + ';'
                       + i18nc("currency name", "Chinese Yuan"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 yuan"),
                       ki18ncp("amount in units (integer)", "%1 yuan", "%1 yuan")));

    addUnit(CustomUnit(CurrencyCategory, Hkd, qSNaN(),
                       QStringLiteral("HKD"),
                       i18nc("currency name", "Hong Kong Dollar"),
                       i18nc("Hong Kong Dollar - unit synonyms for matching user input",
                             "Hong Kong dollar;Hong Kong dollars")
                       + ";HKD;"
                       + QLocale::countryToString(QLocale::HongKong) + ';'
                       + i18nc("currency name", "Hong Kong Dollar"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Hong Kong dollars"),
                       ki18ncp("amount in units (integer)", "%1 Hong Kong dollar", "%1 Hong Kong dollars")));

    addUnit(CustomUnit(CurrencyCategory, Idr, qSNaN(),
                       QStringLiteral("IDR"),
                       i18nc("currency name", "Indonesian Rupiah"),
                       i18nc("IDR Indonesian Rupiah - unit synonyms for matching user input", "rupiah;rupiahs") +
                       + ";IDR;"
                       + QLocale::countryToString(QLocale::Indonesia) + ';'
                       + i18nc("currency name", "Indonesian Rupiah"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 rupiahs"),
                       ki18ncp("amount in units (integer)", "%1 rupiah", "%1 rupiahs"))); // Alt: rupiah

    addUnit(CustomUnit(CurrencyCategory, Inr, qSNaN(),
                       QStringLiteral("INR"),
                       i18nc("currency name", "Indian Rupee"),
                       i18nc("INR Indian Rupee - unit synonyms for matching user input", "rupee;rupees")
                       + ";INR;"
                       + QLocale::countryToString(QLocale::India) + ';'
                       + i18nc("currency name", "Indian Rupee"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 rupees"),
                       ki18ncp("amount in units (integer)", "%1 rupee", "%1 rupees"))); // Alt: rupee

    addUnit(CustomUnit(CurrencyCategory, Krw, qSNaN(),
                       QStringLiteral("KRW"),
                       i18nc("currency name", "Korean Won"),
                       i18nc("KRW Korean Won - unit synonyms for matching user input", "won")
                       + ";KRW;"
                       + QLocale::countryToString(QLocale::SouthKorea) + ';'
                       + i18nc("currency name", "Korean Won"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 won"),
                       ki18ncp("amount in units (integer)", "%1 won", "%1 won")));

    addUnit(CustomUnit(CurrencyCategory, Mxn, qSNaN(),
                       QStringLiteral("MXN"),
                       i18nc("currency name", "Mexican Peso"),
                       i18nc("MXN Mexican Peso - unit synonyms for matching user input",
                             "Mexican peso;Mexican pesos")
                       + ";MXN;"
                       + QLocale::countryToString(QLocale::Mexico) + ';'
                       + i18nc("currency name", "Mexican Peso"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Mexican pesos"),
                       ki18ncp("amount in units (integer)", "%1 Mexican peso", "%1 Mexican pesos")));

    addUnit(CustomUnit(CurrencyCategory, Myr, qSNaN(),
                       QStringLiteral("MYR"),
                       i18nc("currency name", "Malaysian Ringgit"),
                       i18nc("MYR Malaysian Ringgit - unit synonyms for matching user input", "ringgit;ringgits")
                       + ";MYR;"
                       + QLocale::countryToString(QLocale::Malaysia) + ';'
                       + i18nc("currency name", "Malaysian Ringgit"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 ringgit"),
                       ki18ncp("amount in units (integer)", "%1 ringgit", "%1 ringgit"))); // Alt: ringgits

    addUnit(CustomUnit(CurrencyCategory, Nzd, qSNaN(),
                       QStringLiteral("NZD"),
                       i18nc("currency name", "New Zealand Dollar"),
                       i18nc("NZD New Zealand Dollar - unit synonyms for matching user input",
                             "New Zealand dollar;New Zealand dollars")
                       + ";NZD;"
                       + QLocale::countryToString(QLocale::NewZealand) + ';'
                       + i18nc("currency name", "New Zealand Dollar"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 New Zealand dollars"),
                       ki18ncp("amount in units (integer)", "%1 New Zealand dollar", "%1 New Zealand dollars")));

    addUnit(CustomUnit(CurrencyCategory, Php, qSNaN(),
                       QStringLiteral("PHP"),
                       i18nc("currency name", "Philippine Peso"),
                       i18nc("PHP Philippine Peso - unit synonyms for matching user input",
                             "Philippine peso;Philippine pesos")
                       + ";PHP;"
                       + QLocale::countryToString(QLocale::Philippines) + ';'
                       + i18nc("currency name", "Philippine Peso"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Philippine pesos"),
                       ki18ncp("amount in units (integer)", "%1 Philippine peso", "%1 Philippine pesos")));

    addUnit(CustomUnit(CurrencyCategory, Sgd, qSNaN(),
                       QStringLiteral("SGD"),
                       i18nc("currency name", "Singapore Dollar"),
                       i18nc("SGD Singapore Dollar - unit synonyms for matching user input",
                             "Singapore dollar;Singapore dollars")
                       + ";SGD;"
                       + QLocale::countryToString(QLocale::Singapore) + ';'
                       + i18nc("currency name", "Singapore Dollar"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 Singapore dollars"),
                       ki18ncp("amount in units (integer)", "%1 Singapore dollar", "%1 Singapore dollars")));

    addUnit(CustomUnit(CurrencyCategory, Thb, qSNaN(),
                       QStringLiteral("THB"),
                       i18nc("currency name", "Thai Baht"),
                       i18nc("THB Thai Baht - unit synonyms for matching user input", "baht")
                       + ";THB;"
                       + QLocale::countryToString(QLocale::Thailand) + ';'
                       + i18nc("currency name", "Thai Baht"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 baht"),
                       ki18ncp("amount in units (integer)", "%1 baht", "%1 baht")));

    addUnit(CustomUnit(CurrencyCategory, Zar, qSNaN(),
                       QStringLiteral("ZAR"),
                       i18nc("currency name", "South African Rand"),
                       i18nc("South African Rand - unit synonyms for matching user input", "rand")
                       + ";ZAR;"
                       + QLocale::countryToString(QLocale::SouthAfrica) + ';'
                       + i18nc("currency name", "South African Rand"),
                       symbolString,
                       ki18nc("amount in units (real)", "%1 rand"),
                       ki18ncp("amount in units (integer)", "%1 rand", "%1 rand")));
}

static bool isConnected()
{
    //don't download currencies in autotests
    if (qEnvironmentVariableIsSet("KF5UNITCONVERT_NO_DOWNLOAD")) {
        return false;
    }
    bool ret = false;
    foreach (const QNetworkInterface &net, QNetworkInterface::allInterfaces()) {
        if (net.flags().testFlag(QNetworkInterface::IsUp) && !net.flags().testFlag(QNetworkInterface::IsLoopBack)) {
            ret = true;
            break;
        }
    }
    return ret;
}

Value CurrencyCategoryPrivate::convert(const Value &value, const Unit &to)
{
    static QMutex mutex;

    QFileInfo info(m_cache);
    if (!info.exists() || info.lastModified().secsTo(QDateTime::currentDateTime()) > 86400) {
        if (isConnected()) {
            // Bug 345750: QNetworkReply does not work without an event loop and doesn't implement waitForReadyRead()
            QEventLoop loop;
            QNetworkAccessManager manager;
            auto *reply = manager.get(QNetworkRequest(QUrl(URL))); // reply is owned by the network access manager
            QObject::connect(reply, &QNetworkReply::finished, [&] {
                if (!reply->error()) {
                    const QString cacheDir = info.absolutePath();
                    if (!QFileInfo::exists(cacheDir)) {
                        QDir().mkpath(cacheDir);
                    }

                    QSaveFile cacheFile(m_cache);
                    if (cacheFile.open(QFile::WriteOnly)) {
                        cacheFile.write(reply->readAll());

                        if (cacheFile.commit()) {
                            mutex.lock();
                            m_update = true;
                            mutex.unlock();
                        }
                    }
                }

                loop.quit();
            });
            loop.exec(QEventLoop::ExcludeUserInputEvents);
        }
    }

    mutex.lock();

    if (m_update) {
        QFile file(m_cache);
        if (file.open(QIODevice::ReadOnly)) {
            QDomDocument doc;
            if (doc.setContent(&file, false)) {
                QDomNodeList list = doc.elementsByTagName(QStringLiteral("Cube"));
                for (int i = 0; i < list.count(); ++i) {
                    const QDomElement e = list.item(i).toElement();
                    if (e.hasAttribute(QStringLiteral("currency"))) {
                        Unit u = m_unitMap.value(e.attribute(QStringLiteral("currency")));
                        if (u.isValid()) {
                            u.setUnitMultiplier(1.0 / e.attribute(QStringLiteral("rate")).toDouble());
                        }
                    }
                }
                m_update = false;
            }
        }
    }
    mutex.unlock();

    Value v = UnitCategoryPrivate::convert(value, to);
    return v;
}

} // KUnitConversion namespace
