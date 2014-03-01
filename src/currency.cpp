/*
 *   Copyright (C) 2009 Petri Damstén <damu@iki.fi>
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

#include "converter.h"
#include <QLocale>
#include <QtCore/QFileInfo>
#include <QtCore/QDateTime>
#include <QtCore/QMutex>
#include <QtCore/QProcess>
#include <QtXml/QDomDocument>
#include <QDebug>
#include <klocalizedstring.h>

#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

#include <kcurrencycode.h>
#include <qstandardpaths.h>

using namespace KUnitConversion;

static const char URL[] = "http://www.ecb.europa.eu/stats/eurofxref/eurofxref-daily.xml";

Currency::Currency() : UnitCategory(CurrencyCategory)
{
    setName(i18n("Currency"));
    setDescription(i18n("From ECB"));
    setSymbolStringFormat(ki18nc("%1 value, %2 unit symbol (currency)", "%1 %2"));

    // Static rates
    setDefaultUnit(Unit(*this, Eur, 1,
                        "EUR",
                        i18nc("currency name", "Euro"),
                        i18nc("EUR Euro - unit synonyms for matching user input", "euro;euros") +
                        ";EUR;" + QString::fromUtf8("€") + ';' + i18nc("currency name", "Euro"),
                        ki18nc("amount in units (real)", "%1 euros"),
                        ki18ncp("amount in units (integer)", "%1 euro", "%1 euros")
                        ));
    U(Ats, 0.0726728,
      "ATS",
      i18nc("currency name", "Austrian Schilling"),
      i18nc("ATS Austrian Schilling - unit synonyms for matching user input",
            "schilling;schillings") + ";ATS;" + QLocale::countryToString(QLocale::Austria) + ';' +
      i18nc("currency name", "Austrian Schilling"),
      ki18nc("amount in units (real)", "%1 schillings"),
      ki18ncp("amount in units (integer)", "%1 schilling", "%1 schillings")
     );
    U(Bef, 0.0247894,
      "BEF",
      i18nc("currency name", "Belgian Franc"),
      i18nc("BEF Belgian Franc - unit synonyms for matching user input", "franc;francs") +
      ";BEF;" + QLocale::countryToString(QLocale::Belgium) + ';' +
      i18nc("currency name", "Belgian Franc"),
      ki18nc("amount in units (real)", "%1 Belgian francs"),
      ki18ncp("amount in units (integer)", "%1 Belgian franc", "%1 Belgian francs")
     );
    U(Nlg, 0.45378,
      "NLG",
      i18nc("currency name", "Netherlands Guilder"),
      i18nc("NLG Netherlands Guilder - unit synonyms for matching user input", "guilder;guilders") +
      ";NLG;" + QLocale::countryToString(QLocale::Netherlands) + ';' +
      i18nc("currency name", "Netherlands Guilder"),
      ki18nc("amount in units (real)", "%1 guilders"),
      ki18ncp("amount in units (integer)", "%1 guilder", "%1 guilders")
     );
    U(Fim, 0.168188,
      "FIM",
      i18nc("currency name", "Finnish Markka"),
      i18nc("FIM Finnish Markka - unit synonyms for matching user input",
            "markka;markkas;markkaa") + ";FIM;" +
      QLocale::countryToString(QLocale::Finland) + ';' +
      i18nc("currency name", "Finnish Markka"),
      ki18nc("amount in units (real)", "%1 markkas"),
      ki18ncp("amount in units (integer)", "%1 markka", "%1 markkas")  // Alternative = markkaa
     );
    U(Frf, 0.152449,
      "FRF",
      i18nc("currency name", "French Franc"),
      i18nc("FRF French Franc - unit synonyms for matching user input", "franc;francs") + ";FRF;" +
      QLocale::countryToString(QLocale::France) + ';' +
      i18nc("currency name", "French Franc"),
      ki18nc("amount in units (real)", "%1 French francs"),
      ki18ncp("amount in units (integer)", "%1 French franc", "%1 French francs")
     );
    U(Dem, 0.511292,
      "DEM",
      i18nc("currency name", "German Mark"),
      i18nc("DEM German Mark - unit synonyms for matching user input", "mark;marks") + ";DEM;" +
      QLocale::countryToString(QLocale::Germany) + ';' +
      i18nc("currency name", "German Mark"),
      ki18nc("amount in units (real)", "%1 marks"),
      ki18ncp("amount in units (integer)", "%1 mark", "%1 marks")
     );
    U(Iep, 1.26974,
      "IEP",
      i18nc("currency name", "Irish Pound"),
      i18nc("IEP Irish Pound - unit synonyms for matching user input", "Irish pound;Irish pounds") +
      ";IEP;" + QLocale::countryToString(QLocale::Ireland) + ';' +
      i18nc("currency name", "Irish Pound"),
      ki18nc("amount in units (real)", "%1 Irish pounds"),
      ki18ncp("amount in units (integer)", "%1 Irish pound", "%1 Irish pounds")
     );
    U(Itl, 0.000516457,
      "ITL",
      i18nc("currency name", "Italian Lira"),
      i18nc("ITL Italian Lira - unit synonyms for matching user input", "lira;liras") + ";ITL;" +
      QLocale::countryToString(QLocale::Italy) + ';' +
      i18nc("currency name", "Italian Lira"),
      ki18nc("amount in units (real)", "%1 Italian lira"),
      ki18ncp("amount in units (integer)", "%1 Italian lira", "%1 Italian lira")
     );
    U(Luf, 0.0247894,
      "LUF",
      i18nc("currency name", "Luxembourgish Franc"),
      i18nc("LUF Luxembourgish Franc - unit synonyms for matching user input", "franc;francs") +
      ";LUF;" + QLocale::countryToString(QLocale::Luxembourg) + ';' +
      i18nc("currency name", "Luxembourgish Franc"),
      ki18nc("amount in units (real)", "%1 Luxembourgish francs"),
      ki18ncp("amount in units (integer)", "%1 Luxembourgish franc", "%1 Luxembourgish francs")
     );
    U(Pte, 0.00498798,
      "PTE",
      i18nc("currency name", "Portuguese Escudo"),
      i18nc("PTE Portuguese Escudo - unit synonyms for matching user input", "escudo;escudos") +
      ";PTE;" + QLocale::countryToString(QLocale::Portugal) + ';' +
      i18nc("currency name", "Portuguese Escudo"),
      ki18nc("amount in units (real)", "%1 escudos"),
      ki18ncp("amount in units (integer)", "%1 escudo", "%1 escudos")
     );
    U(Esp, 0.00601012,
      "ESP",
      i18nc("currency name", "Spanish Peseta"),
      i18nc("ESP Spanish Peseta - unit synonyms for matching user input", "peseta;pesetas") +
      ";ESP;" + QLocale::countryToString(QLocale::Spain) + ';' +
      i18nc("currency name", "Spanish Peseta"),
      ki18nc("amount in units (real)", "%1 pesetas"),
      ki18ncp("amount in units (integer)", "%1 peseta", "%1 pesetas")
     );
    U(Grd, 0.0029347,
      "GRD",
      i18nc("currency name", "Greek Drachma"),
      i18nc("GRD Greek Drachma - unit synonyms for matching user input", "drachma;drachmas") +
      ";GRD;" + QLocale::countryToString(QLocale::Greece) + ';' +
      i18nc("currency name", "Greek Drachma"),
      ki18nc("amount in units (real)", "%1 drachmas"),
      ki18ncp("amount in units (integer)", "%1 drachma", "%1 drachmas")
     );
    U(Sit, 0.00417293,
      "SIT",
      i18nc("currency name", "Slovenian Tolar"),
      i18nc("SIT Slovenian Tolar - unit synonyms for matching user input", "tolar;tolars;tolarjev") + ";SIT;" +
      QLocale::countryToString(QLocale::Slovenia) + ';' + i18nc("currency name", "Slovenian Tolar"),
      ki18nc("amount in units (real)", "%1 tolars"),
      ki18ncp("amount in units (integer)", "%1 tolar", "%1 tolars")  //Alt: tolarjev/tolarja/tolarji
     );
    U(Cyp, 1.7086,
      "CYP",
      i18nc("currency name", "Cypriot Pound"),
      i18nc("CYP Cypriot Pound - unit synonyms for matching user input",
            "Cypriot pound;Cypriot pounds") + ";CYP;" +
      QLocale::countryToString(QLocale::Cyprus) + ';' +
      i18nc("currency name", "Cypriot Pound"),
      ki18nc("amount in units (real)", "%1 Cypriot pounds"),
      ki18ncp("amount in units (integer)", "%1 Cypriot pound", "%1 Cypriot pounds")
     );
    U(Mtl, 2.32937,
      "MTL",
      i18nc("currency name", "Maltese Lira"),
      i18nc("MTL Maltese Lira - unit synonyms for matching user input", "Maltese lira") + ";MTL;" +
      QLocale::countryToString(QLocale::Malta) + ';' + i18nc("currency name", "Maltese Lira"),
      ki18nc("amount in units (real)", "%1 Maltese lira"),
      ki18ncp("amount in units (integer)", "%1 Maltese lira", "%1 Maltese lira")
     );
    U(Skk, 0.0331939,
      "SKK",
      i18nc("currency name", "Slovak Koruna"),
      i18nc("SKK Slovak Koruna - unit synonyms for matching user input",
            "koruna;korunas;koruny;korun") + ";SKK;" +
      QLocale::countryToString(QLocale::Slovakia) + ';' +
      i18nc("currency name", "Slovak Koruna"),
      ki18nc("amount in units (real)", "%1 Slovak korunas"),
      ki18ncp("amount in units (integer)", "%1 Slovak koruna", "%1 Slovak korunas") // Alt: koruny, korun
     );

    // From ECB
    U(Usd, 1e+99,
      "USD",
      i18nc("currency name", "United States Dollar"),
      i18nc("USD United States Dollar - unit synonyms for matching user input", "dollar;dollars") +
      ";USD;$;" + QLocale::countryToString(QLocale::UnitedStates) + ';' +
      i18nc("currency name", "United States Dollar"),
      ki18nc("amount in units (real)", "%1 United States dollars"),
      ki18ncp("amount in units (integer)", "%1 United States dollar", "%1 United States dollars")
     );
    U(Jpy, 1e+99,
      "JPY",
      i18nc("currency name", "Japanese Yen"),
      i18nc("JPY Japanese Yen - unit synonyms for matching user input", "yen") +
      ";JPY;" + QString::fromUtf8("¥") + ';' +
      QLocale::countryToString(QLocale::Japan) + ';' + i18nc("currency name", "Japanese Yen"),
      ki18nc("amount in units (real)", "%1 yen"),
      ki18ncp("amount in units (integer)", "%1 yen", "%1 yen")
     );
    U(Bgn, 1e+99,
      "BGN",
      i18nc("currency name", "Bulgarian Lev"),
      i18nc("BGN Bulgarian Lev - unit synonyms for matching user input", "lev;leva") + ";BGN;" +
      QLocale::countryToString(QLocale::Bulgaria) + ';' + i18nc("currency name", "Bulgarian Lev"),
      ki18nc("amount in units (real)", "%1 leva"),
      ki18ncp("amount in units (integer)", "%1 lev", "%1 leva")
     );
    U(Czk, 1e+99,
      "CZK",
      i18nc("currency name", "Czech Koruna"),
      i18nc("CZK Czech Koruna - unit synonyms for matching user input", "koruna;korunas") +
      ";CZK;" + QLocale::countryToString(QLocale::CzechRepublic) + ';' +
      i18nc("currency name", "Czech Koruna"),
      ki18nc("amount in units (real)", "%1 Czech korunas"),
      // Alt: koruny, korun
      ki18ncp("amount in units (integer)", "%1 Czech koruna", "%1 Czech korunas")
     );
    U(Dkk, 1e+99,
      "DKK",
      i18nc("currency name", "Danish Krone"),
      i18nc("DKK Danish Krone - unit synonyms for matching user input",
            "Danish krone;Danish kroner") + ";DKK;" +
      QLocale::countryToString(QLocale::Denmark) + ';' +
      i18nc("currency name", "Danish Krone"),
      ki18nc("amount in units (real)", "%1 Danish kroner"),
      ki18ncp("amount in units (integer)", "%1 Danish krone", "%1 Danish kroner")
     );
    U(Eek, 1e+99,
      "EEK",
      i18nc("currency name", "Estonian Kroon"),
      i18nc("EEK Estonian Kroon - unit synonyms for matching user input", "kroon;kroons;krooni") +
      ";EEK;" + QLocale::countryToString(QLocale::Estonia) + ';' +
      i18nc("currency name", "Estonian Kroon"),
      ki18nc("amount in units (real)", "%1 kroons"),
      ki18ncp("amount in units (integer)", "%1 kroon", "%1 kroons") // Alt: krooni
     );
    U(Gbp, 1e+99,
      "GBP",
      i18nc("currency name", "British Pound"),
      i18nc("GBP British Pound - unit synonyms for matching user input",
            "pound;pounds;pound sterling;pounds sterling") +
      ";GBP;" + QString::fromUtf8("£") + ';' +
      QLocale::countryToString(QLocale::UnitedKingdom) + ';' +
      i18nc("currency name", "British Pound"),
      ki18nc("amount in units (real)", "%1 pounds sterling"),
      ki18ncp("amount in units (integer)", "%1 pound sterling", "%1 pounds sterling")
     );
    U(Huf, 1e+99,
      "HUF",
      i18nc("currency name", "Hungarian Forint"),
      i18nc("HUF hungarian Forint - unit synonyms for matching user input", "forint") + ";HUF;" +
      QLocale::countryToString(QLocale::Hungary) + ';' +
      i18nc("currency name", "Hungarian Forint"),
      ki18nc("amount in units (real)", "%1 forint"),
      ki18ncp("amount in units (integer)", "%1 forint", "%1 forint")
     );
    U(Ltl, 1e+99,
      "LTL",
      i18nc("currency name", "Lithuanian Litas"),
      i18nc("LTL Lithuanian Litas - unit synonyms for matching user input", "litas;litai;litu") +
      ";LTL;" + QLocale::countryToString(QLocale::Lithuania) + ';' +
      i18nc("currency name", "Lithuanian Litas"),
      ki18nc("amount in units (real)", "%1 litas"),
      ki18ncp("amount in units (integer)", "%1 litas", "%1 litai") // Alt: litu
     );
    U(Lvl, 1e+99,
      "LVL",
      i18nc("currency name", "Latvian Lats"),
      i18nc("LVL Latvian Lats - unit synonyms for matching user input", "lats;lati") + ";LVL;" +
      QLocale::countryToString(QLocale::Latvia) + ';' + i18nc("currency name", "Latvian Lats"),
      ki18nc("amount in units (real)", "%1 lati"),
      ki18ncp("amount in units (integer)", "%1 lats", "%1 lati")
     );
    U(Pln, 1e+99,
      "PLN",
      i18nc("currency name", "Polish Zloty"),
      i18nc("PLN Polish Zloty - unit synonyms for matching user input", "zloty;zlotys;zloties") +
      ";PLN;" + QLocale::countryToString(QLocale::Poland) + ';' +
      i18nc("currency name", "Polish Zloty"),
      ki18nc("amount in units (real)", "%1 zlotys"),
      ki18ncp("amount in units (integer)", "%1 zloty", "%1 zlotys") // Alt: zloty, zlote, zlotych
     );
    U(Ron, 1e+99,
      "RON",
      i18nc("currency name", "Romanian Leu"),
      i18nc("RON Romanian Leu - unit synonyms for matching user input", "leu;lei") + ";RON;" +
      QLocale::countryToString(QLocale::Romania) + ';' +
      i18nc("currency name", "Romanian Leu"),
      ki18nc("amount in units (real)", "%1 lei"),
      ki18ncp("amount in units (integer)", "%1 leu", "%1 lei")
     );
    U(Sek, 1e+99,
      "SEK",
      i18nc("currency name", "Swedish Krona"),
      i18nc("SEK Swedish Krona - unit synonyms for matching user input", "krona;kronor") + ";SEK;" +
      QLocale::countryToString(QLocale::Sweden) + ';' +
      i18nc("currency name", "Swedish Krona"),
      ki18nc("amount in units (real)", "%1 kronor"),
      ki18ncp("amount in units (integer)", "%1 krona", "%1 kronor")
     );
    U(Chf, 1e+99,
      "CHF",
      i18nc("currency name", "Swiss Franc"),
      i18nc("CHF Swiss Franc - unit synonyms for matching user input", "franc;francs") + ";CHF;" +
      QLocale::countryToString(QLocale::Switzerland) + ';' +
      i18nc("currency name", "Swiss Franc"),
      ki18nc("amount in units (real)", "%1 Swiss francs"),
      ki18ncp("amount in units (integer)", "%1 Swiss franc", "%1 Swiss francs")
     );
    U(Nok, 1e+99,
      "NOK",
      i18nc("currency name", "Norwegian Krone"),
      i18nc("Norwegian Krone - unit synonyms for matching user input",
            "Norwegian krone;Norwegian kroner") + ";NOK;" +
      QLocale::countryToString(QLocale::Norway) + ';' +
      i18nc("currency name", "Norwegian Krone"),
      ki18nc("amount in units (real)", "%1 Norwegian kroner"),
      ki18ncp("amount in units (integer)", "%1 Norwegian krone", "%1 Norwegian kroner")
     );
    U(Hrk, 1e+99,
      "HRK",
      i18nc("currency name", "Croatian Kuna"),
      i18nc("HRK Croatian Kuna - unit synonyms for matching user input", "kuna;kune") + ";HRK;" +
      QLocale::countryToString(QLocale::Croatia) + ';' +
      i18nc("currency name", "Croatian Kuna"),
      ki18nc("amount in units (real)", "%1 kune"),
      ki18ncp("amount in units (integer)", "%1 kuna", "%1 kune")
     );
    U(Rub, 1e+99,
      "RUB",
      i18nc("currency name", "Russian Ruble"),
      i18nc("RUB Russian Ruble - unit synonyms for matching user input",
            "ruble;rubles;rouble;roubles") + ";RUB;" +
      QLocale::countryToString(QLocale::Russia) + ';' +
      i18nc("currency name", "Russian Ruble"),
      ki18nc("amount in units (real)", "%1 rubles"),
      ki18ncp("amount in units (integer)", "%1 ruble", "%1 rubles") //Alt: rouble/roubles
     );
    U(Try, 1e+99,
      "TRY",
      i18nc("currency name", "Turkish Lira"),
      i18nc("TRY Turkish Lira - unit synonyms for matching user input", "lira") + ";TRY;" +
      QLocale::countryToString(QLocale::Turkey) + ';' +
      i18nc("currency name", "Turkish Lira"),
      ki18nc("amount in units (real)", "%1 Turkish lira"),
      ki18ncp("amount in units (integer)", "%1 Turkish lira", "%1 Turkish lira")
     );
    U(Aud, 1e+99,
      "AUD",
      i18nc("currency name", "Australian Dollar"),
      i18nc("AUD Australian Dollar - unit synonyms for matching user input",
            "Australian dollar;Australian dollars") + ";AUD;" +
      QLocale::countryToString(QLocale::Australia) + ';' +
      i18nc("currency name", "Australian Dollar"),
      ki18nc("amount in units (real)", "%1 Australian dollars"),
      ki18ncp("amount in units (integer)", "%1 Australian dollar", "%1 Australian dollars")
     );
    U(Brl, 1e+99,
      "BRL",
      i18nc("currency name", "Brazilian Real"),
      i18nc("BRL Brazilian Real - unit synonyms for matching user input", "real;reais") +
      ";BRL;" + QLocale::countryToString(QLocale::Brazil) + ';' +
      i18nc("currency name", "Brazilian Real"),
      ki18nc("amount in units (real)", "%1 reais"),
      ki18ncp("amount in units (integer)", "%1 real", "%1 reais")
     );
    U(Cad, 1e+99,
      "CAD",
      i18nc("currency name", "Canadian Dollar"),
      i18nc("Canadian Dollar - unit synonyms for matching user input",
            "Canadian dollar;Canadian dollars") + ";CAD;" +
      QLocale::countryToString(QLocale::Canada) + ';' +
      i18nc("currency name", "Canadian Dollar"),
      ki18nc("amount in units (real)", "%1 Canadian dollars"),
      ki18ncp("amount in units (integer)", "%1 Canadian dollar", "%1 Canadian dollars")
     );
    U(Cny, 1e+99,
      "CNY",
      i18nc("currency name", "Chinese Yuan"),
      i18nc("Chinese Yuan - unit synonyms for matching user input", "yuan") + ";CNY;" +
      QLocale::countryToString(QLocale::China) + ';' +
      i18nc("currency name", "Chinese Yuan"),
      ki18nc("amount in units (real)", "%1 yuan"),
      ki18ncp("amount in units (integer)", "%1 yuan", "%1 yuan")
     );
    U(Hkd, 1e+99,
      "HKD",
      i18nc("currency name", "Hong Kong Dollar"),
      i18nc("Hong Kong Dollar - unit synonyms for matching user input",
            "Hong Kong dollar;Hong Kong dollars") + ";HKD;" +
      QLocale::countryToString(QLocale::HongKong) + ';' +
      i18nc("currency name", "Hong Kong Dollar"),
      ki18nc("amount in units (real)", "%1 Hong Kong dollars"),
      ki18ncp("amount in units (integer)", "%1 Hong Kong dollar", "%1 Hong Kong dollars")
     );
    U(Idr, 1e+99,
      "IDR",
      i18nc("currency name", "Indonesian Rupiah"),
      i18nc("IDR Indonesian Rupiah - unit synonyms for matching user input", "rupiah;rupiahs") +
      ";IDR;" + QLocale::countryToString(QLocale::Indonesia) + ';' +
      i18nc("currency name", "Indonesian Rupiah"),
      ki18nc("amount in units (real)", "%1 rupiahs"),
      ki18ncp("amount in units (integer)", "%1 rupiah", "%1 rupiahs") // Alt: rupiah
     );
    U(Inr, 1e+99,
      "INR",
      i18nc("currency name", "Indian Rupee"),
      i18nc("INR Indian Rupee - unit synonyms for matching user input", "rupee;rupees") + ";INR;" +
      QLocale::countryToString(QLocale::India) + ';' +
      i18nc("currency name", "Indian Rupee"),
      ki18nc("amount in units (real)", "%1 rupees"),
      ki18ncp("amount in units (integer)", "%1 rupee", "%1 rupees") // Alt: rupee
     );
    U(Krw, 1e+99,
      "KRW",
      i18nc("currency name", "Korean Won"),
      i18nc("KRW Korean Won - unit synonyms for matching user input", "won") + ";KRW;" +
      QLocale::countryToString(QLocale::SouthKorea) + ';' +
      i18nc("currency name", "Korean Won"),
      ki18nc("amount in units (real)", "%1 won"),
      ki18ncp("amount in units (integer)", "%1 won", "%1 won")
     );
    U(Mxn, 1e+99,
      "MXN",
      i18nc("currency name", "Mexican Peso"),
      i18nc("MXN Mexican Peso - unit synonyms for matching user input",
            "Mexican peso;Mexican pesos") + ";MXN;" +
      QLocale::countryToString(QLocale::Mexico) + ';' +
      i18nc("currency name", "Mexican Peso"),
      ki18nc("amount in units (real)", "%1 Mexican pesos"),
      ki18ncp("amount in units (integer)", "%1 Mexican peso", "%1 Mexican pesos")
     );
    U(Myr, 1e+99,
      "MYR",
      i18nc("currency name", "Malaysian Ringgit"),
      i18nc("MYR Malaysian Ringgit - unit synonyms for matching user input", "ringgit;ringgits") +
      ";MYR;" + QLocale::countryToString(QLocale::Malaysia) + ';' +
      i18nc("currency name", "Malaysian Ringgit"),
      ki18nc("amount in units (real)", "%1 ringgit"),
      ki18ncp("amount in units (integer)", "%1 ringgit", "%1 ringgit") // Alt: ringgits
     );
    U(Nzd, 1e+99,
      "NZD",
      i18nc("currency name", "New Zealand Dollar"),
      i18nc("NZD New Zealand Dollar - unit synonyms for matching user input",
            "New Zealand dollar;New Zealand dollars") + ";NZD;" +
      QLocale::countryToString(QLocale::NewZealand) + ';' +
      i18nc("currency name", "New Zealand Dollar"),
      ki18nc("amount in units (real)", "%1 New Zealand dollars"),
      ki18ncp("amount in units (integer)", "%1 New Zealand dollar", "%1 New Zealand dollars")
     );
    U(Php, 1e+99,
      "PHP",
      i18nc("currency name", "Philippine Peso"),
      i18nc("PHP Philippine Peso - unit synonyms for matching user input",
            "Philippine peso;Philippine pesos") + ";PHP;" +
      QLocale::countryToString(QLocale::Philippines) + ';' +
      i18nc("currency name", "Philippine Peso"),
      ki18nc("amount in units (real)", "%1 Philippine pesos"),
      ki18ncp("amount in units (integer)", "%1 Philippine peso", "%1 Philippine pesos")
     );
    U(Sgd, 1e+99,
      "SGD",
      i18nc("currency name", "Singapore Dollar"),
      i18nc("SGD Singapore Dollar - unit synonyms for matching user input",
            "Singapore dollar;Singapore dollars") + ";SGD;" +
      QLocale::countryToString(QLocale::Singapore) + ';' +
      i18nc("currency name", "Singapore Dollar"),
      ki18nc("amount in units (real)", "%1 Singapore dollars"),
      ki18ncp("amount in units (integer)", "%1 Singapore dollar", "%1 Singapore dollars")
     );
    U(Thb, 1e+99,
      "THB",
      i18nc("currency name", "Thai Baht"),
      i18nc("THB Thai Baht - unit synonyms for matching user input", "baht") + ";THB;" +
      QLocale::countryToString(QLocale::Thailand) + ';' +
      i18nc("currency name", "Thai Baht"),
      ki18nc("amount in units (real)", "%1 baht"),
      ki18ncp("amount in units (integer)", "%1 baht", "%1 baht")
     );
    U(Zar, 1e+99,
      "ZAR",
      i18nc("currency name", "South African Rand"),
      i18nc("South African Rand - unit synonyms for matching user input", "rand") + ";ZAR;" +
      QLocale::countryToString(QLocale::SouthAfrica) + ';' +
      i18nc("currency name", "South African Rand"),
      ki18nc("amount in units (real)", "%1 rand"),
      ki18ncp("amount in units (integer)", "%1 rand", "%1 rand")
     );

    setMostCommonUnits(QList<UnitId>() << Eur << Usd << Jpy << Gbp << Cad);

    m_cache = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + QStringLiteral("/libkunitconversion/currency.xml");
    m_update = true;
}

static bool isConnected()
{
    bool ret = false;
    foreach (const QNetworkInterface &net, QNetworkInterface::allInterfaces()) {
        if (net.flags().testFlag(QNetworkInterface::IsUp) && !net.flags().testFlag(QNetworkInterface::IsLoopBack)) {
            ret = true;
            break;
        }
    }
    return ret;
}

Value Currency::convert(const Value &value, const Unit &to)
{
    static QMutex mutex;

    mutex.lock();
    QFileInfo info(m_cache);
    if (!info.exists() || info.lastModified().secsTo(QDateTime::currentDateTime()) > 86400) {
        if (isConnected()) {
            //qDebug() << "Getting currency info from net:" << URL;
            // TODO: This crashes in runner. Threading issues??
            /*
            KIO::Job* job = KIO::file_copy(QUrl(URL), QUrl::fromLocalFile(m_cache), -1,
                                           KIO::Overwrite | KIO::HideProgressInfo);
            job->setUiDelegate(0);
            if (job->exec()) {
                m_update = true;
            }
            */
            //qDebug() << "Removed previous cache:" << QFile::remove(m_cache);

            QNetworkAccessManager manager;
            QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(URL)));
            QFile cacheFile(m_cache);
            cacheFile.open(QFile::WriteOnly);
            while (!reply->error() && !reply->atEnd()) {
                if (reply->bytesAvailable() > 0
                        || reply->waitForReadyRead(500)) {
                    cacheFile.write(reply->readAll());
                }
            }
            cacheFile.close();
        }
    }
    mutex.unlock();

    if (m_update) {
        QFile file(m_cache);
        if (file.open(QIODevice::ReadOnly)) {
            QDomDocument doc;
            if (doc.setContent(&file, false)) {
                QDomNodeList list = doc.elementsByTagName("Cube");
                for (int i = 0; i < list.count(); ++i) {
                    const QDomElement e = list.item(i).toElement();
                    if (e.hasAttribute("currency")) {
                        Unit u = unit(e.attribute("currency"));
                        if (u.isValid()) {
                            u.setUnitMultiplier(1.0 / e.attribute("rate").toDouble());
                        }
                    }
                }
                m_update = false;
            }
        }
    }
    Value v = UnitCategory::convert(value, to);
    return v;
}
