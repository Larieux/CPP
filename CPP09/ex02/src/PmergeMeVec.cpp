#include "PmergeMeVec.hpp"

PmergeMeVec::PmergeMeVec() : PmergeMe< std::vector<unsigned int> >()
{

}

PmergeMeVec::PmergeMeVec(const std::vector<unsigned int> &src) : PmergeMe< std::vector<unsigned int> >(src)
{

}

PmergeMeVec::PmergeMeVec(const PmergeMeVec &src):
	PmergeMe< std::vector<unsigned int> >(src)
{
	*this = src;
}

PmergeMeVec::~PmergeMeVec()
{

}


PmergeMeVec &PmergeMeVec::operator=(const PmergeMeVec &src)
{
	_cont = src.getCont();

	return (*this);
}


std::vector<unsigned int>	PmergeMeVec::sortVec()
{
	return (_cont);
}
