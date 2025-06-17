#pragma once

#include "cnv_constants.h"

#include <unordered_map>
#include <fstream>
#include <string>
#include <iostream>

class RatioLoader {
public:
    static std::unordered_map<cnv::Currency, double> &get_ratios();

private:
    static void load_ratios();

    static void print_content_err(cnv::RatioLoaderErrs err_t);

    static void manage_content_err(cnv::RatioLoaderErrs err_t);
    static void load_content_err();

    inline static std::unordered_map<cnv::Currency, double> ratios;
};
