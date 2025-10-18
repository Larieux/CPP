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

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const std::vector<int> &src);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &src);

	std::vector<int>	getVec();
	std::list<int>		getLi();

private:
	std::vector<int>	vec;
	std::list<int>		li;

};

#endif