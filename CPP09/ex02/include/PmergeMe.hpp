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
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &src);

	std::vector<int>	getInput() const;
	std::vector<int>	getVec() const;
	std::list<int>		getLi() const;

	void				fillContainers(char **argv);

	

private:
	std::vector<int>	input;
	std::vector<int>	vec;
	std::list<int>		li;

};

#endif