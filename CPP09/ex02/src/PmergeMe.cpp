#include "PmergeMe.hpp"

std::ostream& operator<<(std::ostream& out, const PmergeMe< std::vector<unsigned int> > &src)
{
	std::vector<unsigned int>	tmpVec = src.getCont();

	for (std::vector<unsigned int>::const_iterator it = tmpVec.begin(); it != tmpVec.end(); it++)
		out << *it << " ";

	return (out);
}

std::ostream& operator<<(std::ostream& out, const PmergeMe< std::list<unsigned int> > &src)
{
	std::list<unsigned int>	tmpLi = src.getCont();

	for (std::list<unsigned int>::const_iterator it = tmpLi.begin(); it != tmpLi.end(); it++)
		out << *it << " ";

	return (out);
}
