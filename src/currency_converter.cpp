#include "../include/currency_converter.h"

CurrencyConverter::CurrencyConverter(std::unordered_map<cnv::Currency, double> &ratios) {
    this->ratios = std::move(ratios);
    curr_from = cnv::Currency::USD;
    curr_to = cnv::Currency::USD;
}

long double CurrencyConverter::convert_currency(const long double value) {
    return value / this->ratios[curr_from] * this->ratios[curr_to];
}

void CurrencyConverter::set_curr_from(const cnv::Currency currency) {
    curr_from = currency;
}

void CurrencyConverter::set_curr_to(const cnv::Currency currency) {
    curr_to = currency;
}
