#include "../include/distance_converter.h"

static long double to_meters(const cnv::DistanceUnit unit, const long double value) {
    static const std::map<cnv::DistanceUnit, long double> conversion_factors = {
        {cnv::DistanceUnit::KILOMETER, 1000.0},
        {cnv::DistanceUnit::METER, 1.0},
        {cnv::DistanceUnit::DECIMETER, 0.1},
        {cnv::DistanceUnit::CENTIMETER, 0.01},
        {cnv::DistanceUnit::MILLIMETER, 0.001},
        {cnv::DistanceUnit::MICROMETER, 1e-6},
        {cnv::DistanceUnit::NANOMETER, 1e-9},
        {cnv::DistanceUnit::NAUTICAL_MILE, 1852.0},
        {cnv::DistanceUnit::MILE, 1609.344},
        {cnv::DistanceUnit::YARD, 0.9144},
        {cnv::DistanceUnit::FOOT, 0.3048},
        {cnv::DistanceUnit::INCH, 0.0254},
        {cnv::DistanceUnit::ASTRONOMICAL_UNIT, 149597870700.0},
        {cnv::DistanceUnit::LIGHT_YEAR, 9460730472580800.0},
        {cnv::DistanceUnit::PARSEC, 3.08567758149137e16},
        {cnv::DistanceUnit::VERSTA, 1066.8},
        {cnv::DistanceUnit::SAZHEN, 2.1336},
        {cnv::DistanceUnit::ARSHIN, 0.7112},
        {cnv::DistanceUnit::LOKOT, 0.46},
        {cnv::DistanceUnit::VERSHOK, 0.04445}
    };

    const auto it = conversion_factors.find(unit);
    return value * it->second;
}

static long double from_meters(const cnv::DistanceUnit unit, const long double value_in_meters) {
    static const std::map<cnv::DistanceUnit, long double> conversion_factors = {
        {cnv::DistanceUnit::KILOMETER, 1.0 / 1000.0},
        {cnv::DistanceUnit::METER, 1.0},
        {cnv::DistanceUnit::DECIMETER, 10.0},
        {cnv::DistanceUnit::CENTIMETER, 100.0},
        {cnv::DistanceUnit::MILLIMETER, 1000.0},
        {cnv::DistanceUnit::MICROMETER, 1e6},
        {cnv::DistanceUnit::NANOMETER, 1e9},
        {cnv::DistanceUnit::NAUTICAL_MILE, 1.0 / 1852.0},
        {cnv::DistanceUnit::MILE, 1.0 / 1609.344},
        {cnv::DistanceUnit::YARD, 1.0 / 0.9144},
        {cnv::DistanceUnit::FOOT, 1.0 / 0.3048},
        {cnv::DistanceUnit::INCH, 1.0 / 0.0254},
        {cnv::DistanceUnit::ASTRONOMICAL_UNIT, 1.0 / 149597870700.0},
        {cnv::DistanceUnit::LIGHT_YEAR, 1.0 / 9460730472580800.0},
        {cnv::DistanceUnit::PARSEC, 1.0 / 3.08567758149137e16},
        {cnv::DistanceUnit::VERSTA, 1.0 / 1066.8},
        {cnv::DistanceUnit::SAZHEN, 1.0 / 2.1336},
        {cnv::DistanceUnit::ARSHIN, 1.0 / 0.7112},
        {cnv::DistanceUnit::LOKOT, 1.0 / 0.46},
        {cnv::DistanceUnit::VERSHOK, 1.0 / 0.04445}
    };

    const auto it = conversion_factors.find(unit);
    return value_in_meters * it->second;
}

long double convert_distance(const cnv::DistanceUnit unit_from, const cnv::DistanceUnit unit_to, const long double value) {
    if (unit_from == unit_to) return value;
    const long double value_in_meters = to_meters(unit_from, value);
    return from_meters(unit_to, value_in_meters);
}
