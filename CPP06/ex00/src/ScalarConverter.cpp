#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	(void)src;
	return (*this);
}

static bool isvalid(const std::string &input, char *end)
{
	if (input == "-inff" || input == "+inff" || input == "-inf" || input == "+inf"
		|| input == "nanf" || input == "nan")
		return (true);

	if (end[0] == '\0')
		return (true);

	if (end[0] != 'f')
		return (false);

	std::size_t index = input.find(end);
	if (index + 1 != input.length())
		return (false);
	return (true);
}

static void convertToChar(double value, std::stringstream &output, char *end, const std::string &input)
{
	long lValue = static_cast<long>(value);
	if (input.c_str() == end || lValue < CHAR_MIN || lValue > CHAR_MAX) {
		output << IMPOSSIBLE;
		return;
	}
	if (lValue < 0 || lValue > 127 || !isprint(lValue)) {
		output << NON_DISPLAYABLE;
	}
	else {
		output << '\'' << static_cast<char>(lValue) << '\'';
	}
}

static void convertToInt(double value, std::stringstream &output, char *end, const std::string &input)
{
	long lValue = static_cast<long>(value);
	if (input.c_str() == end || lValue < INT_MIN || lValue > INT_MAX || !isvalid(input, end)) {
		output << IMPOSSIBLE;
	}
	else {
		output << static_cast<int>(value);
	}
}

static void convertToFloat(double value, std::stringstream &output, char *end, const std::string &input)
{
	if (input.c_str() == end || errno == ERANGE || ((value < -FLT_MAX || value > FLT_MAX) && !isinf(value)) || !isvalid(input, end)) {
		output << IMPOSSIBLE;
	}
	else if (static_cast<float>(value) == ceilf(static_cast<float>(value)) && !isinf(value)) {
		output << std::fixed << std::setprecision(0) << static_cast<float>(value) << ".0f";
	}
	else {
		output << static_cast<float>(value) << "f";
	}
}

static void convertToDouble(double value, std::stringstream &output, char *end, const std::string &input)
{
	if (input.c_str() == end || errno == ERANGE || !isvalid(input, end)) {
		output << IMPOSSIBLE;
	}
	else if (value == ceil(value) && !isinf(value)) {
		output << std::fixed << std::setprecision(0) << value << ".0";
	}
	else {
		output << value;
	}
}

void ScalarConverter::convert(const std::string &input)
{
	std::stringstream convertInput[4];
	char *end;
	double value = strtod(input.c_str(), &end);

	if (input.length() == 1 && isprint(input[0]) && !std::isdigit(input[0])) {
		value = static_cast<double>(input[0]);
		std::cout << "char: '" << input << "'" << std::endl;
		std::cout << "int: " << value << std::endl;
		std::cout << "float: " << value << ".0f" << std::endl;
		std::cout << "double: " << value << ".0" << std::endl;
		return ;
	}

	convertToChar(value, convertInput[CHAR], end, input);
	convertToInt(value, convertInput[INT], end, input);
	convertToFloat(value, convertInput[FLOAT], end, input);
	convertToDouble(value, convertInput[DOUBLE], end, input);

	std::cout << "char: " << convertInput[CHAR].str() << std::endl;
	std::cout << "int: " << convertInput[INT].str() << std::endl;
	std::cout << "float: " << convertInput[FLOAT].str() << std::endl;
	std::cout << "double: " << convertInput[DOUBLE].str() << std::endl;
}
