/*
 *   Copyright (C) 2007-2009 Petri Damstén <damu@iki.fi>
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

#ifndef KUNITCONVERSION_UNIT_H
#define KUNITCONVERSION_UNIT_H

#include "kunitconversion/kunitconversion_export.h"

#include <QString>
#include <QExplicitlySharedDataPointer>

class KLocalizedString;

namespace KUnitConversion
{

enum CategoryId {
    InvalidCategory = -1,
    LengthCategory,
    AreaCategory,
    VolumeCategory,
    TemperatureCategory,
    VelocityCategory,
    MassCategory,
    PressureCategory,
    EnergyCategory,
    CurrencyCategory,
    PowerCategory,
    TimeCategory,
    FuelEfficiencyCategory,
    DensityCategory,
    AccelerationCategory,
    AngleCategory,
    FrequencyCategory,
    ForceCategory,
    /** @since 5.27 */
    ThermalConductivityCategory,
    /** @since 5.27 */
    ThermalFluxCategory,
    /** @since 5.27 */
    ThermalGenerationCategory,
    /** @since 5.27 */
    VoltageCategory,
    /** @since 5.27 */
    ElectricalCurrentCategory,
    /** @since 5.27 */
    ElectricalResistanceCategory
};

enum UnitId {
    InvalidUnit = -1,
    NoUnit = 0,
    Percent = 1,

    // Area
    SquareYottameter = 1000, SquareZettameter, SquareExameter, SquarePetameter, SquareTerameter,
    SquareGigameter, SquareMegameter, SquareKilometer, SquareHectometer, SquareDecameter,
    SquareMeter, SquareDecimeter, SquareCentimeter, SquareMillimeter, SquareMicrometer,
    SquareNanometer, SquarePicometer, SquareFemtometer, SquareAttometer, SquareZeptometer,
    SquareYoctometer, Acre, SquareFoot, SquareInch, SquareMile,

    // Length
    Yottameter = 2000, Zettameter, Exameter, Petameter, Terameter, Gigameter, Megameter,
    Kilometer, Hectometer, Decameter, Meter, Decimeter, Centimeter, Millimeter, Micrometer,
    Nanometer, Picometer, Femtometer, Attometer, Zeptometer, Yoctometer, Inch, Foot, Yard,
    Mile, NauticalMile, LightYear, Parsec, AstronomicalUnit, Thou, Angstrom,

    // Volume
    CubicYottameter = 3000, CubicZettameter, CubicExameter, CubicPetameter, CubicTerameter,
    CubicGigameter, CubicMegameter, CubicKilometer, CubicHectometer, CubicDecameter, CubicMeter,
    CubicDecimeter, CubicCentimeter, CubicMillimeter, CubicMicrometer, CubicNanometer,
    CubicPicometer, CubicFemtometer, CubicAttometer, CubicZeptometer, CubicYoctometer,
    Yottaliter, Zettaliter, Exaliter, Petaliter, Teraliter, Gigaliter, Megaliter, Kiloliter,
    Hectoliter, Decaliter, Liter, Deciliter, Centiliter, Milliliter, Microliter, Nanoliter,
    Picoliter, Femtoliter, Attoliter, Zeptoliter, Yoctoliter, CubicFoot, CubicInch, CubicMile,
    FluidOunce, Cup, GallonUS, PintImperial,

    // Mass
    Yottagram = 4000, Zettagram, Exagram, Petagram, Teragram, Gigagram, Megagram, Kilogram,
    Hectogram, Decagram, Gram, Decigram, Centigram, Milligram, Microgram, Nanogram, Picogram,
    Femtogram, Attogram, Zeptogram, Yoctogram, Ton, Carat, Pound, Ounce, TroyOunce, MassNewton,
    Kilonewton,

    /** @since 5.26 */
    Stone,

    // Pressure
    Yottapascal = 5000, Zettapascal, Exapascal, Petapascal, Terapascal, Gigapascal, Megapascal,
    Kilopascal, Hectopascal, Decapascal, Pascal, Decipascal, Centipascal, Millipascal,
    Micropascal, Nanopascal, Picopascal, Femtopascal, Attopascal, Zeptopascal, Yoctopascal,
    Bar, Millibar, Decibar, Torr, TechnicalAtmosphere, Atmosphere, PoundForcePerSquareInch,
    InchesOfMercury, MillimetersOfMercury,

    // Temperature
    Kelvin = 6000, Celsius, Fahrenheit, Rankine, Delisle, TemperatureNewton, Reaumur, Romer,

    // Energy
    Yottajoule = 7000, Zettajoule, Exajoule, Petajoule, Terajoule, Gigajoule, Megajoule,
    Kilojoule, Hectojoule, Decajoule, Joule, Decijoule, Centijoule, Millijoule, Microjoule,
    Nanojoule, Picojoule, Femtojoule, Attojoule, Zeptojoule, Yoctojoule, GuidelineDailyAmount,
    Electronvolt, Rydberg, Kilocalorie, PhotonWavelength, KiloJoulePerMole, JoulePerMole,
    /** @since 5.27 */
    Btu,
    /** @since 5.27 */
    Erg,

    // Currency
    Eur = 8000, Ats, Bef, Nlg, Fim, Frf, Dem, Iep, Itl, Luf, Pte, Esp, Grd, Sit, Cyp, Mtl, Skk,
    Usd, Jpy, Bgn, Czk, Dkk, Eek, Gbp, Huf, Ltl, Lvl, Pln, Ron, Sek, Chf, Nok, Hrk, Rub, Try,
    Aud, Brl, Cad, Cny, Hkd, Idr, Inr, Krw, Mxn, Myr, Nzd, Php, Sgd, Thb, Zar, Ils,

    // Velocity
    MeterPerSecond = 9000, KilometerPerHour, MilePerHour, FootPerSecond, InchPerSecond, Knot,
    Mach, SpeedOfLight, Beaufort,

    // Power
    Yottawatt = 10000, Zettawatt, Exawatt, Petawatt, Terawatt, Gigawatt, Megawatt, Kilowatt,
    Hectowatt, Decawatt, Watt, Deciwatt, Centiwatt, Milliwatt, Microwatt, Nanowatt, Picowatt,
    Femtowatt, Attowatt, Zeptowatt, Yoctowatt, Horsepower,

    // Time
    Yottasecond = 11000, Zettasecond, Exasecond, Petasecond, Terasecond, Gigasecond, Megasecond,
    Kilosecond, Hectosecond, Decasecond, Second, Decisecond, Centisecond, Millisecond,
    Microsecond, Nanosecond, Picosecond, Femtosecond, Attosecond, Zeptosecond, Yoctosecond,
    Minute, Hour, Day, Week, JulianYear, LeapYear, Year,

    // FuelEfficiency
    LitersPer100Kilometers = 12000, MilePerUsGallon, MilePerImperialGallon, KilometrePerLitre,

    // Density
    YottakilogramsPerCubicMeter = 13000, ZettakilogramPerCubicMeter, ExakilogramPerCubicMeter,
    PetakilogramPerCubicMeter, TerakilogramPerCubicMeter, GigakilogramPerCubicMeter,
    MegakilogramPerCubicMeter, KilokilogramPerCubicMeter, HectokilogramsPerCubicMeter,
    DecakilogramsPerCubicMeter, KilogramsPerCubicMeter, DecikilogramsPerCubicMeter,
    CentikilogramsPerCubicMeter, MillikilogramsPerCubicMeter, MicrokilogramsPerCubicMeter,
    NanokilogramsPerCubicMeter, PicokilogramsPerCubicMeter, FemtokilogramsPerCubicMeter,
    AttokilogramsPerCubicMeter, ZeptokilogramsPerCubicMeter, YoctokilogramsPerCubicMeter,
    KilogramPerLiter, GramPerLiter, GramPerMilliliter,
    OuncePerCubicInch, OuncePerCubicFoot, OuncePerCubicYard,
    PoundPerCubicInch, PoundPerCubicFoot, PoundPerCubicYard,

    // Acceleration
    MetresPerSecondSquared = 14000, FeetPerSecondSquared, StandardGravity,

    // Force
    Yottanewton = 15000, Zettanewton, Exanewton, Petanewton, Teranewton, Giganewton, Meganewton,
    KilonewtonForce, Hectonewton, Decanewton, Newton, Decinewton, Centinewton, Millinewton, Micronewton,
    Nanonewton, Piconewton, Femtonewton, Attonewton, Zeptonewton, Yoctonewton, Dyne, Kilopond,
    PoundForce, Poundal,

    // Angle
    Degree = 16000, Radian, Gradian, ArcMinute, ArcSecond,

    // Frequency
    Yottahertz = 17000, Zettahertz, Exahertz, Petahertz, Terahertz, Gigahertz, Megahertz,
    Kilohertz, Hectohertz, Decahertz, Hertz, Decihertz, Centihertz, Millihertz, Microhertz,
    Nanohertz, Picohertz, Femtohertz, Attohertz, Zeptohertz, Yoctohertz, RPM,

    // Thermal Conductivity
    /** @since 5.27 */
    WattPerMeterKelvin = 18000,
    /** @since 5.27 */
    BtuPerFootHourFahrenheit,
    /** @since 5.27 */
    BtuPerSquareFootHourFahrenheitPerInch,

    // Thermal Flux Density
    /** @since 5.27 */
    WattPerSquareMeter = 19000,
    /** @since 5.27 */
    BtuPerHourPerSquareFoot,

    // Thermal Generation per volume
    /** @since 5.27 */
    WattPerCubicMeter = 20000,
    /** @since 5.27 */
    BtuPerHourPerCubicFoot,

    // Voltage
    /** @since 5.27 */
    Yottavolts = 30000,
    /** @since 5.27 */
    Zettavolts,
    /** @since 5.27 */
    Exavolts,
    /** @since 5.27 */
    Petavolts,
    /** @since 5.27 */
    Teravolts,
    /** @since 5.27 */
    Gigavolts,
    /** @since 5.27 */
    Megavolts,
    /** @since 5.27 */
    Kilovolts,
    /** @since 5.27 */
    Hectovolts,
    /** @since 5.27 */
    Decavolts,
    /** @since 5.27 */
    Volts,
    /** @since 5.27 */
    Decivolts,
    /** @since 5.27 */
    Centivolts,
    /** @since 5.27 */
    Millivolts,
    /** @since 5.27 */
    Microvolts,
    /** @since 5.27 */
    Nanovolts,
    /** @since 5.27 */
    Picovolts,
    /** @since 5.27 */
    Femtovolts,
    /** @since 5.27 */
    Attovolts,
    /** @since 5.27 */
    Zeptovolts,
    /** @since 5.27 */
    Yoctovolts,
    /** @since 5.27 */
    Statvolts,

    // Electrical Current
    /** @since 5.27 */
    Yottaampere = 31000,
    /** @since 5.27 */
    Zettaampere,
    /** @since 5.27 */
    Exaampere,
    /** @since 5.27 */
    Petaampere,
    /** @since 5.27 */
    Teraampere,
    /** @since 5.27 */
    Gigaampere,
    /** @since 5.27 */
    Megaampere,
    /** @since 5.27 */
    Kiloampere,
    /** @since 5.27 */
    Hectoampere,
    /** @since 5.27 */
    Decaampere,
    /** @since 5.27 */
    Ampere,
    /** @since 5.27 */
    Deciampere,
    /** @since 5.27 */
    Centiampere,
    /** @since 5.27 */
    Milliampere,
    /** @since 5.27 */
    Microampere,
    /** @since 5.27 */
    Nanoampere,
    /** @since 5.27 */
    Picoampere,
    /** @since 5.27 */
    Femtoampere,
    /** @since 5.27 */
    Attoampere,
    /** @since 5.27 */
    Zeptoampere,
    /** @since 5.27 */
    Yoctoampere,

    // Electrical Resistance
    /** @since 5.27 */
    Yottaohms = 32000,
    /** @since 5.27 */
    Zettaohms,
    /** @since 5.27 */
    Exaohms,
    /** @since 5.27 */
    Petaohms,
    /** @since 5.27 */
    Teraohms,
    /** @since 5.27 */
    Gigaohms,
    /** @since 5.27 */
    Megaohms,
    /** @since 5.27 */
    Kiloohms,
    /** @since 5.27 */
    Hectoohms,
    /** @since 5.27 */
    Decaohms,
    /** @since 5.27 */
    Ohms,
    /** @since 5.27 */
    Deciohms,
    /** @since 5.27 */
    Centiohms,
    /** @since 5.27 */
    Milliohms,
    /** @since 5.27 */
    Microohms,
    /** @since 5.27 */
    Nanoohms,
    /** @since 5.27 */
    Picoohms,
    /** @since 5.27 */
    Femtoohms,
    /** @since 5.27 */
    Attoohms,
    /** @since 5.27 */
    Zeptoohms,
    /** @since 5.27 */
    Yoctoohms
};

class UnitCategory;
class UnitPrivate;

/**
 * @short Class to define a unit of measurement
 *
 * @since 4.4
 *
 * This is a class to define a unit of measurement.
 *
 * @b license GNU-LGPL v.2 or later
 *
 * @see Converter, UnitCategory, Value
 *
 * @author Petri Damstén <damu@iki.fi>
 * @author John Layt <jlayt@kde.org>
 */

class KUNITCONVERSION_EXPORT Unit
{
public:
    /**
     * Null constructor
     **/
    Unit();

    /**
     * Copy constructor, copy @p other to this.
     **/
    Unit(const Unit &other);

    virtual ~Unit();

    /**
     * Assignment operator, assign @p other to this.
     **/
    Unit &operator=(const Unit &other);

#ifdef Q_COMPILER_RVALUE_REFS
    /**
     * Move-assigns @p other to this Unit instance, transferring the
     * ownership of the managed pointer to this instance.
     **/
    Unit &operator=(Unit &&other) { swap(other); return *this; }
#endif

    /**
     * Swaps this Unit with @p other. This function is very fast and never fails.
     **/
    void swap(Unit &other) { d.swap(other.d); }

    /**
     * @return @c true if this Unit is equal to the @p other Unit.
     **/
    bool operator==(const Unit &other) const;

    /**
     * @return @c true if this Unit is not equal to the @p other Unit.
     **/
    bool operator!=(const Unit &other) const;

    /**
     * @return returns true if this Unit is null
     **/
    bool isNull() const;

    /**
     * @return if unit is valid.
     **/
    bool isValid() const;

    /**
     * @return unit id.
     **/
    UnitId id() const;

    /**
     * @return category id.
     **/
    CategoryId categoryId() const;

    /**
     * @return unit category.
     **/
    UnitCategory category() const;

    /**
     * @return translated name for unit.
     **/
    QString description() const;

    /**
     * @return symbol for the unit.
     **/
    QString symbol() const;

    /**
     * @param value number value
     * @param fieldWidth width of the formatted field, padded by spaces.
     *                   Positive value aligns right, negative aligns left
     * @param format type of floating point formating, like in QString::arg
     * @param precision number of digits after the decimal separator
     * @param fillChar the character used to fill up the empty places when
     *                 field width is greater than argument width
     * @return value + unit string
     **/
    QString toString(qreal value, int fieldWidth = 0, char format = 'g', int precision = -1,
                     const QChar &fillChar = QLatin1Char(' ')) const;

    /**
     * @param value number value
     * @param fieldWidth width of the formatted field, padded by spaces.
     *                   Positive value aligns right, negative aligns left
     * @param format type of floating point formating, like in QString::arg
     * @param precision number of digits after the decimal separator
     * @param fillChar the character used to fill up the empty places when
     *                 field width is greater than argument width
     * @return value + unit string
     **/
    QString toSymbolString(qreal value, int fieldWidth = 0, char format = 'g', int precision = -1,
                           const QChar &fillChar = QLatin1Char(' ')) const;


protected:
    qreal toDefault(qreal value) const;
    qreal fromDefault(qreal value) const;

private:
    friend class CustomUnit;
    friend class UnitCategory;
    friend class UnitCategoryPrivate;
    friend class CurrencyCategoryPrivate;

    Unit(UnitPrivate *dd);
    void setUnitMultiplier(qreal multiplier);

    QExplicitlySharedDataPointer<UnitPrivate> d;
};

} // KUnitConversion namespace

#endif
