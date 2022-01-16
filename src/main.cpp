#include "tools/base_includes.h"
#include "custom_exceptions.hpp"
#include "table_generator.hpp"

std::string validate_input_arguments(int argc, const char* argv[]) {
    if (argc < 2) throw input_file_not_received();
    if (!std::filesystem::exists(argv[1])) throw input_file_not_found(argv[1]);

    return argv[1];
}

int main(int argc, const char* argv[]) {
    auto filename = validate_input_arguments(argc, argv);

    table_generator generator(filename);

    generator.print_table(true);

    return 0;
}