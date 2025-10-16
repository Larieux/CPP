#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <cstdlib>
#include <cctype>

#define DATA_FILE "data.csv"

#define ERROR "Error: "
#define COULD_NOT_OPEN "could not open"
#define INVALID_FORMAT "Invalid format"
#define COULD_NOT_READ "could not read first line"
#define VALUE_OUT_OF_RANGE "value out of range"

#define DATABASE_FILE "database file"
#define INPUT_FILE "input file"

#define DATE_YEAR 4
#define DATE_DASH_MONTH 3
#define DATE_DASH_DAY 3
#define DATE_DASH 1
#define NB_OF_MONTH 12

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange &operator=(BitcoinExchange const &src);
	~BitcoinExchange();

	bool	parseData(std::string const &file);
	void	convert(std::string const &file);

	std::map<std::string, float>	getMap() const;

private:
	std::map<std::string, float> map;
};

#endif