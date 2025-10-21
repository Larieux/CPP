#include "PmergeMeInput.hpp"
#include "PmergeMeLi.hpp"
#include "PmergeMeVec.hpp"

int main(int argc, char **argv)
{
	try
	{
		PmergeMeInput	inputKeeper(argc, argv);
		PmergeMeVec		vecSorter(inputKeeper.getCont());
		PmergeMeLi		liSorter(inputKeeper.getCont());

		std::cout << inputKeeper << std::endl;
		std::cout << vecSorter << std::endl;
		std::cout << liSorter << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}