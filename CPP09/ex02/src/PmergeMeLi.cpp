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
	pairsList	sortedSecond = sortSecondLi(pairs);


	return (_cont);
}


pairsList	PmergeMeLi::makePairs()
{
	pairsList	list;

	std::list<unsigned int>::const_iterator it = _cont.begin();
	it++;

	std::list<unsigned int>::const_iterator ite = _cont.begin();


	for (; it != _cont.end();)
	{
		if (*it < *ite)
			list.push_back(std::make_pair(*it, *ite));
		else
			list.push_back(std::make_pair(*ite, *it));


		it++;
		ite++;
		if (it == _cont.end())
			return (list);
		it++;
		ite++;
		if (it == _cont.end())
			return (list);

	}

	return (list);
}

pairsList	PmergeMeLi::makePairsOfSecond(const pairsList &src)
{
	pairsList	list;

	std::list<basePair>::const_iterator it = src.begin();
	it++;

	std::list<basePair>::const_iterator ite = src.begin();


	for (; it != src.end();)
	{
		if ((*it).second < (*ite).second)
			list.push_back(std::make_pair((*it).second, (*ite).second));
		else
			list.push_back(std::make_pair((*ite).second, (*it).second));


		it++;
		ite++;
		if (it == src.end())
			return (list);
		it++;
		ite++;
		if (it == src.end())
			return (list);
	}

	return (list);
}

pairsList	PmergeMeLi::sortSecondLi(const pairsList &src)
{
	pairsList	pairsOfSecond = makePairsOfSecond(src);
	pairsList	sortedPairsOfSecond;
	pairsList	pushedTo;
	pairsList	sorted;

	if (pairsOfSecond.size() > 2)
		sortedPairsOfSecond = sortSecondLi(pairsOfSecond);

	for (std::list<basePair>::const_iterator it = sortedPairsOfSecond.begin(); it != sortedPairsOfSecond.end(); it++)
		pushedTo.push_front(*it);

	sorted = sortPushed(pushedTo);

	return (sorted);
}

pairsList	PmergeMeLi::sortPushed(const pairsList &src)
{
	pairsList	sorted;

	
}
