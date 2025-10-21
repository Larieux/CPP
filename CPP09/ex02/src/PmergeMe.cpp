#include "PmergeMe.hpp"

std::ostream& operator<<(std::ostream& out, const PmergeMe< std::vector<int> > &src)
{
	std::vector<int>	tmpVec = src.getCont();

	for (std::vector<int>::iterator it = tmpVec.begin(); it != tmpVec.end(); it++)
		out << *it << " ";

	return (out);
}

std::ostream& operator<<(std::ostream& out, const PmergeMe< std::list<int> > &src)
{
	std::list<int>	tmpLi = src.getCont();

	for (std::list<int>::iterator it = tmpLi.begin(); it != tmpLi.end(); it++)
		out << *it << " ";

	return (out);
}
