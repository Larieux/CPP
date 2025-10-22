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


PmergeMeLi	&PmergeMeLi::operator=(const PmergeMeLi &src)
{
	_cont = src.getCont();

	return (*this);
}


std::list<unsigned int>	PmergeMeLi::sortLi()
{
	pairsList	pairs = makePairs();

	return (_cont);
}


pairsList	PmergeMeLi::makePairs()
{
	pairsList	pairs;

	std::list<unsigned int>::const_iterator it = _cont.begin();
	it++;
	for (std::list<unsigned int>::const_iterator ite = _cont.begin(); it != _cont.end();)
	{
		if (*it < *ite)
			pairs.push_back(std::make_pair(*it, *ite));
		else
			pairs.push_back(std::make_pair(*ite, *it));

		it++;
		ite++;
		if (it == _cont.end())
			return (pairs);
		it++;
		ite++;
	}

	return (pairs);
}
