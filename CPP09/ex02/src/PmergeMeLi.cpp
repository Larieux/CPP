#include "PmergeMeLi.hpp"

PmergeMeLi::PmergeMeLi() : PmergeMe< std::list<int> >()
{

}

PmergeMeLi::PmergeMeLi(const std::vector<int> &src) : PmergeMe< std::list<int> >(src)
{

}

PmergeMeLi::PmergeMeLi(const PmergeMeLi &src):
	PmergeMe< std::list<int> >(src)
{

}

PmergeMeLi::~PmergeMeLi()
{

}
