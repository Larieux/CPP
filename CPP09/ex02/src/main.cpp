#include "PmergeMeInOut.hpp"
#include "PmergeMeLi.hpp"
#include "PmergeMeVec.hpp"

int main(int argc, char **argv)
{
	struct timespec	timeInit, timeToFill, timeVec, timeLi;

	clock_gettime(CLOCK_REALTIME, &timeInit);

	try
	{
		PmergeMeInOut	inOutKeeper(argc, argv);

		clock_gettime(CLOCK_REALTIME, &timeToFill);

		PmergeMeVec		vecSorter(inOutKeeper.getCont());
		inOutKeeper.setSortedVec(vecSorter.sortVec());

		clock_gettime(CLOCK_REALTIME, &timeVec);

		PmergeMeLi		liSorter(inOutKeeper.getCont());
		inOutKeeper.setSortedLi(liSorter.sortLi());

		clock_gettime(CLOCK_REALTIME, &timeLi);

		std::cout << "Before:\t" << inOutKeeper << std::endl;
		std::cout << "AfterV:\t" << vecSorter << std::endl;
		std::cout << "AfterL:\t" << liSorter << std::endl;

		inOutKeeper.fillTimes(timeInit, timeToFill, timeVec, timeLi);

		inOutKeeper.printOutput(argc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}