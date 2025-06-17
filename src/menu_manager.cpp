#include "../include/menu_manager.h"

#include <conio.h>

#include "../include/cnv_constants.h"

cnv::DistanceUnit MenuManager::get_dist_unit(const int input) {
    switch(input) {
        case 1:  return cnv::DistanceUnit::METER;
        case 2:  return cnv::DistanceUnit::KILOMETER;
        case 3:  return cnv::DistanceUnit::DECIMETER;
        case 4:  return cnv::DistanceUnit::CENTIMETER;
        case 5:  return cnv::DistanceUnit::MILLIMETER;
        case 6:  return cnv::DistanceUnit::MICROMETER;
        case 7:  return cnv::DistanceUnit::NANOMETER;
        case 8:  return cnv::DistanceUnit::NAUTICAL_MILE;
        case 9:  return cnv::DistanceUnit::MILE;
        case 10: return cnv::DistanceUnit::YARD;
        case 11: return cnv::DistanceUnit::FOOT;
        case 12: return cnv::DistanceUnit::INCH;
        case 13: return cnv::DistanceUnit::ASTRONOMICAL_UNIT;
        case 14: return cnv::DistanceUnit::LIGHT_YEAR;
        case 15: return cnv::DistanceUnit::PARSEC;
        case 16: return cnv::DistanceUnit::VERSTA;
        case 17: return cnv::DistanceUnit::SAZHEN;
        case 18: return cnv::DistanceUnit::ARSHIN;
        case 19: return cnv::DistanceUnit::LOKOT;
        case 20: return cnv::DistanceUnit::VERSHOK;
        default: return cnv::DistanceUnit::LOKOT;
    }
}

long double MenuManager::get_dist_conv_val() {
    std::string input;

    while (true) {
        char *err_i;

        std::cout << "|~ ";
        std::cin >> input;
        const long double value = strtold(input.c_str(), &err_i);

        if (*err_i != '\0' || value < 0) {
            std::cout << "Incorrect input. Input correct value please.\n";
            continue;
        }

        return value;
    }
}

void MenuManager::manage_dist_conv_menu()
{
    std::cout << "Choose metric unit to convert from and to, respectively:\n1) Meter\n2)"
                 " Kilometer\n3) Decimeter\n4) "
                 "Centimeter\n5) Millimeter\n6) Micrometer\n7) Nanometer\n8)"
                 " Nautical mile\n9) Mile\n10) Yard\n11)"
                 " Foot\n12) Inch\n13) Astronomical "
                 "unit\n14) Light year\n15) Parsec\n16) Versta\n17) Sazhen\n18)"
                 " Arshin\n19) Lokot\n20) Vershok\n";
    auto input = get_input(20);
    const auto unit_from = get_dist_unit(input);
    input = get_input(20);
    const auto unit_to = get_dist_unit(input);
    const auto value = get_dist_conv_val();

    const auto converted_val = convert_distance(unit_from, unit_to, value);

    std::cout << "Converted distance: " << converted_val << " " << cnv::distanceUnitPrefixes.at(unit_to) << '\n';
}

void MenuManager::print_start_welcome() {
    std::cout << "Welcome in Converter. In this program you can convert"
                 "temperature, currencies and distance.\n";
}

void MenuManager::print_start_choice() {
    std::cout << "Choose an action:\n1) Convert currency\n2) Convert temprature\n"
                 "3) Convert distance\n4) Exit program\n";
}

void MenuManager::print_curr_conv_choice(const cnv::CurrencyConvertTypes curr_t) {
    const char *curr_convert_type;
    if (curr_t == cnv::CurrencyConvertTypes::FROM) {
        curr_convert_type = "from";
    } else {
        curr_convert_type = "to";
    }
    std::cout << "Choose currency to convert " << curr_convert_type << ":\n1) USD\n2) EUR\n3) GBP\n4) JPY\n5)"
                 " CHF\n6) CNY\n7) CAD\n8) AUD\n9) BYN\n10) RUB\n";
}

void MenuManager::print_temp_conv_choice() {
    std::cout << "Enter the temperature units you want to convert from and to, respectively:\n"
                 "1) Kelvin\n2) Celsius\n3) Fahrenheit\n";
}

void MenuManager::print_curr_conv_value_input(const cnv::Currency currency) {
    std::cout << "Input amount of " << cnv::curr_to_str.at(currency) << ":\n";
}

void MenuManager::print_temp_conv_value_input() {
    std::cout << "Input temperature value:\n";
}


void MenuManager::print_curr_converted_value(const long double value, const cnv::Currency currency_to) {
    std::cout << "Converted sum of money: " << value << ' ' << cnv::curr_to_str.at(currency_to) << '\n';
}

void MenuManager::print_converted_temp(const long double value, cnv::TemperatureUnit temp_to) {
    std::cout << "Converter temperature: " << value << " " << cnv::TemperatureUnitPrefixes.at(temp_to) << '\n';
}

void MenuManager::manage_start_input(const int input) {
    switch (input) {
        case 1: {
            conv_curr();
            break;
        }
        case 2: {
            conv_temp();
            break;
        }
        case 3: {
            conv_dist();
            break;
        }
        case 4: {
            exit_menu();
            break;
        }
        default:
            break;
    }
}

cnv::Currency MenuManager::get_currency_type(const int input) {
    switch (input) {
        case 1:
            return cnv::Currency::USD;
        case 2:
            return cnv::Currency::EUR;
        case 3:
            return cnv::Currency::GBP;
        case 4:
            return cnv::Currency::JPY;
        case 5:
            return cnv::Currency::CHF;
        case 6:
            return cnv::Currency::CNY;
        case 7:
            return cnv::Currency::CAD;
        case 8:
            return cnv::Currency::AUD;
        case 9:
            return cnv::Currency::BYN;
        case 10:
            return cnv::Currency::RUB;
        default:
            return cnv::Currency::USD;
    }
}

cnv::TemperatureUnit MenuManager::get_temp_unit(const int input) {
    switch (input) {
        case 1:
            return cnv::TemperatureUnit::KELVIN;
        case 2:
            return cnv::TemperatureUnit::CELSIUS;
        case 3:
            return cnv::TemperatureUnit::FAHRENHEIT;
        default:
            return cnv::TemperatureUnit::CELSIUS;
    }
}

long double MenuManager::get_curr_conv_val() {
    std::string input;

    while (true) {
        char *err_i;

        std::cout << "|~ ";
        std::cin >> input;
        const long double value = strtold(input.c_str(), &err_i);

        if (*err_i != '\0' || value < 0) {
            std::cout << "Incorrect input. Input correct value please.\n";
            continue;
        }

        return value;
    }
}

long double MenuManager::get_temp_conv_val() {
    std::string input;

    while (true) {
        char *err_i;

        std::cout << "|~ ";
        std::cin >> input;
        const long double value = strtold(input.c_str(), &err_i);

        if (*err_i != '\0' || value < 0) {
            std::cout << "Incorrect input. Input correct value please.\n";
            continue;
        }

        return value;
    }
}

int MenuManager::get_input(const int max_range) {
    std::string input;

    while (true) {
        char *err_i;

        std::cout << "|~ ";
        std::cin >> input;
        const int answer = strtod(input.c_str(), &err_i);

        if (*err_i != '\0' || answer < 1 || answer > max_range) {
            std::cout << "Incorrect input. There is no such action.\n";
            continue;
        }

        return answer;
    }
}

void MenuManager::manage_curr_conv_menu() {
    print_curr_conv_choice(cnv::CurrencyConvertTypes::FROM);
    auto input = get_input(10);
    const auto currency_from = get_currency_type(input);
    print_curr_conv_value_input(currency_from);
    const auto value = get_curr_conv_val();
    print_curr_conv_choice(cnv::CurrencyConvertTypes::TO);
    input = get_input(10);
    const auto currency_to = get_currency_type(input);

    auto ratios = RatioLoader::get_ratios();

    CurrencyConverter currency_converter(ratios);
    currency_converter.set_curr_from(currency_from);
    currency_converter.set_curr_to(currency_to);
    const auto converted_value = currency_converter.convert_currency(value);

    print_curr_converted_value(converted_value, currency_to);
}

void MenuManager::manage_temp_conv_menu()
{
    print_temp_conv_choice();
    auto input = get_input(3);
    const auto temp_from = get_temp_unit(input);
    input = get_input(3);
    const auto temp_to = get_temp_unit(input);
    print_temp_conv_value_input();
    const auto value = get_temp_conv_val();
    const auto converted_value = convert_temp(temp_from, temp_to, value);
    print_converted_temp(converted_value, temp_to);
}

void MenuManager::start() {
    static bool is_used = false;
    if (!is_used) {
        is_used = true;
        print_start_welcome();
    }
    print_start_choice();
    const int input = get_input(4);
    manage_start_input(input);
}

void MenuManager::conv_curr() {
    manage_curr_conv_menu();
    start();
}

void MenuManager::conv_temp() {
    manage_temp_conv_menu();
    start();
}

void MenuManager::conv_dist() {
    manage_dist_conv_menu();
    start();
}

[[noreturn]] void MenuManager::exit_menu() {
    std::cout << "Program is quiting...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    exit(0);
}
