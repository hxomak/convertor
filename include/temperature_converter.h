#pragma once

#include "cnv_constants.h"

#include <iostream>

long double convert_temp(cnv::TemperatureUnit unit_from, cnv::TemperatureUnit unit_to, long double value);

long double convert_from_kelvin(long double value, cnv::TemperatureUnit unit_to);
