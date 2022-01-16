#ifndef AOC_EXECUTION_TIME_TABLE_GENERATOR_TABLE_GENERATOR_H
#define AOC_EXECUTION_TIME_TABLE_GENERATOR_TABLE_GENERATOR_H

#include <string>
#include <array>

class table_generator {
public:
    explicit table_generator(std::string_view file_name);

    void print_table(bool include_empty_days);

private:
    std::array<std::pair<std::string, std::string>, 25> days_details;

    std::string produce_table(bool include_empty_days);

    uint8_t get_day_number_from_input(std::string day_input_line);

    std::string get_part_from_input_line(std::string part, size_t separator_place);
};

#endif