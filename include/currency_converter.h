#pragma once

#include "cnv_constants.h"

#include <unordered_map>

class CurrencyConverter {
public:
    explicit CurrencyConverter(std::unordered_map<cnv::Currency, double> &ratios);

    long double convert_currency(long double value);

    void set_curr_from(cnv::Currency currency);
    void set_curr_to(cnv::Currency currency);

private:
    std::unordered_map<cnv::Currency, double> ratios;
    cnv::Currency curr_from, curr_to;
};
