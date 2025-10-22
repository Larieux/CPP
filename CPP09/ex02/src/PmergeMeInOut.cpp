#include "PmergeMeInOut.hpp"

PmergeMeInOut::PmergeMeInOut() : PmergeMe< std::vector<unsigned int> >()
{

}

PmergeMeInOut::PmergeMeInOut(int argc, char **argv) : PmergeMe< std::vector<unsigned int> >()
{
	if (argc < 3)
		throw (std::invalid_argument("Not enough arguments"));

	fillInput(argv);
}

PmergeMeInOut::PmergeMeInOut(const PmergeMeInOut &src):
	PmergeMe< std::vector<unsigned int> >(src)
{
	*this = src;
}

PmergeMeInOut::~PmergeMeInOut()
{

}


PmergeMeInOut &PmergeMeInOut::operator=(const PmergeMeInOut &src)
{
	_cont = src.getCont();
	sortedVec = src.getSortedVec();
	sortedLi = src.getSortedLi();
	timeVector = src.getTimeVector();
	timeList = src.getTimeList();

	return (*this);
}


long	PmergeMeInOut::getTimeVector() const
{
	return (timeVector);
}
long	PmergeMeInOut::getTimeList() const
{
	return (timeList);
}

std::vector<unsigned int>	PmergeMeInOut::getSortedVec() const
{
	return (sortedVec);
}

std::list<unsigned int>		PmergeMeInOut::getSortedLi() const
{
	return (sortedLi);
}


void	PmergeMeInOut::fillInput(char **argv)
{
	char	*endPtr;

	for (int i = 1; argv[i]; i++)
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

void	PmergeMeInOut::fillTimes(struct timespec timeInit, struct timespec timeToFill,
			struct timespec timeVec, struct timespec timeLi)
{
	timeVector = timeVec.tv_nsec - timeInit.tv_nsec;
	timeList = (timeLi.tv_nsec - timeVec.tv_nsec) + (timeToFill.tv_nsec - timeInit.tv_nsec);
}


void	PmergeMeInOut::setSortedVec(const std::vector<unsigned int> outVec)
{
	for (std::vector<unsigned int>::const_iterator it = outVec.begin(); it != outVec.end(); it++)
	{
		sortedVec.push_back(*it);
	}
}

void	PmergeMeInOut::setSortedLi(const std::list<unsigned int> outLi)
{
	for (std::list<unsigned int>::const_iterator it = outLi.begin(); it != outLi.end(); it++)
	{
		sortedLi.push_back(*it);
	}
}

			
void	PmergeMeInOut::printOutput(int argc)
{
	std::cout	<< "Before:\t\t" << _cont << "\n"
				<< "After (v):\t" << sortedVec << "\n"
				<< "After (d):\t" << sortedLi << "\n"
				<< "Time to process a range of " << argc << " elements with std::vector:  " 
				<< timeVector * 1000 << " µs" << "\n"
				<< "Time to process a range of " << argc << " elements with std::list:   " 
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
