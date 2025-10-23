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
	int			lastElement = (_cont.size() % 2 == 0) ? -1 : *(--_cont.end());
	std::list<unsigned int>	insertOrder = defineInsertOrderLi(sortedSecond.size(), lastElement);
	std::list<unsigned int> res = insertElementsLi(sortedSecond, lastElement, insertOrder);

	return (res);
}


pairsList	PmergeMeLi::makePairs()
{
	pairsList	list;

	cListIt it = _cont.begin();
	it++;

	cListIt ite = _cont.begin();


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

std::list<unsigned int>	PmergeMeLi::defineInsertOrderLi(unsigned int numberOfPairs, int lastElement)
{
	std::list<unsigned int>	groupSizes;
	unsigned long long		currentSizesSum;
	unsigned int			JSFirst, JSSecond, JSNew;

	groupSizes.push_back(3);
	currentSizesSum = 2;
	JSFirst = 1;
	JSSecond = 3;

	while (currentSizesSum <= numberOfPairs)
	{
		JSNew = JSSecond + (2 * JSFirst);
		JSFirst = JSSecond;
		JSSecond = JSNew;
		groupSizes.push_back(JSSecond - *(--groupSizes.end()));
		currentSizesSum += *(--groupSizes.end());
	}
	if (lastElement != -1)
		numberOfPairs++;
	if (lastElement != -1 && currentSizesSum == numberOfPairs)
		groupSizes.push_back(1);

	std::list<unsigned int>	indexOrder;
	unsigned int	numberOfElementsLeftInGroup = *(groupSizes.begin());
	int				largestIndexInGroup = 0;
	int				listSize = 0;
	cListIt	it = groupSizes.begin();

	indexOrder.push_back(0);

	for (unsigned int i = 0; i + 1 < numberOfPairs; i++)
	{
		if (numberOfElementsLeftInGroup == 1)
			numberOfElementsLeftInGroup = *(++it);

		listSize = indexOrder.size() - 1;
		largestIndexInGroup = *it + listSize;
		if (largestIndexInGroup >= (int)numberOfPairs)
			largestIndexInGroup = (int)numberOfPairs - 1;

		while (largestIndexInGroup - listSize > 0)
		{
			indexOrder.push_back(largestIndexInGroup);
			largestIndexInGroup--;
		}

		numberOfElementsLeftInGroup--;
	}

	return (indexOrder);
}

std::list<unsigned int> PmergeMeLi::insertElementsLi(const pairsList &pairs, int lastElement, std::list<unsigned int> insertOrder)
{
	std::list<unsigned int> res;
	for (pairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		res.push_back((*it).first);

	std::list<unsigned int>	seconds;
	for (pairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		seconds.push_back((*it).second);
	if (lastElement != -1)
		seconds.push_back(lastElement);

	for (cListIt it = insertOrder.begin(); it != insertOrder.end(); it++)
	{
		cListIt	secondsIndex = findSecondsIndex(seconds, it);
		listIt	index = binarySearchLi(secondsIndex, res.begin(), res.end(), res);
		
		res.insert(index, *secondsIndex);
	}
	return (res);
}

cListIt	PmergeMeLi::findSecondsIndex(std::list<unsigned int> &list, cListIt orderIndex)
{
	cListIt	res = list.begin();

	for (unsigned int i = 0; i < *orderIndex; i++)
		res++;

	return (res);
}

listIt	PmergeMeLi::binarySearchLi(cListIt index, listIt begin, cListIt end, const std::list<unsigned int> &list)
{
	if (*begin >= *end)
		return (begin);

	listIt	mid = begin;
	for (unsigned int findMid = 0; findMid < (list.size() / 2); findMid++)
		mid++;

	if (*index < *mid)
		return (binarySearchLi(index, begin, mid, list));
	else if (*index > *mid)
		return (binarySearchLi(index, ++mid, end, list));
	return (mid);
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
	int			lastElement = (_cont.size() % 2 == 0) ? -1 : *(--_cont.end());
	std::list<unsigned int>	insertOrder = defineInsertOrderLi(src.size(), lastElement);
	std::list<unsigned int> inserted = insertElementsLi(src, lastElement, insertOrder);
	pairsList	res;

	for (std::list<unsigned int>::const_iterator it = inserted.begin(); it != inserted.end(); it++)
	{
		for (pairsList::const_iterator ite = src.begin(); ite != src.end(); ite++)
		{
			if (*it == (*ite).second)
			{
				res.push_back(std::make_pair((*ite).first, (*ite).second));
				continue ;
			}
		}
	}

	return (res);
}

