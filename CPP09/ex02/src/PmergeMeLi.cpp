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

	pairsList	sortedSecond = sortSecondLi(pairs);

	pairs.clear();

	int			lastElement = (_cont.size() % 2 == 0) ? -1 : *(--_cont.end());
	std::list<unsigned int>	insertOrder = defineInsertOrderLi(sortedSecond.size(), lastElement);

	std::cout << "insertOrder: " << insertOrder << std::endl;

	std::list<unsigned int> res = insertElementsLi(sortedSecond, lastElement, -1, insertOrder);

	std::cout << "res: " << res << std::endl;

	sortedSecond.clear();

	return (res);
}


pairsList	PmergeMeLi::makePairs(std::list<unsigned int>	cont)
{
	pairsList	list;

	cListIt it = ++(cont.begin());

	cListIt ite = cont.begin();

	for (; it != cont.end();)
	{
		if (*it < *ite)
			list.push_back(std::make_pair(*it, *ite));
		else
			list.push_back(std::make_pair(*ite, *it));

		it++;
		ite++;
		if (it == cont.end())
			return (list);
		it++;
		ite++;
		if (it == cont.end())
			return (list);
	}

	return (list);
}

std::list<unsigned int>	PmergeMeLi::defineInsertOrderLi(unsigned int numberOfPairs, int lastElement)
{
	std::list<unsigned int>	groupSizes;
	unsigned long long		currentSizesSum;
	unsigned int			JSFirst, JSSecond, JSNew;

	groupSizes.push_back(2);
	currentSizesSum = 4;
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

	std::cout << "groupSizes: " << groupSizes << std::endl;

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

std::list<unsigned int> PmergeMeLi::insertElementsLi(const pairsList &pairs, int lastElementFirst, int lastElementSecond, std::list<unsigned int> insertOrder)
{
	std::list<unsigned int> res;
	for (pairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		res.push_back((*it).first);

	std::list<unsigned int>	seconds;
	for (pairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		seconds.push_back((*it).second);
	if (lastElementFirst != -1)
		seconds.push_back(lastElementFirst);
	if (lastElementSecond != -1)
		seconds.push_back(lastElementSecond);

	for (cListIt it = insertOrder.begin(); it != insertOrder.end(); it++)
	{
		cListIt	secondsIndex = findSecondsIndex(seconds, it);

		unsigned int	index = binarySearchLi(*secondsIndex, *(res.begin()), *(--(res.end())));

		listIt	findIndex = res.begin();
		for (; *findIndex != index;)
			findIndex++;

		res.insert(findIndex, *secondsIndex);
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

unsigned int	PmergeMeLi::binarySearchLi(unsigned int index, unsigned int begin, unsigned int end)
{
	if (end <= begin)
		return (begin);

	unsigned int	mid = (begin + end) / 2;

	if (index < mid)
		return (binarySearchLi(index, begin, mid));
	else if (index > mid)
		return (binarySearchLi(index, ++mid, end));
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
	
	// std::cerr << "pairsOfSecond: " << pairsOfSecond << std::endl;

	pairsList	sortedPairsOfSecond;
	pairsList	pushedTo;
	pairsList	sorted;

	if (pairsOfSecond.size() > 2)
		sortedPairsOfSecond = sortSecondLi(pairsOfSecond);
	else
		sortedPairsOfSecond = pairsOfSecond;

	// std::cerr << "sortedpairsOfSecond: " << sortedPairsOfSecond << std::endl;

	for (std::list<basePair>::const_iterator it = sortedPairsOfSecond.begin(); it != sortedPairsOfSecond.end(); it++)
		pushedTo.push_front(*it);

	if (src.size() % 2 != 0)
		pushedTo.push_front(*(--src.end()));

	// std::cerr << "pushedTo: " << pushedTo << std::endl;

	sorted = sortPushed(src, pushedTo);

	// std::cerr << "sorted: " << sorted << std::endl;

	return (sorted);
}

pairsList	PmergeMeLi::sortPushed(const pairsList &origin, const pairsList &src)
{
	int	lastElementFirst = (origin.size() % 2 == 0) ? -1 : (*(--origin.end())).first;
	int	lastElementSec = (origin.size() % 2 == 0) ? -1 : (*(--origin.end())).second;
	std::list<unsigned int>	insertOrder = defineInsertOrderLi(src.size(), lastElementFirst);
	std::list<unsigned int>	inserted = insertElementsLi(src, lastElementFirst, lastElementSec, insertOrder);
	pairsList	res;

	for (std::list<unsigned int>::const_iterator it = inserted.begin(); it != inserted.end(); it++)
	{
		for (pairsList::const_iterator ite = origin.begin(); ite != origin.end(); ite++)
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

