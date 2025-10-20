#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 3)
		throw (std::invalid_argument("Error: not enough arguments"));

	fillContainers(argv);
}

PmergeMe::PmergeMe(const PmergeMe &src):
	input(src.getInput()),
	vec(src.getVec()),
	li(src.getLi())
{

}

PmergeMe::~PmergeMe()
{

}


PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	input = src.getInput();
	vec = src.getVec();
	li = src.getLi();

	return (*this);
}


std::vector<int>	PmergeMe::getInput() const
{
	return (input);
}

std::vector<int>	PmergeMe::getVec() const
{
	return (vec);
}

std::list<int>		PmergeMe::getLi() const
{
	return (li);
}


void				PmergeMe::fillContainers(char **argv)
{
	char	*endPtr;

	for (int i = 1; argv[i]; i++)
	{
		std::string	inputStr = argv[i];

		if (inputStr.find_first_not_of("0123456789") != inputStr.npos)
			throw (std::invalid_argument("Error: Invalid input argument: forbidden character"));
		
		long	value = strtol(argv[i], &endPtr, 10);

		if (endPtr == argv[i] || *endPtr == '\0')
			throw (std::invalid_argument("Error: Invalid input argument: not a valid number"));

		if (value > INT_MAX || value < 0)
			throw (std::invalid_argument("Error: Invalid input argument: positive integers only"));
		
		if (std::find(input.begin(), input.end(), static_cast<unsigned int>(value)) != input.end())
			throw (std::invalid_argument("Error: Invalid input argument: duplicate found"));

		input.push_back(value);
		vec.push_back(value);
		li.push_back(value);

	}

}
