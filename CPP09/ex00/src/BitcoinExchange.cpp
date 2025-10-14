#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
	{
		map.clear();
		map = src.getMap();
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

static bool	_extensionCorrect(std::string file)
{
	size_t	dot = file.find(".");

	if (dot == std::string::npos || dot == 0)
		return (false);

	std::string extension = file.substr(dot + 1);

	return (extension == "csv");
}

static bool _isLeapYear(const unsigned int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return (true);
	}
	return (false);
}

static bool _getDayPerMonth(const unsigned int year, const unsigned int month)
{
	static const unsigned int daysInMonth[] = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};

	if (month == 2 && _isLeapYear(year) == true) {
		return (29);
	}
	return (daysInMonth[month - 1]);
}

static bool _check_date_format(std::string	extractedDate)
{
	if (extractedDate.length() != 10)
		return (false);
	
	if (extractedDate[4] != '-' || extractedDate[7] != '-')
		return (false);

	int i = 0;
	for (; i < DATE_YEAR; i++)
	{
		if (!isdigit(extractedDate[i]))
			return (false);
	}

	for (i += DATE_DASH; i < DATE_YEAR + DATE_DASH_MONTH; i++)
	{
		if (!isdigit(extractedDate[i]))
			return (false);
	}

	for (i += DATE_DASH;
			i < DATE_YEAR + DATE_DASH_MONTH + DATE_DASH_DAY; i++)
	{
		if (!isdigit(extractedDate[i]))
			return (false);
	}


	const int year = atoi(extractedDate.substr(0, 4).c_str());
	const int month = atoi(extractedDate.substr(DATE_YEAR + DATE_DASH, 2).c_str());
	const int day = atoi(extractedDate.substr(DATE_YEAR + DATE_DASH_MONTH + DATE_DASH, 2).c_str());

	if (month <= 0 || NB_OF_MONTH < month) {
		throw (std::out_of_range("Month value out of range"));
	}

	if (day <= 0 || _getDayPerMonth(year, month) < day) {
		throw (std::out_of_range("Day value out of range"));
	}
	return (true);
}

static bool	_parseLine(std::map<std::string, float> map, std::string line)
{
	std::istringstream	stream(line);
	std::string			extractedDate;
	std::string			extractedValue;
	// std::string			delimiter = ",";
	float				floatValue;

	if (std::getline(stream, extractedDate, ',') && std::getline(stream, extractedValue))
	{
		extractedDate.erase(std::remove_if(extractedDate.begin(), extractedDate.end(), ::isspace), extractedDate.end());

		if (!_check_date_format(extractedDate))
			throw std::invalid_argument(INVALID_FORMAT);
		
		std::istringstream valueStream(extractedValue);
		valueStream >> floatValue;

		if (!valueStream || valueStream.fail()) {
			throw std::out_of_range("Value out of range");
		}

		map[extractedDate] = floatValue;
		return (true);
	}
	return (false);
}

bool	BitcoinExchange::parseData(std::string const &file)
{
	std::ifstream	infile(file.c_str());

	if (!_extensionCorrect(file))
	{
		std::cerr << "Error: wrong extension" << std::endl;
	}

	if (!infile.is_open())
	{
		std::cerr << "Error: Couldn't open database file." << std::endl;
		return (false);
	}

	std::string line;

	if (!std::getline(infile, line))
	{
		std::cerr << "Error: couldn't read first line." << std::endl;
		return (false);
	}

	unsigned int i = 0;
	try
	{
		while (std::getline(infile, line))
		{
			i++;
			if (!line.empty() && !_parseLine(map, line))
				throw (std::runtime_error("Invalid data format"));
		}
	}
	catch(const std::runtime_error& e)
	{
		std::cerr	<< file
					<< ": line " << i << ": " << e.what()
					<< "\n\t[" << line << "]"
					<< std::endl;
		return (false);
	}
	
	infile.close();
	return (true);
}

void	BitcoinExchange::convert(std::string const &file)
{
	(void) file;
}


std::map<std::string, float>	BitcoinExchange::getMap() const
{
	return (map);
}