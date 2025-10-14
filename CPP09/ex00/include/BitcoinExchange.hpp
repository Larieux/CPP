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

#define INVALID_FORMAT "format invalid in data file."

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

	class ExceptionInvalidNumber : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

private:
	std::map<std::string, float> map;
};

#endif