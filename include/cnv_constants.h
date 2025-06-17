#pragma once

#include <unordered_map>
#include <string>

namespace cnv {

constexpr auto content_path = "../content/ratios.txt";

enum class RatioLoaderErrs {
    FileNotFound,
    RatiosNotFound
};

enum class CurrencyConvertTypes {
    FROM,
    TO
};

enum class TemperatureUnit {
    KELVIN,
    CELSIUS,
    FAHRENHEIT
};

inline const std::unordered_map<TemperatureUnit, std::string> TemperatureUnitPrefixes = {
    {TemperatureUnit::KELVIN,    "K"},
    {TemperatureUnit::CELSIUS,   "C"},
    {TemperatureUnit::FAHRENHEIT,"F"}
};

constexpr auto celsius_shift = 273.15;
constexpr auto fahrenheit_ratio_to = 1.8;
constexpr auto fahrenheit_shift_to = -459.67;
constexpr auto fahrenheit_ratio_from = 0.555555;
constexpr auto fahrenheit_shift_from = 255.372222;

    enum class DistanceUnit {
        KILOMETER,
        METER,
        DECIMETER,
        CENTIMETER,
        MILLIMETER,
        MICROMETER,
        NANOMETER,
        NAUTICAL_MILE,
        MILE,
        YARD,
        FOOT,
        INCH,
        ASTRONOMICAL_UNIT,
        LIGHT_YEAR,
        PARSEC,
        VERSTA,
        SAZHEN,
        ARSHIN,
        LOKOT,
        VERSHOK
    };

    inline const std::unordered_map<DistanceUnit, std::string> distanceUnitPrefixes = {
        {DistanceUnit::KILOMETER, "km"},
        {DistanceUnit::METER, "m"},
        {DistanceUnit::DECIMETER, "dm"},
        {DistanceUnit::CENTIMETER, "cm"},
        {DistanceUnit::MILLIMETER, "mm"},
        {DistanceUnit::MICROMETER, "µm"},
        {DistanceUnit::NANOMETER, "nm"},
        {DistanceUnit::NAUTICAL_MILE, "nmi"},
        {DistanceUnit::MILE, "mi"},
        {DistanceUnit::YARD, "yd"},
        {DistanceUnit::FOOT, "ft"},
        {DistanceUnit::INCH, "in"},
        {DistanceUnit::ASTRONOMICAL_UNIT, "au"},
        {DistanceUnit::LIGHT_YEAR, "ly"},
        {DistanceUnit::PARSEC, "pc"},
        {DistanceUnit::VERSTA, "versta"},
        {DistanceUnit::SAZHEN, "sazhen"},
        {DistanceUnit::ARSHIN, "arshin"},
        {DistanceUnit::LOKOT, "lokot"},
        {DistanceUnit::VERSHOK, "vershok"}
    };

enum class Currency {
    USD,  // Доллар США
    EUR,  // Евро
    GBP,  // Фунт стерлингов
    JPY,  // Японская иена
    CHF,  // Швейцарский франк
    CNY,  // Китайский юань
    CAD,  // Канадский доллар
    AUD,  // Австралийский доллар
    BYN,  // Белорусский рубль
    RUB   // Российский рубль
};

inline const std::unordered_map<Currency, std::string> curr_to_str {
        {Currency::USD, "USD"},
        {Currency::EUR, "EUR"},
        {Currency::GBP, "GBP"},
        {Currency::JPY, "JPY"},
        {Currency::CHF, "CHF"},
        {Currency::CNY, "CNY"},
        {Currency::CAD, "CAD"},
        {Currency::AUD, "AUD"},
        {Currency::BYN, "BYN"},
        {Currency::RUB, "RUB"}
};

inline std::unordered_map<Currency, double> basic_ratios {   // Might be moved into CurrencyConvManager
        {Currency::USD, 1.0000},
        {Currency::EUR, 0.9300},
        {Currency::GBP, 0.7900},
        {Currency::JPY, 156.0000},
        {Currency::CHF, 0.8900},
        {Currency::CNY, 7.2500},
        {Currency::CAD, 1.3700},
        {Currency::AUD, 1.5200},
        {Currency::BYN, 3.2300},
        {Currency::RUB, 90.0000}
};

}
