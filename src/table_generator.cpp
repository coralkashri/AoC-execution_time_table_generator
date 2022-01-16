#include "table_generator.hpp"
#include "tools/base_includes.h"
#include "custom_exceptions.hpp"

table_generator::table_generator(std::string_view file_name) {
    std::ifstream input_file(file_name.begin());
    std::for_each(std::istream_iterator<WordDelimitedBy<'\n' >>(input_file), std::istream_iterator<WordDelimitedBy<'\n' >>(), [this, current_day = 1](std::string str) mutable {
        if (str.empty()) return;
        if (auto separator_place = str.find(':'); separator_place == std::string::npos) { // Day number
            current_day = get_day_number_from_input(str) - 1;
        } else { // First / Second part
            auto part_data = str.substr(separator_place + 1);
            auto part = get_part_from_input_line(str, separator_place);
            if (part == "first") days_details[current_day].first = part_data;
            else days_details[current_day].second = part_data;
        }
    });
}

void table_generator::print_table(bool include_empty_days) {
    std::cout << produce_table(include_empty_days) << std::endl;
}

std::string table_generator::produce_table(bool include_empty_days) {
    std::stringstream table_res;
    table_res << "| Day | First Part | Second Part |\n"
                 "| --- | ---------- | ----------- |\n";
    uint8_t day = 1;
    for (const auto &[first, second] : days_details) {
        if (include_empty_days || !first.empty() || !second.empty()) {
            table_res << "| [" << (int)day << "](./day_" << (int)day << ".hpp) | " << first << " | " << second << " |\n";
        }
        ++day;
    }
    return table_res.str();
}

uint8_t table_generator::get_day_number_from_input(std::string day_input_line) {
    std::regex number_regex(R"([\d][\d]?)");
    std::smatch number;
    if (!std::regex_search(day_input_line, number, number_regex))
        throw input_file_syntax_error(day_input_line, "Expected day_input_line number, could not find a number");
    auto actual_number = std::stoi(number.str());
    if (actual_number < 1 || actual_number > 25)
        throw input_file_syntax_error(day_input_line, "Expected day_input_line number (1-25), found more than two (2) digits");
    return actual_number;
}

std::string table_generator::get_part_from_input_line(std::string part_line, size_t separator_place) {
    auto part = part_line.substr(0, separator_place);
    std::erase_if(part, [](char c) { return c == ' '; });
    std::transform(part.begin(), part.end(), part.begin(), [](unsigned char c) { return std::tolower(c); });
    if (part != "first" && part != "second") throw input_file_syntax_error(part_line, "Unrecognized part");
    return part;
}