#include "ScalarConverter.hpp"

int main()
{
    ScalarConverter::convert("");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("1");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("5.4f");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("6.3");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("inf");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("n");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("2147483648");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("-2147483648");
    std::cout << "----------------------" << std::endl;
    ScalarConverter::convert("hello");
}