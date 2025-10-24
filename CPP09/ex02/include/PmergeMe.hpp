#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <limits>
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(int argc = 0, char **argv = NULL);
	PmergeMe(const PmergeMe &src);
	virtual ~PmergeMe();

	PmergeMe &operator=(const PmergeMe &src);

	std::vector<unsigned int>	getCont() const;

	void	clearLi();

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
	std::vector<unsigned int>	_cont;
	long						timeVector, timeList;

	std::vector<unsigned int>	sortedVec;
	std::list<unsigned int>		sortedLi;

};

std::ostream& operator<<(std::ostream& out, const std::vector<unsigned int> &src);

std::ostream& operator<<(std::ostream& out, const std::list<unsigned int> &src);

#endif