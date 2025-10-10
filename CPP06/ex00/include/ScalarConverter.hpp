#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <sstream> 
#include <limits>

#define IMPOSSIBLE "impossible"
#define NON_DISPLAYABLE "Non displayable"

enum InputIndex {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter
{
public:
	~ScalarConverter();

	static void convert(const std::string &src);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	ScalarConverter &operator=(const ScalarConverter &src);
};

#endif