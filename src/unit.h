/*
 *   SPDX-FileCopyrightText: 2007-2009 Petri Damstén <damu@iki.fi>
 *   SPDX-FileCopyrightText: 2014 John Layt <jlayt@kde.org>
 *
 *   SPDX-License-Identifier: LGPL-2.0-or-later
 */

#ifndef KUNITCONVERSION_UNIT_H
#define KUNITCONVERSION_UNIT_H

#include "kunitconversion/kunitconversion_export.h"

#include <QExplicitlySharedDataPointer>
#include <QString>

/*!
 * \namespace KUnitConversion
 * \inmodule KUnitConversion
 */
namespace KUnitConversion
{
/*!
 * \enum KUnitConversion::CategoryId
 * \value InvalidCategory
 * \value LengthCategory
 * \value AreaCategory
 * \value VolumeCategory
 * \value TemperatureCategory
 * \value VelocityCategory
 * \value MassCategory
 * \value PressureCategory
 * \value EnergyCategory
 * \value CurrencyCategory
 * \value PowerCategory
 * \value TimeCategory
 * \value FuelEfficiencyCategory
 * \value DensityCategory
 * \value WeightPerAreaCategory
 * \value AccelerationCategory
 * \value AngleCategory
 * \value FrequencyCategory
 * \value ForceCategory
 * \value [since 5.27] ThermalConductivityCategory
 * \value [since 5.27] ThermalFluxCategory
 * \value [since 5.27] ThermalGenerationCategory
 * \value [since 5.27] VoltageCategory
 * \value [since 5.27] ElectricalCurrentCategory
 * \value [since 5.27] ElectricalResistanceCategory
 * \value [since 5.53] PermeabilityCategory
 * \value [since 5.61] BinaryDataCategory
 */
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
    WeightPerAreaCategory,
    AccelerationCategory,
    AngleCategory,
    FrequencyCategory,
    ForceCategory,
    ThermalConductivityCategory,
    ThermalFluxCategory,
    ThermalGenerationCategory,
    VoltageCategory,
    ElectricalCurrentCategory,
    ElectricalResistanceCategory,
    PermeabilityCategory,
    BinaryDataCategory
};

/*!
 * \enum KUnitConversion::UnitId
 * \value InvalidUnit
 * \value NoUnit
 * \value Percent
 *
 * \value SquareYottameter
 * \value SquareZettameter
 * \value SquareExameter
 * \value SquarePetameter
 * \value SquareTerameter
 * \value SquareGigameter
 * \value SquareMegameter
 * \value SquareKilometer
 * \value SquareHectometer
 * \value SquareDecameter
 * \value SquareMeter
 * \value SquareDecimeter
 * \value SquareCentimeter
 * \value SquareMillimeter
 * \value SquareMicrometer
 * \value SquareNanometer
 * \value SquarePicometer
 * \value SquareFemtometer
 * \value SquareAttometer
 * \value SquareZeptometer
 * \value SquareYoctometer
 * \value Acre
 * \value SquareFoot
 * \value SquareInch
 * \value SquareMile
 *
 * \value Yottameter
 * \value Zettameter
 * \value Exameter
 * \value Petameter
 * \value Terameter
 * \value Gigameter
 * \value Megameter
 * \value Kilometer
 * \value Hectometer
 * \value Decameter
 * \value Meter
 * \value Decimeter
 * \value Centimeter
 * \value Millimeter
 * \value Micrometer
 * \value Nanometer
 * \value Picometer
 * \value Femtometer
 * \value Attometer
 * \value Zeptometer
 * \value Yoctometer
 * \value Inch
 * \value Foot
 * \value Yard
 * \value Mile
 * \value NauticalMile
 * \value LightYear
 * \value Parsec
 * \value AstronomicalUnit
 * \value Thou
 * \value Angstrom
 *
 * \value CubicYottameter
 * \value CubicZettameter
 * \value CubicExameter
 * \value CubicPetameter
 * \value CubicTerameter
 * \value CubicGigameter
 * \value CubicMegameter
 * \value CubicKilometer
 * \value CubicHectometer
 * \value CubicDecameter
 * \value CubicMeter
 * \value CubicDecimeter
 * \value CubicCentimeter
 * \value CubicMillimeter
 * \value CubicMicrometer
 * \value CubicNanometer
 * \value CubicPicometer
 * \value CubicFemtometer
 * \value CubicAttometer
 * \value CubicZeptometer
 * \value CubicYoctometer
 * \value Yottaliter
 * \value Zettaliter
 * \value Exaliter
 * \value Petaliter
 * \value Teraliter
 * \value Gigaliter
 * \value Megaliter
 * \value Kiloliter
 * \value Hectoliter
 * \value Decaliter
 * \value Liter
 * \value Deciliter
 * \value Centiliter
 * \value Milliliter
 * \value Microliter
 * \value Nanoliter
 * \value Picoliter
 * \value Femtoliter
 * \value Attoliter
 * \value Zeptoliter
 * \value Yoctoliter
 * \value CubicFoot
 * \value CubicInch
 * \value CubicMile
 * \value FluidOunce
 * \value Cup
 * \value Teaspoon
 * \value Tablespoon
 * \value GallonUS
 * \value PintImperial
 * \value [since 5.53] OilBarrel
 * \value [since 5.70] GallonImperial
 * \value [since 5.70] PintUS
 *
 * \value Yottagram
 * \value Zettagram
 * \value Exagram
 * \value Petagram
 * \value Teragram
 * \value Gigagram
 * \value Megagram
 * \value Kilogram
 * \value Hectogram
 * \value Decagram
 * \value Gram
 * \value Decigram
 * \value Centigram
 * \value Milligram
 * \value Microgram
 * \value Nanogram
 * \value Picogram
 * \value Femtogram
 * \value Attogram
 * \value Zeptogram
 * \value Yoctogram
 * \value Ton
 * \value Carat
 * \value Pound
 * \value Ounce
 * \value TroyOunce
 * \value MassNewton
 * \value Kilonewton
 *
 * \value [since 5.26] Stone
 *
 * \value Yottapascal
 * \value Zettapascal
 * \value Exapascal
 * \value Petapascal
 * \value Terapascal
 * \value Gigapascal
 * \value Megapascal
 * \value Kilopascal
 * \value Hectopascal
 * \value Decapascal
 * \value Pascal
 * \value Decipascal
 * \value Centipascal
 * \value Millipascal
 * \value Micropascal
 * \value Nanopascal
 * \value Picopascal
 * \value Femtopascal
 * \value Attopascal
 * \value Zeptopascal
 * \value Yoctopascal
 * \value Bar
 * \value Millibar
 * \value Decibar
 * \value Torr
 * \value TechnicalAtmosphere
 * \value Atmosphere
 * \value PoundForcePerSquareInch
 * \value InchesOfMercury
 * \value MillimetersOfMercury
 *
 * \value Kelvin
 * \value Celsius
 * \value Fahrenheit
 * \value Rankine
 * \value Delisle
 * \value TemperatureNewton
 * \value Reaumur
 * \value Romer
 *
 * \value Yottajoule
 * \value Zettajoule
 * \value Exajoule
 * \value Petajoule
 * \value Terajoule
 * \value Gigajoule
 * \value Megajoule
 * \value Kilojoule
 * \value Hectojoule
 * \value Decajoule
 * \value Joule
 * \value Decijoule
 * \value Centijoule
 * \value Millijoule
 * \value Microjoule
 * \value Nanojoule
 * \value Picojoule
 * \value Femtojoule
 * \value Attojoule
 * \value Zeptojoule
 * \value Yoctojoule
 * \value GuidelineDailyAmount
 * \value Electronvolt
 * \value Rydberg
 * \value Kilocalorie
 * \value PhotonWavelength
 * \value KiloJoulePerMole
 * \value JoulePerMole
 * \value [since 5.27] Btu
 * \value [since 5.27] Erg
 *
 * \value Eur
 * \value Ats
 * \value Bef
 * \value Nlg
 * \value Fim
 * \value Frf
 * \value Dem
 * \value Iep
 * \value Itl
 * \value Luf
 * \value Pte
 * \value Esp
 * \value Grd
 * \value Sit
 * \value Cyp
 * \value Mtl
 * \value Skk
 * \value Usd
 * \value Jpy
 * \value Bgn
 * \value Czk
 * \value Dkk
 * \value Eek
 * \value Gbp
 * \value Huf
 * \value Ltl
 * \value Lvl
 * \value Pln
 * \value Ron
 * \value Sek
 * \value Chf
 * \value Nok
 * \value Hrk
 * \value Rub
 * \value Try
 * \value Aud
 * \value Brl
 * \value Cad
 * \value Cny
 * \value Hkd
 * \value Idr
 * \value Inr
 * \value Krw
 * \value Mxn
 * \value Myr
 * \value Nzd
 * \value Php
 * \value Sgd
 * \value Thb
 * \value Zar
 * \value Ils
 * \value Isk
 *
 * \value MeterPerSecond
 * \value KilometerPerHour
 * \value MilePerHour
 * \value FootPerSecond
 * \value InchPerSecond
 * \value Knot
 * \value Mach
 * \value SpeedOfLight
 * \value Beaufort
 *
 * \value Yottawatt
 * \value Zettawatt
 * \value Exawatt
 * \value Petawatt
 * \value Terawatt
 * \value Gigawatt
 * \value Megawatt
 * \value Kilowatt
 * \value Hectowatt
 * \value Decawatt
 * \value Watt
 * \value Deciwatt
 * \value Centiwatt
 * \value Milliwatt
 * \value Microwatt
 * \value Nanowatt
 * \value Picowatt
 * \value Femtowatt
 * \value Attowatt
 * \value Zeptowatt
 * \value Yoctowatt
 * \value Horsepower
 * \value [since 5.62] DecibelKilowatt
 * \value [since 5.62] DecibelWatt
 * \value [since 5.62] DecibelMilliwatt
 * \value [since 5.62] DecibelMicrowatt
 *
 * \value Yottasecond
 * \value Zettasecond
 * \value Exasecond
 * \value Petasecond
 * \value Terasecond
 * \value Gigasecond
 * \value Megasecond
 * \value Kilosecond
 * \value Hectosecond
 * \value Decasecond
 * \value Second
 * \value Decisecond
 * \value Centisecond
 * \value Millisecond
 * \value Microsecond
 * \value Nanosecond
 * \value Picosecond
 * \value Femtosecond
 * \value Attosecond
 * \value Zeptosecond
 * \value Yoctosecond
 * \value Minute
 * \value Hour
 * \value Day
 * \value Week
 * \value JulianYear
 * \value LeapYear
 * \value Year
 *
 * \value LitersPer100Kilometers
 * \value MilePerUsGallon
 * \value MilePerImperialGallon
 * \value KilometrePerLitre
 *
 * \value YottakilogramsPerCubicMeter
 * \value ZettakilogramPerCubicMeter
 * \value ExakilogramPerCubicMeter
 * \value PetakilogramPerCubicMeter
 * \value TerakilogramPerCubicMeter
 * \value GigakilogramPerCubicMeter
 * \value MegakilogramPerCubicMeter
 * \value KilokilogramPerCubicMeter
 * \value HectokilogramsPerCubicMeter
 * \value DecakilogramsPerCubicMeter
 * \value KilogramsPerCubicMeter
 * \value DecikilogramsPerCubicMeter
 * \value CentikilogramsPerCubicMeter
 * \value MillikilogramsPerCubicMeter
 * \value MicrokilogramsPerCubicMeter
 * \value NanokilogramsPerCubicMeter
 * \value PicokilogramsPerCubicMeter
 * \value FemtokilogramsPerCubicMeter
 * \value AttokilogramsPerCubicMeter
 * \value ZeptokilogramsPerCubicMeter
 * \value YoctokilogramsPerCubicMeter
 * \value KilogramPerLiter
 * \value GramPerLiter
 * \value GramPerMilliliter
 * \value OuncePerCubicInch
 * \value OuncePerCubicFoot
 * \value OuncePerCubicYard
 * \value PoundPerCubicInch
 * \value PoundPerCubicFoot
 * \value PoundPerCubicYard
 *
 * \value GramsPerSquareMeter
 * \value OuncesPerSquareYard
 *
 * \value MetresPerSecondSquared
 * \value FeetPerSecondSquared
 * \value StandardGravity
 *
 * \value Yottanewton
 * \value Zettanewton
 * \value Exanewton
 * \value Petanewton
 * \value Teranewton
 * \value Giganewton
 * \value Meganewton
 * \value KilonewtonForce
 * \value Hectonewton
 * \value Decanewton
 * \value Newton
 * \value Decinewton
 * \value Centinewton
 * \value Millinewton
 * \value Micronewton
 * \value Nanonewton
 * \value Piconewton
 * \value Femtonewton
 * \value Attonewton
 * \value Zeptonewton
 * \value Yoctonewton
 * \value Dyne
 * \value Kilopond
 * \value PoundForce
 * \value Poundal
 *
 * \value Degree
 * \value Radian
 * \value Gradian
 * \value ArcMinute
 * \value ArcSecond
 *
 * \value Yottahertz
 * \value Zettahertz
 * \value Exahertz
 * \value Petahertz
 * \value Terahertz
 * \value Gigahertz
 * \value Megahertz
 * \value Kilohertz
 * \value Hectohertz
 * \value Decahertz
 * \value Hertz
 * \value Decihertz
 * \value Centihertz
 * \value Millihertz
 * \value Microhertz
 * \value Nanohertz
 * \value Picohertz
 * \value Femtohertz
 * \value Attohertz
 * \value Zeptohertz
 * \value Yoctohertz
 * \value RPM
 *
 * \value [since 5.27] WattPerMeterKelvin
 * \value [since 5.27] BtuPerFootHourFahrenheit
 * \value [since 5.27] BtuPerSquareFootHourFahrenheitPerInch
 *
 * \value [since 5.27] WattPerSquareMeter
 * \value [since 5.27] BtuPerHourPerSquareFoot
 *
 * \value [since 5.27] WattPerCubicMeter
 * \value [since 5.27] BtuPerHourPerCubicFoot
 *
 * \value [since 5.27] Yottavolts
 * \value [since 5.27] Zettavolts
 * \value [since 5.27] Exavolts
 * \value [since 5.27] Petavolts
 * \value [since 5.27] Teravolts
 * \value [since 5.27] Gigavolts
 * \value [since 5.27] Megavolts
 * \value [since 5.27] Kilovolts
 * \value [since 5.27] Hectovolts
 * \value [since 5.27] Decavolts
 * \value [since 5.27] Volts
 * \value [since 5.27] Decivolts
 * \value [since 5.27] Centivolts
 * \value [since 5.27] Millivolts
 * \value [since 5.27] Microvolts
 * \value [since 5.27] Nanovolts
 * \value [since 5.27] Picovolts
 * \value [since 5.27] Femtovolts
 * \value [since 5.27] Attovolts
 * \value [since 5.27] Zeptovolts
 * \value [since 5.27] Yoctovolts
 * \value [since 5.27] Statvolts
 * \value [since 5.27] Yottaampere
 * \value [since 5.27] Zettaampere
 * \value [since 5.27] Exaampere
 * \value [since 5.27] Petaampere
 * \value [since 5.27] Teraampere
 * \value [since 5.27] Gigaampere
 * \value [since 5.27] Megaampere
 * \value [since 5.27] Kiloampere
 * \value [since 5.27] Hectoampere
 * \value [since 5.27] Decaampere
 * \value [since 5.27] Ampere
 * \value [since 5.27] Deciampere
 * \value [since 5.27] Centiampere
 * \value [since 5.27] Milliampere
 * \value [since 5.27] Microampere
 * \value [since 5.27] Nanoampere
 * \value [since 5.27] Picoampere
 * \value [since 5.27] Femtoampere
 * \value [since 5.27] Attoampere
 * \value [since 5.27] Zeptoampere
 * \value [since 5.27] Yoctoampere
 * \value [since 5.27] Yottaohms
 * \value [since 5.27] Zettaohms
 * \value [since 5.27] Exaohms
 * \value [since 5.27] Petaohms
 * \value [since 5.27] Teraohms
 * \value [since 5.27] Gigaohms
 * \value [since 5.27] Megaohms
 * \value [since 5.27] Kiloohms
 * \value [since 5.27] Hectoohms
 * \value [since 5.27] Decaohms
 * \value [since 5.27] Ohms
 * \value [since 5.27] Deciohms
 * \value [since 5.27] Centiohms
 * \value [since 5.27] Milliohms
 * \value [since 5.27] Microohms
 * \value [since 5.27] Nanoohms
 * \value [since 5.27] Picoohms
 * \value [since 5.27] Femtoohms
 * \value [since 5.27] Attoohms
 * \value [since 5.27] Zeptoohms
 * \value [since 5.27] Yoctoohms
 *
 * \value [since 5.53] Darcy
 * \value [since 5.53] MiliDarcy
 * \value [since 5.53] PermeabilitySquareMicrometer
 *
 * \value [since 5.61] Yobibyte
 * \value [since 5.61] Yobibit
 * \value [since 5.61] Yottabyte
 * \value [since 5.61] Yottabit
 * \value [since 5.61] Zebibyte
 * \value [since 5.61] Zebibit
 * \value [since 5.61] Zettabyte
 * \value [since 5.61] Zettabit
 * \value [since 5.61] Exbibyte
 * \value [since 5.61] Exbibit
 * \value [since 5.61] Exabyte
 * \value [since 5.61] Exabit
 * \value [since 5.61] Pebibyte
 * \value [since 5.61] Pebibit
 * \value [since 5.61] Petabyte
 * \value [since 5.61] Petabit
 * \value [since 5.61] Tebibyte
 * \value [since 5.61] Tebibit
 * \value [since 5.61] Terabyte
 * \value [since 5.61] Terabit
 * \value [since 5.61] Gibibyte
 * \value [since 5.61] Gibibit
 * \value [since 5.61] Gigabyte
 * \value [since 5.61] Gigabit
 * \value [since 5.61] Mebibyte
 * \value [since 5.61] Mebibit
 * \value [since 5.61] Megabyte
 * \value [since 5.61] Megabit
 * \value [since 5.61] Kibibyte
 * \value [since 5.61] Kibibit
 * \value [since 5.61] Kilobyte
 * \value [since 5.61] Kilobit
 * \value [since 5.61] Byte
 * \value [since 5.61] Bit
 */
enum UnitId {
    InvalidUnit = -1,
    NoUnit = 0,
    Percent = 1,

    // Area
    SquareYottameter = 1000,
    SquareZettameter,
    SquareExameter,
    SquarePetameter,
    SquareTerameter,
    SquareGigameter,
    SquareMegameter,
    SquareKilometer,
    SquareHectometer,
    SquareDecameter,
    SquareMeter,
    SquareDecimeter,
    SquareCentimeter,
    SquareMillimeter,
    SquareMicrometer,
    SquareNanometer,
    SquarePicometer,
    SquareFemtometer,
    SquareAttometer,
    SquareZeptometer,
    SquareYoctometer,
    Acre,
    SquareFoot,
    SquareInch,
    SquareMile,

    // Length
    Yottameter = 2000,
    Zettameter,
    Exameter,
    Petameter,
    Terameter,
    Gigameter,
    Megameter,
    Kilometer,
    Hectometer,
    Decameter,
    Meter,
    Decimeter,
    Centimeter,
    Millimeter,
    Micrometer,
    Nanometer,
    Picometer,
    Femtometer,
    Attometer,
    Zeptometer,
    Yoctometer,
    Inch,
    Foot,
    Yard,
    Mile,
    NauticalMile,
    LightYear,
    Parsec,
    AstronomicalUnit,
    Thou,
    Angstrom,
    RackUnit,

    // Volume
    CubicYottameter = 3000,
    CubicZettameter,
    CubicExameter,
    CubicPetameter,
    CubicTerameter,
    CubicGigameter,
    CubicMegameter,
    CubicKilometer,
    CubicHectometer,
    CubicDecameter,
    CubicMeter,
    CubicDecimeter,
    CubicCentimeter,
    CubicMillimeter,
    CubicMicrometer,
    CubicNanometer,
    CubicPicometer,
    CubicFemtometer,
    CubicAttometer,
    CubicZeptometer,
    CubicYoctometer,
    Yottaliter,
    Zettaliter,
    Exaliter,
    Petaliter,
    Teraliter,
    Gigaliter,
    Megaliter,
    Kiloliter,
    Hectoliter,
    Decaliter,
    Liter,
    Deciliter,
    Centiliter,
    Milliliter,
    Microliter,
    Nanoliter,
    Picoliter,
    Femtoliter,
    Attoliter,
    Zeptoliter,
    Yoctoliter,
    CubicFoot,
    CubicInch,
    CubicMile,
    FluidOunce,
    Cup,
    Teaspoon,
    Tablespoon,
    GallonUS,
    PintImperial,
    OilBarrel,
    GallonImperial,
    PintUS,

    // Mass
    Yottagram = 4000,
    Zettagram,
    Exagram,
    Petagram,
    Teragram,
    Gigagram,
    Megagram,
    Kilogram,
    Hectogram,
    Decagram,
    Gram,
    Decigram,
    Centigram,
    Milligram,
    Microgram,
    Nanogram,
    Picogram,
    Femtogram,
    Attogram,
    Zeptogram,
    Yoctogram,
    Ton,
    Carat,
    Pound,
    Ounce,
    TroyOunce,
    MassNewton,
    Kilonewton,

    Stone,

    // Pressure
    Yottapascal = 5000,
    Zettapascal,
    Exapascal,
    Petapascal,
    Terapascal,
    Gigapascal,
    Megapascal,
    Kilopascal,
    Hectopascal,
    Decapascal,
    Pascal,
    Decipascal,
    Centipascal,
    Millipascal,
    Micropascal,
    Nanopascal,
    Picopascal,
    Femtopascal,
    Attopascal,
    Zeptopascal,
    Yoctopascal,
    Bar,
    Millibar,
    Decibar,
    Torr,
    TechnicalAtmosphere,
    Atmosphere,
    PoundForcePerSquareInch,
    InchesOfMercury,
    MillimetersOfMercury,

    // Temperature
    Kelvin = 6000,
    Celsius,
    Fahrenheit,
    Rankine,
    Delisle,
    TemperatureNewton,
    Reaumur,
    Romer,

    // Energy
    Yottajoule = 7000,
    Zettajoule,
    Exajoule,
    Petajoule,
    Terajoule,
    Gigajoule,
    Megajoule,
    Kilojoule,
    Hectojoule,
    Decajoule,
    Joule,
    Decijoule,
    Centijoule,
    Millijoule,
    Microjoule,
    Nanojoule,
    Picojoule,
    Femtojoule,
    Attojoule,
    Zeptojoule,
    Yoctojoule,
    GuidelineDailyAmount,
    Electronvolt,
    Rydberg,
    Kilocalorie,
    PhotonWavelength,
    KiloJoulePerMole,
    JoulePerMole,
    Btu,
    Erg,

    // Currency
    Eur = 8000,
    Ats,
    Bef,
    Nlg,
    Fim,
    Frf,
    Dem,
    Iep,
    Itl,
    Luf,
    Pte,
    Esp,
    Grd,
    Sit,
    Cyp,
    Mtl,
    Skk,
    Usd,
    Jpy,
    Bgn,
    Czk,
    Dkk,
    Eek,
    Gbp,
    Huf,
    Ltl,
    Lvl,
    Pln,
    Ron,
    Sek,
    Chf,
    Nok,
    Hrk,
    Rub,
    Try,
    Aud,
    Brl,
    Cad,
    Cny,
    Hkd,
    Idr,
    Inr,
    Krw,
    Mxn,
    Myr,
    Nzd,
    Php,
    Sgd,
    Thb,
    Zar,
    Ils,
    Isk,
    Xpf, /// @since 6.9

    // Velocity
    MeterPerSecond = 9000,
    KilometerPerHour,
    MilePerHour,
    FootPerSecond,
    InchPerSecond,
    Knot,
    Mach,
    SpeedOfLight,
    Beaufort,

    // Power
    Yottawatt = 10000,
    Zettawatt,
    Exawatt,
    Petawatt,
    Terawatt,
    Gigawatt,
    Megawatt,
    Kilowatt,
    Hectowatt,
    Decawatt,
    Watt,
    Deciwatt,
    Centiwatt,
    Milliwatt,
    Microwatt,
    Nanowatt,
    Picowatt,
    Femtowatt,
    Attowatt,
    Zeptowatt,
    Yoctowatt,
    Horsepower,
    DecibelKilowatt,
    DecibelWatt,
    DecibelMilliwatt,
    DecibelMicrowatt,

    // Time
    Yottasecond = 11000,
    Zettasecond,
    Exasecond,
    Petasecond,
    Terasecond,
    Gigasecond,
    Megasecond,
    Kilosecond,
    Hectosecond,
    Decasecond,
    Second,
    Decisecond,
    Centisecond,
    Millisecond,
    Microsecond,
    Nanosecond,
    Picosecond,
    Femtosecond,
    Attosecond,
    Zeptosecond,
    Yoctosecond,
    Minute,
    Hour,
    Day,
    Week,
    JulianYear,
    LeapYear,
    Year,

    // FuelEfficiency
    LitersPer100Kilometers = 12000,
    MilePerUsGallon,
    MilePerImperialGallon,
    KilometrePerLitre,

    // Density
    YottakilogramsPerCubicMeter = 13000,
    ZettakilogramPerCubicMeter,
    ExakilogramPerCubicMeter,
    PetakilogramPerCubicMeter,
    TerakilogramPerCubicMeter,
    GigakilogramPerCubicMeter,
    MegakilogramPerCubicMeter,
    KilokilogramPerCubicMeter,
    HectokilogramsPerCubicMeter,
    DecakilogramsPerCubicMeter,
    KilogramsPerCubicMeter,
    DecikilogramsPerCubicMeter,
    CentikilogramsPerCubicMeter,
    MillikilogramsPerCubicMeter,
    MicrokilogramsPerCubicMeter,
    NanokilogramsPerCubicMeter,
    PicokilogramsPerCubicMeter,
    FemtokilogramsPerCubicMeter,
    AttokilogramsPerCubicMeter,
    ZeptokilogramsPerCubicMeter,
    YoctokilogramsPerCubicMeter,
    KilogramPerLiter,
    GramPerLiter,
    GramPerMilliliter,
    OuncePerCubicInch,
    OuncePerCubicFoot,
    OuncePerCubicYard,
    PoundPerCubicInch,
    PoundPerCubicFoot,
    PoundPerCubicYard,

    // Weight per area
    GramsPerSquareMeter,
    OuncesPerSquareYard,

    // Acceleration
    MetresPerSecondSquared = 14000,
    FeetPerSecondSquared,
    StandardGravity,

    // Force
    Yottanewton = 15000,
    Zettanewton,
    Exanewton,
    Petanewton,
    Teranewton,
    Giganewton,
    Meganewton,
    KilonewtonForce,
    Hectonewton,
    Decanewton,
    Newton,
    Decinewton,
    Centinewton,
    Millinewton,
    Micronewton,
    Nanonewton,
    Piconewton,
    Femtonewton,
    Attonewton,
    Zeptonewton,
    Yoctonewton,
    Dyne,
    Kilopond,
    PoundForce,
    Poundal,

    // Angle
    Degree = 16000,
    Radian,
    Gradian,
    ArcMinute,
    ArcSecond,

    // Frequency
    Yottahertz = 17000,
    Zettahertz,
    Exahertz,
    Petahertz,
    Terahertz,
    Gigahertz,
    Megahertz,
    Kilohertz,
    Hectohertz,
    Decahertz,
    Hertz,
    Decihertz,
    Centihertz,
    Millihertz,
    Microhertz,
    Nanohertz,
    Picohertz,
    Femtohertz,
    Attohertz,
    Zeptohertz,
    Yoctohertz,
    RPM,

    // Thermal Conductivity
    WattPerMeterKelvin = 18000,
    BtuPerFootHourFahrenheit,
    BtuPerSquareFootHourFahrenheitPerInch,

    // Thermal Flux Density
    WattPerSquareMeter = 19000,
    BtuPerHourPerSquareFoot,

    // Thermal Generation per volume
    WattPerCubicMeter = 20000,
    BtuPerHourPerCubicFoot,

    // Voltage
    Yottavolts = 30000,
    Zettavolts,
    Exavolts,
    Petavolts,
    Teravolts,
    Gigavolts,
    Megavolts,
    Kilovolts,
    Hectovolts,
    Decavolts,
    Volts,
    Decivolts,
    Centivolts,
    Millivolts,
    Microvolts,
    Nanovolts,
    Picovolts,
    Femtovolts,
    Attovolts,
    Zeptovolts,
    Yoctovolts,
    Statvolts,

    // Electrical Current
    Yottaampere = 31000,
    Zettaampere,
    Exaampere,
    Petaampere,
    Teraampere,
    Gigaampere,
    Megaampere,
    Kiloampere,
    Hectoampere,
    Decaampere,
    Ampere,
    Deciampere,
    Centiampere,
    Milliampere,
    Microampere,
    Nanoampere,
    Picoampere,
    Femtoampere,
    Attoampere,
    Zeptoampere,
    Yoctoampere,

    // Electrical Resistance
    Yottaohms = 32000,
    Zettaohms,
    Exaohms,
    Petaohms,
    Teraohms,
    Gigaohms,
    Megaohms,
    Kiloohms,
    Hectoohms,
    Decaohms,
    Ohms,
    Deciohms,
    Centiohms,
    Milliohms,
    Microohms,
    Nanoohms,
    Picoohms,
    Femtoohms,
    Attoohms,
    Zeptoohms,
    Yoctoohms,

    Darcy = 33000,
    MiliDarcy,
    PermeabilitySquareMicrometer,

    Yobibyte = 34000,
    Yobibit,
    Yottabyte,
    Yottabit,
    Zebibyte,
    Zebibit,
    Zettabyte,
    Zettabit,
    Exbibyte,
    Exbibit,
    Exabyte,
    Exabit,
    Pebibyte,
    Pebibit,
    Petabyte,
    Petabit,
    Tebibyte,
    Tebibit,
    Terabyte,
    Terabit,
    Gibibyte,
    Gibibit,
    Gigabyte,
    Gigabit,
    Mebibyte,
    Mebibit,
    Megabyte,
    Megabit,
    Kibibyte,
    Kibibit,
    Kilobyte,
    Kilobit,
    Byte,
    Bit
};

class UnitCategory;
class UnitPrivate;

/*!
 * \class KUnitConversion::Unit
 * \inmodule KUnitConversion
 *
 * \brief Class to define a unit of measurement.
 *
 * This is a class to define a unit of measurement.
 *
 * \sa Converter, UnitCategory, Value
 *
 */

class KUNITCONVERSION_EXPORT Unit
{
public:
    /*!
     * Null constructor
     **/
    Unit();

    Unit(const Unit &other);

    ~Unit();

    Unit &operator=(const Unit &other);

    Unit &operator=(Unit &&other);

    /*!
     * Returns true if this Unit is equal to the \a other Unit.
     **/
    bool operator==(const Unit &other) const;

    bool operator!=(const Unit &other) const;

    /*!
     * Returns returns true if this Unit is null
     **/
    bool isNull() const;

    /*!
     * Returns if unit is valid.
     **/
    bool isValid() const;

    /*!
     * Returns unit id.
     **/
    UnitId id() const;

    /*!
     * Returns category id.
     **/
    CategoryId categoryId() const;

    /*!
     * Returns unit category.
     **/
    UnitCategory category() const;

    /*!
     * Returns translated name for unit.
     **/
    QString description() const;

    /*!
     * Returns symbol for the unit.
     **/
    QString symbol() const;

    /*!
     * \a value number value
     *
     * \a fieldWidth width of the formatted field, padded by spaces.
     *                   Positive value aligns right, negative aligns left
     *
     * \a format type of floating point formatting, like in \l QString::arg
     *
     * \a precision number of digits after the decimal separator
     *
     * \a fillChar the character used to fill up the empty places when
     *                 field width is greater than argument width
     *
     * Returns value + unit string
     **/
    QString toString(qreal value, int fieldWidth = 0, char format = 'g', int precision = -1, const QChar &fillChar = QLatin1Char(' ')) const;

    /*!
     * \a value number value
     *
     * \a fieldWidth width of the formatted field, padded by spaces.
     *                   Positive value aligns right, negative aligns left
     *
     * \a format type of floating point formatting, like in \l QString::arg
     *
     * \a precision number of digits after the decimal separator
     *
     * \a fillChar the character used to fill up the empty places when
     *                 field width is greater than argument width
     *
     * Returns value + unit string
     **/
    QString toSymbolString(qreal value, int fieldWidth = 0, char format = 'g', int precision = -1, const QChar &fillChar = QLatin1Char(' ')) const;

protected:
    qreal toDefault(qreal value) const;
    qreal fromDefault(qreal value) const;

private:
    friend class UnitPrivate;
    friend class UnitCategory;
    friend class UnitCategoryPrivate;
    friend class CurrencyCategoryPrivate;

    KUNITCONVERSION_NO_EXPORT explicit Unit(UnitPrivate *dd);

    KUNITCONVERSION_NO_EXPORT void setUnitMultiplier(qreal multiplier);

    QExplicitlySharedDataPointer<UnitPrivate> d;
};

} // KUnitConversion namespace

Q_DECLARE_TYPEINFO(KUnitConversion::Unit, Q_RELOCATABLE_TYPE);

#endif
