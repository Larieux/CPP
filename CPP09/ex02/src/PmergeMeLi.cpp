#include "PmergeMeLi.hpp"

PmergeMeLi::PmergeMeLi() : PmergeMe< std::list<unsigned int> >()
{

}

PmergeMeLi::PmergeMeLi(const std::vector<unsigned int> &src) : PmergeMe< std::list<unsigned int> >(src)
{

}

PmergeMeLi::PmergeMeLi(const PmergeMeLi &src):
	PmergeMe< std::list<unsigned int> >(src)
{
	*this = src;
}

PmergeMeLi::~PmergeMeLi()
{

}


PmergeMeLi &PmergeMeLi::operator=(const PmergeMeLi &src)
{
	_cont = src.getCont();

	return (*this);
}


std::list<unsigned int>	PmergeMeLi::sortLi()
{
	return (_cont);
}

