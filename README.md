# KUnitConversion

Converting physical units

## Introduction

KUnitConversion provides functions to convert values in different physical
units. It supports converting different prefixes (e.g. kilo, mega, giga) as
well as converting between different unit systems (e.g. liters, gallons). The
following areas are supported:

* Acceleration
* Angle
* Area
* Currency
* Density
* Energy
* Force
* Frequency
* Fuel efficiency
* Length
* Mass
* Power
* Pressure
* Temperature
* Time
* Velocity
* Volume

## Usage

To convert 100 GBP into EUR, you can write:

    using namespace KUnitConversion;
    Value pounds(100, Gbp);
    Value eur = pounds.convertTo(Eur);

