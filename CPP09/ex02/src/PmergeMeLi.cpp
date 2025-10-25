#include "PmergeMeLi.hpp"

PmergeMeLi::PmergeMeLi()
{

}

PmergeMeLi::PmergeMeLi(const std::vector<unsigned int> &src)
{
	for (std::vector<unsigned int>::const_iterator it = src.begin(); it != src.end(); it++)
	{
		_cont.push_back(*it);
	}
}

PmergeMeLi::PmergeMeLi(const PmergeMeLi &src)
{
	*this = src;
}

PmergeMeLi::~PmergeMeLi()
{
	_cont.clear();
}


PmergeMeLi	&PmergeMeLi::operator=(const PmergeMeLi &src)
{
	_cont.clear();
	_cont = src.getCont();

	return (*this);
}


std::ostream& operator<<(std::ostream& out, const pairsList &src)
{
	for (pairsList::const_iterator it = src.begin(); it != src.end(); it++)
		out << (*it).first << " " << (*it).second << " | ";

	return (out);
}


std::list<unsigned int>	PmergeMeLi::getCont() const
{
	return (_cont);
}


void	PmergeMeLi::clearLi()
{
	_cont.clear();
}


std::list<unsigned int>	PmergeMeLi::sortLi()
{
	pairsList	pairs = makePairs(_cont);
	pairsList	sortedSecond;
	if (pairs.size() > 1)
		sortedSecond = sortSecondLi(pairs);
	else
		sortedSecond = pairs;

	pairs.clear();

	int	lastElement = (_cont.size() % 2 == 0) ? -1 : *(--_cont.end());

	std::list<unsigned int>	insertOrder = defineInsertOrderLi(sortedSecond.size(), lastElement);

	std::list<unsigned int> res = insertElementsLi(sortedSecond, lastElement, -1, insertOrder);

	sortedSecond.clear();

	return (res);
}


pairsList	PmergeMeLi::makePairs(std::list<unsigned int>	cont)
{
	pairsList list;
	listIt it = cont.begin();
		
	while (it != cont.end())
	{
		unsigned int a = *it;
		++it;

		if (it == cont.end())
			break;

		unsigned int b = *it;
		++it;

		list.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	return (list);
}

std::list<unsigned int>	PmergeMeLi::defineInsertOrderLi(unsigned int numberOfPairs,
	int lastElement)
{
	std::list<unsigned int>	groupSizes;
	unsigned long long		currentSizesSum;

	groupSizes.push_back(1);
	currentSizesSum = 4;

	std::list<unsigned int> jSeq;
	jSeq.push_back(1);
	jSeq.push_back(3);
	while (jSeq.back() < numberOfPairs + 1)
	{
		listIt last = jSeq.end();
		--last;
		listIt secondLast = last;
		--secondLast;

		jSeq.push_back((*last) * 2 + (*secondLast));
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

std::list<unsigned int> PmergeMeLi::insertElementsLi(const pairsList &pairs,
	int lastElementFirst, int lastElementSecond, std::list<unsigned int> insertOrder)
{
	std::list<unsigned int> first;
	for (pairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		first.push_back((*it).first);

	std::list<unsigned int>	seconds;
	for (pairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		seconds.push_back((*it).second);

	if (lastElementFirst != -1)
		first.push_back(lastElementFirst);
	if (lastElementSecond != -1)
		first.push_back(lastElementSecond);

	for (cListIt it = insertOrder.begin(); it != insertOrder.end(); it++)
	{
		cListIt	firstIndex = findSecIndex(first, it);

		listIt	findIndex = binarySearchLi(seconds, *firstIndex);

		seconds.insert(findIndex, *firstIndex);
	}
	return (seconds);
}

cListIt	PmergeMeLi::findSecIndex(std::list<unsigned int> &list, cListIt orderIndex)
{
	cListIt	res = list.begin();

	for (unsigned int i = 0; i < *orderIndex; i++)
		res++;

	return (res);
}

listIt PmergeMeLi::binarySearchLi(std::list<unsigned int> &lst,
	unsigned int value)
{
	listIt low = lst.begin();
	listIt high = lst.end();

	while (low != high)
	{
		listIt mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (*mid < value)
			low = ++mid;
		else
			high = mid;
	}
	return low;
}


pairsList	PmergeMeLi::makePairsOfSecond(const pairsList &src)
{
	pairsList list;
	pairsList::const_iterator it = src.begin();
		
	while (it != src.end())
	{
		unsigned int a = (*it).second;
		++it;

		if (it == src.end())
			break;

		unsigned int b = (*it).second;
		++it;

		list.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	return (list);
}

pairsList	PmergeMeLi::sortSecondLi(const pairsList &src)
{
	pairsList	pairsOfSecond = makePairsOfSecond(src);

	pairsList	sortedPairsOfSecond;
	pairsList	pushedTo;
	pairsList	sorted;

	if (pairsOfSecond.size() > 1)
		sortedPairsOfSecond = sortSecondLi(pairsOfSecond);
	else
		sortedPairsOfSecond = pairsOfSecond;

	for (pairsList::const_iterator it = sortedPairsOfSecond.begin(); it != sortedPairsOfSecond.end(); it++)
		pushedTo.push_back(*it);

	if (src.size() % 2 != 0)
		pushedTo.push_front(*(--src.end()));

	sorted = sortPushed(src, pushedTo);

	return (sorted);
}

pairsList	PmergeMeLi::sortPushed(const pairsList &origin, const pairsList &src)
{
	int	lastElementFirst = (origin.size() % 2 == 0) ? -1 : (*(--origin.end())).first;
	int	lastElementSec = (origin.size() % 2 == 0) ? -1 : (*(--origin.end())).second;

	std::list<unsigned int>	insertOrder = defineInsertOrderLi(src.size(),
		lastElementFirst);

	std::list<unsigned int>	inserted = insertElementsLi(src, lastElementFirst,
		lastElementSec, insertOrder);

	pairsList	res;

	for (cListIt it = inserted.begin(); it != inserted.end(); it++)
	{
		for (pairsList::const_iterator ite = origin.begin(); ite != origin.end(); ite++)
		{
			if (*it == (*ite).second)
			{
				res.push_back(std::make_pair((*ite).first, (*ite).second));
				break ;
			}
		}
	}

	return (res);
}

