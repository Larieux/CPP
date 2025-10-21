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

template < class container >
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const std::vector<int> &src);
	PmergeMe(const PmergeMe &src);
	~PmergeMe();

	PmergeMe &operator=(const PmergeMe &src);

	container		getCont() const;

protected:
	container	_cont;

private:

};

std::ostream& operator<<(std::ostream& out, const PmergeMe< std::vector<int> > &src);

std::ostream& operator<<(std::ostream& out, const PmergeMe< std::list<int> > &src);

#include "PmergeMe.tpp"

#endif