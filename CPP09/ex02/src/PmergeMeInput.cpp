#include "PmergeMeInput.hpp"

PmergeMeInput::PmergeMeInput() : PmergeMe< std::vector<int> >()
{

}

PmergeMeInput::PmergeMeInput(int argc, char **argv) : PmergeMe< std::vector<int> >()
{
	if (argc < 3)
		throw (std::invalid_argument("Not enough arguments"));

	fillInput(argv);
}

PmergeMeInput::PmergeMeInput(const PmergeMeInput &src):
	PmergeMe< std::vector<int> >(src)
{

}

PmergeMeInput::~PmergeMeInput()
{

}

void	PmergeMeInput::fillInput(char **argv)
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
