#include "../include/temperature_converter.h"

long double convert_from_kelvin(const long double value, const cnv::TemperatureUnit unit_to)
{
    if (unit_to == cnv::TemperatureUnit::CELSIUS) {
        return value - cnv::celsius_shift;
        std::cout << "celsius to\n";
    } else if (unit_to == cnv::TemperatureUnit::FAHRENHEIT) {
        return value * cnv::fahrenheit_ratio_to + cnv::fahrenheit_shift_to;
        std::cout << "farengeit to\n";
    } else {
        std::cout << "kelvins to\n";
        return value;
    }
}

long double convert_temp(const cnv::TemperatureUnit unit_from,
                         const cnv::TemperatureUnit unit_to,
                         const long double value)
{
    if (unit_from == unit_to) {
        return value;
    }

    if (unit_from == cnv::TemperatureUnit::CELSIUS) {
        const auto kelvin_temp = value + cnv::celsius_shift;
        return convert_from_kelvin(kelvin_temp, unit_to);
    } else if (unit_from == cnv::TemperatureUnit::FAHRENHEIT) {
        const auto kelvin_temp = value * cnv::fahrenheit_ratio_from + cnv::fahrenheit_shift_from;
        return convert_from_kelvin(kelvin_temp, unit_to);
    } else {
        return convert_from_kelvin(value, unit_to);
    }
}
