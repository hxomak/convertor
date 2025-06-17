#pragma once

#include "cnv_constants.h"
#include "currency_converter.h"
#include "ratio_loader.h"
#include "temperature_converter.h"
#include "distance_converter.h"

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

class MenuManager
{
public:
    static void start();
    static void conv_curr();
    static void conv_dist();
    static void conv_temp();
    [[noreturn]] static void exit_menu();

private:
    static int get_input(int max_range);

    static void print_start_welcome();
    static void print_start_choice();
    static void manage_start_input(int input);

    static void manage_curr_conv_menu();
    static void print_curr_conv_choice(cnv::CurrencyConvertTypes curr_t);
    static void print_curr_conv_value_input(cnv::Currency currency);
    static void print_curr_converted_value(long double value, cnv::Currency currency_to);
    static cnv::Currency get_currency_type(int input);
    static long double get_curr_conv_val();

    static void manage_temp_conv_menu();
    static void print_temp_conv_choice();
    static void print_temp_conv_value_input();
    static cnv::TemperatureUnit get_temp_unit(int input);
    static long double get_temp_conv_val();
    static void print_converted_temp(long double value, cnv::TemperatureUnit temp_to);

    static void manage_dist_conv_menu();
    static cnv::DistanceUnit get_dist_unit(int input);
    static long double get_dist_conv_val();
};
