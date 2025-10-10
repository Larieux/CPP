#include "ScalarConverter.hpp"

int main()
{
	std::string input;

	input.assign("");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("12.0ff");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("-inf");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("5.4f");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("6.3");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("inf");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("nanf");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("n");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("2147483648");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("-2147483648");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
	std::cout << "\n" << std::endl;

	input.assign("hello");
	std::cout << "input value: [" << input << "]" << std::endl;
	ScalarConverter::convert(input);
	input.clear();
}