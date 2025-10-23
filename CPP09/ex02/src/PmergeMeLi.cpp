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


pairsList	PmergeMeLi::launchIncePairs()
{

	pairsList	firstList;

	std::list<unsigned int>::const_iterator it = _cont.begin();
	it++;

	std::list<unsigned int>::const_iterator ite = _cont.begin();

	incePairs< std::pair<const unsigned int, const unsigned int> >	pairFirst;
	if (*it < *ite)
		pairFirst.setAbomination(*it, *ite);
	else
		pairFirst.setAbomination(*ite, *it);


	it++;
	ite++;
	if (it == _cont.end())
	{
		firstList.push_back(pairFirst);
		return (firstList);
	}
	it++;
	ite++;
	if (it == _cont.end())
	{
		firstList.push_back(pairFirst);
		return (firstList);
	}

	incePairs< std::pair<const unsigned int, const unsigned int> >	pairSecond;
	if (*it < *ite)
		pairSecond.setAbomination(*it, *ite);
	else
		pairSecond.setAbomination(*ite, *it);


	it++;
	ite++;
	firstList.push_back(pairFirst);
	firstList.push_back(pairSecond);

	incePairs< std::pair<pairsInception, pairsInception> >	deeperPairFisrt;
	deeperPairFisrt.setAbomination(pairFirst, pairSecond);

	it++;
	ite++;

	for (; it != _cont.end();)
	{
		incePairs< std::pair<const unsigned int, const unsigned int> >	pairThird;
		if (*it < *ite)
			pairThird.setAbomination(*it, *ite);
		else
			pairThird.setAbomination(*ite, *it);


		it++;
		ite++;
		if (it == _cont.end())
		{
			firstList.push_back(pairThird);
			return (firstList);
		}
		it++;
		ite++;
		if (it == _cont.end())
		{
			firstList.push_back(pairThird);
			return (firstList);
		}

		incePairs< std::pair<const unsigned int, const unsigned int> >	pairFourth;
		if (*it < *ite)
			pairFourth.setAbomination(*it, *ite);
		else
			pairFourth.setAbomination(*ite, *it);


		it++;
		ite++;
		firstList.push_back(pairThird);
		firstList.push_back(pairFourth);

		incePairs< std::pair<pairsInception, pairsInception> >	deeperPair;

		it++;
		ite++;
	}

	return (firstList);

}

std::list<unsigned int>	PmergeMeLi::sortLi()
{
	pairsList		sortedPairs = launchIncePairs();


	return (_cont);
}


std::pair< pairsInception, pairsInception >	PmergeMeLi::makePairs()
{
	std::list<unsigned int>::const_iterator it = _cont.begin();
	it++;

	for (std::list<unsigned int>::const_iterator ite = _cont.begin(); it != _cont.end();)
	{
		incePairs< std::pair<const unsigned int, const unsigned int> >	deeperPairFirst;
		if (*it < *ite)
			deeperPairFirst.setAbomination(*it, *ite);
		else
			deeperPairFirst.setAbomination(*ite, *it);


		it++;
		ite++;
		if (it == _cont.end())
			return (deeperPairFirst.getAbomination());
		it++;
		ite++;
	}

	return (firstList);
}
