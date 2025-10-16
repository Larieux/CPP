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

static int _getDayPerMonth(const unsigned int year, const unsigned int month)
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
	{
		return (false);
	}
	
	if (extractedDate[4] != '-' || extractedDate[7] != '-')
	{
		return (false);
	}

	int i = 0;
	for (; i < DATE_YEAR; i++)
	{
		if (!isdigit(extractedDate[i]))
		{
			return (false);
		}
	}

	for (i += DATE_DASH; i < DATE_YEAR + DATE_DASH_MONTH; i++)
	{
		if (!isdigit(extractedDate[i]))
		{
			return (false);
		}
	}

	for (i += DATE_DASH;
			i < DATE_YEAR + DATE_DASH_MONTH + DATE_DASH_DAY; i++)
	{
		if (!isdigit(extractedDate[i]))
		{
			return (false);
		}
	}


	const int year = atoi(extractedDate.substr(0, 4).c_str());
	const int month = atoi(extractedDate.substr(DATE_YEAR + DATE_DASH, 2).c_str());
	const int day = atoi(extractedDate.substr(DATE_YEAR + DATE_DASH_MONTH + DATE_DASH, 2).c_str());

	if (month <= 0 || month > NB_OF_MONTH)
	{
			std::cout << "Month " << VALUE_OUT_OF_RANGE << std::endl;
			return (false);
	}

	if (day <= 0 || day > _getDayPerMonth(year, month))
	{
			std::cout << "Day " << VALUE_OUT_OF_RANGE << std::endl;
			return (false);
	}
	return (true);
}

static bool	_parseLine(std::map<std::string, float> &map, std::string line)
{
	std::istringstream	stream(line);
	std::string			extractedDate;
	std::string			extractedValue;
	float				floatValue;

	if (std::getline(stream, extractedDate, ',') && std::getline(stream, extractedValue))
	{
		extractedDate.erase(std::remove_if(extractedDate.begin(), extractedDate.end(), ::isspace), extractedDate.end());

		if (!_check_date_format(extractedDate))
		{
			std::cout << INVALID_FORMAT << " in " << DATABASE_FILE << std::endl;
			return (false);
		}
		
		std::istringstream valueStream(extractedValue);
		valueStream >> floatValue;

		if (!valueStream || valueStream.fail())
		{
			std::cout << VALUE_OUT_OF_RANGE << " in " << DATABASE_FILE << std::endl;
			return (false);
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
		std::cerr << ERROR << "wrong extension for database file." << std::endl;
	}

	if (!infile.is_open())
	{
		std::cerr << ERROR << " " << COULD_NOT_OPEN << " " << " database file." << std::endl;
		return (false);
	}

	std::string line;

	if (!std::getline(infile, line))
	{
		std::cerr << ERROR << COULD_NOT_READ << " in " << DATABASE_FILE << std::endl;
		return (false);
	}

	unsigned int i = 0;
	try
	{
		while (std::getline(infile, line))
		{
			i++;
			if (!line.empty() && !_parseLine(map, line))
				throw (CustomException<std::runtime_error>(INVALID_FORMAT, " in ", DATABASE_FILE));
		}
	}
	catch(const std::exception& e)
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

static float	findClosest(const std::map<std::string, float> &map, const std::string &extractedDate)
{
	std::map<std::string, float>::const_iterator it = map.begin();
	float closest = 0;

	for (; it != map.end(); it++)
	{
		if (extractedDate < it->first)
			break ;
		closest = it->second;
	}
	return (closest);
}

void	BitcoinExchange::convert(const std::string &file)
{
	std::ifstream	infile(file.c_str());

	if (!infile.is_open())
	{
		std::cerr << ERROR << " " << COULD_NOT_OPEN << " " << INPUT_FILE << std::endl;
		return ;
	}

	std::string	line;
	if (!std::getline(infile, line))
	{
		std::cerr << ERROR << " " << COULD_NOT_READ << " in " << INPUT_FILE << std::endl;
		return ;
	}

	while (std::getline(infile, line))
	{
		if (line.empty())
			continue;

		try
		{
			float value = 0;
			std::string extractedDate;

			size_t pipe = line.find('|');
			if (pipe != std::string::npos)
			{
				extractedDate = line.substr(0, pipe - 1);
				std::string	extractedValue = line.substr(pipe + 1);
				if (extractedValue.empty())
					throw (CustomException<std::runtime_error>(COULD_NOT_READ, " in ", INPUT_FILE));
				value = atof(extractedValue.c_str());
			}

			if (!_check_date_format(extractedDate))
				throw (CustomException<std::invalid_argument>(INVALID_FORMAT, " in ", DATABASE_FILE));

			if (value < 0 || value > 1000)
				throw (CustomException<std::runtime_error>(VALUE_OUT_OF_RANGE, " in ", INPUT_FILE));

			float rate = findClosest(map, extractedDate);

			std::cout << extractedDate << " => " << value << " = " << value * rate << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << "\n\tLine: " << line << std::endl;
		}
	}
	infile.close();
}


std::map<std::string, float>	BitcoinExchange::getMap() const
{
	return (map);
}
