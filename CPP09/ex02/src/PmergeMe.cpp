#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 3)
		throw (std::invalid_argument("Not enough arguments"));

	fillInput(argv);
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{
	_cont.clear();
}


PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	_cont.clear();
	_cont = src.getCont();
	sortedVec = src.getSortedVec();
	sortedLi = src.getSortedLi();
	timeVector = src.getTimeVector();
	timeList = src.getTimeList();

	return (*this);
}


std::vector<unsigned int>	PmergeMe::getCont() const
{
	return (_cont);
}


void	PmergeMe::clearLi()
{
	_cont.clear();
}


long	PmergeMe::getTimeVector() const
{
	return (timeVector);
}

long	PmergeMe::getTimeList() const
{
	return (timeList);
}

std::vector<unsigned int>	PmergeMe::getSortedVec() const
{
	return (sortedVec);
}

std::list<unsigned int>		PmergeMe::getSortedLi() const
{
	return (sortedLi);
}


void	PmergeMe::fillInput(char **argv)
{
	char	*endPtr;

	_cont.clear();

	for (int i = 1; argv[i] && argv[i] != '\0'; i++)
	{
		std::string	inputStr = argv[i];

		if (inputStr.find_first_not_of("0123456789") != inputStr.npos)
			throw (std::invalid_argument("Error: Invalid input argument: forbidden character"));
		
		long	value = strtol(argv[i], &endPtr, 10);

		if (endPtr == argv[i] || *endPtr != '\0')
			throw (std::invalid_argument("Error: Invalid input argument: not a valid number"));

		if (value > INT_MAX || value < 0)
			throw (std::invalid_argument("Error: Invalid input argument: positive integers only"));
		
		if (std::find(_cont.begin(), _cont.end(), static_cast<unsigned int>(value)) != _cont.end())
			throw (std::invalid_argument("Error: Invalid input argument: duplicate found"));

		_cont.push_back(value);
	}
}

void	PmergeMe::fillTimes(struct timespec timeInit, struct timespec timeToFill,
			struct timespec timeVec, struct timespec timeLi)
{
	timeVector = timeVec.tv_nsec - timeInit.tv_nsec;
	timeList = (timeLi.tv_nsec - timeVec.tv_nsec) + (timeToFill.tv_nsec - timeInit.tv_nsec);
}


void	PmergeMe::setSortedVec(const std::vector<unsigned int> outVec)
{
	for (std::vector<unsigned int>::const_iterator it = outVec.begin(); it != outVec.end(); it++)
	{
		sortedVec.push_back(*it);
	}
}

void	PmergeMe::setSortedLi(const std::list<unsigned int> outLi)
{
	for (std::list<unsigned int>::const_iterator it = outLi.begin(); it != outLi.end(); it++)
	{
		sortedLi.push_back(*it);
	}
}

			
void	PmergeMe::printOutput(int argc)
{
	std::cout	<< "Before:\t\t" << _cont << "\n"
				<< "After (v):\t" << sortedVec << "\n"
				<< "After (l):\t" << sortedLi << "\n"
				<< "Time to process a range of " << argc << "\telements with std::vector:\t" 
				<< timeVector * 1000 << " µs" << "\n"
				<< "Time to process a range of " << argc << "\telements with std::list:\t" 
				<< timeList * 1000 << " µs" << std::endl;
}


std::ostream& operator<<(std::ostream& out, const std::vector<unsigned int> &src)
{
	std::vector<unsigned int>	tmpVec = src;

	for (std::vector<unsigned int>::const_iterator it = tmpVec.begin(); it != tmpVec.end(); it++)
		out << *it << " ";

	return (out);
}

std::ostream& operator<<(std::ostream& out, const std::list<unsigned int> &src)
{
	std::list<unsigned int>	tmpLi = src;

	for (std::list<unsigned int>::const_iterator it = tmpLi.begin(); it != tmpLi.end(); it++)
		out << *it << " ";

	return (out);
}
