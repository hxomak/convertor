#include "../include/ratio_loader.h"

void RatioLoader::print_content_err(const cnv::RatioLoaderErrs err_t) {
    if (err_t == cnv::RatioLoaderErrs::FileNotFound) {
        std::cout << "Program did not find file for converting. Basic ratios will be used.\n";
    } else if (err_t == cnv::RatioLoaderErrs::RatiosNotFound) {
        std::cout << "Program did not find all ratios for converting. Basic ratios will be used.\n";
    }
}

void RatioLoader::load_content_err() {
    ratios = std::move(cnv::basic_ratios);
}

void RatioLoader::manage_content_err(const cnv::RatioLoaderErrs err_t) {
    print_content_err(err_t);
    load_content_err();
}

void RatioLoader::load_ratios() {
    std::ifstream file {cnv::content_path};

    if (!file.is_open()) {
        manage_content_err(cnv::RatioLoaderErrs::FileNotFound);
        file.close();
        return;
    }

    std::string ratio;
    char *err_c;
    int i {0};

    while (file >> ratio) {
        *ratio.rbegin() = '\0';
        const double ratio_d = strtod(ratio.c_str(), &err_c);

        if (*err_c != '\0') {
            manage_content_err(cnv::RatioLoaderErrs::RatiosNotFound);
            file.close();
            return;
        }

        auto currency = static_cast<cnv::Currency>(i++);
        ratios[currency] = ratio_d;
    }

    if (ratios.size() != 10) {
        manage_content_err(cnv::RatioLoaderErrs::RatiosNotFound);
    }

    file.close();
}

std::unordered_map<cnv::Currency, double> &RatioLoader::get_ratios() {
    load_ratios();
    return ratios;
}
