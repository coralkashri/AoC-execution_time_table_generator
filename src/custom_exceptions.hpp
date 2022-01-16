#ifndef AOC_EXECUTION_TIME_TABLE_GENERATOR_CUSTOM_EXCEPTIONS_HPP
#define AOC_EXECUTION_TIME_TABLE_GENERATOR_CUSTOM_EXCEPTIONS_HPP

#include <exception>
#include <string>

class input_file_syntax_error : public std::exception {
public:
    input_file_syntax_error(std::string line, std::string error_details)
    : msg("Syntax error detected in input file.\n Line: '" + line + "'.\nError details: " + error_details + ".") {}

    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

class input_file_not_received : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Input file not received as executable argument.";
    }
};

class input_file_not_found : public std::exception {
public:
    explicit input_file_not_found(std::string input_file)
    : msg("Input file('" + input_file + "') not found.") {}

    [[nodiscard]] const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};

#endif