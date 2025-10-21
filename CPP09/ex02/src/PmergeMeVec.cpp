#include "PmergeMeVec.hpp"

PmergeMeVec::PmergeMeVec() : PmergeMe< std::vector<int> >()
{

}

PmergeMeVec::PmergeMeVec(const std::vector<int> &src) : PmergeMe< std::vector<int> >(src)
{

}

PmergeMeVec::PmergeMeVec(const PmergeMeVec &src):
	PmergeMe< std::vector<int> >(src)
{

}

PmergeMeVec::~PmergeMeVec()
{

}
