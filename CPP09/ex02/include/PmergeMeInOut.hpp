#ifndef PMERGEMEINOUT_HPP
# define PMERGEMEINOUT_HPP

#include "PmergeMe.hpp"

class PmergeMeInOut : public PmergeMe< std::vector<unsigned int> >
{
public:
	PmergeMeInOut();
	PmergeMeInOut(int argc = 0, char **argv = NULL);
	PmergeMeInOut(const PmergeMeInOut &src);
	virtual ~PmergeMeInOut();

	PmergeMeInOut &operator=(const PmergeMeInOut &src);

	long	getTimeVector() const;
	long	getTimeList() const;

	std::vector<unsigned int>	getSortedVec() const;
	std::list<unsigned int>		getSortedLi() const;

	void	fillInput(char **argv);
	void	fillTimes(struct timespec timeInit, struct timespec timeToFill,
				struct timespec timeVec, struct timespec timeLi);

	void	setSortedVec(std::vector<unsigned int> outVec);
	void	setSortedLi(std::list<unsigned int> outLi);

	void	printOutput(int argc);

private:
	long			timeVector, timeList;

	std::vector<unsigned int>	sortedVec;
	std::list<unsigned int>		sortedLi;

};

std::ostream& operator<<(std::ostream& out, const std::vector<unsigned int> &src);

std::ostream& operator<<(std::ostream& out, const std::list<unsigned int> &src);

#endif