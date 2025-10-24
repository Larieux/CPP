#include "PmergeMeVec.hpp"

PmergeMeVec::PmergeMeVec()
{

}

PmergeMeVec::PmergeMeVec(const std::vector<unsigned int> &src)
{
	for (std::vector<unsigned int>::const_iterator it = src.begin(); it != src.end(); it++)
	{
		_cont.push_back(*it);
	}
}

PmergeMeVec::PmergeMeVec(const PmergeMeVec &src)
{
	*this = src;
}

PmergeMeVec::~PmergeMeVec()
{
	_cont.clear();
}


PmergeMeVec	&PmergeMeVec::operator=(const PmergeMeVec &src)
{
	_cont.clear();
	_cont = src.getCont();

	return (*this);
}


std::ostream& operator<<(std::ostream& out, const pairsVector &src)
{
	for (pairsVector::const_iterator it = src.begin(); it != src.end(); it++)
		out << (*it).first << " " << (*it).second << " | ";

	return (out);
}


std::vector<unsigned int>	PmergeMeVec::getCont() const
{
	return (_cont);
}


void	PmergeMeVec::clearVec()
{
	_cont.clear();
}


std::vector<unsigned int>	PmergeMeVec::sortVec()
{
	pairsVector	pairs = makePairs(_cont);
	pairsVector	sortedSecond;
	if (pairs.size() > 1)
		sortedSecond = sortSecondVec(pairs);
	else
		sortedSecond = pairs;

	pairs.clear();

	int			lastElement = (_cont.size() % 2 == 0) ? -1 : *(--_cont.end());
	std::vector<unsigned int>	insertOrder = defineInsertOrderVec(sortedSecond.size(), lastElement);

	std::vector<unsigned int> res = insertElementsVec(sortedSecond, lastElement, -1, insertOrder);

	std::cerr << "res:\t\t" << res << std::endl;

	sortedSecond.clear();

	return (res);
}


pairsVector	PmergeMeVec::makePairs(std::vector<unsigned int>	cont)
{
	pairsVector	vector;

	cVectorIt it = ++(cont.begin());

	cVectorIt ite = cont.begin();

	for (; it != cont.end();)
	{
		if (*it < *ite)
			vector.push_back(std::make_pair(*it, *ite));
		else
			vector.push_back(std::make_pair(*ite, *it));

		it++;
		ite++;
		if (it == cont.end())
			return (vector);
		it++;
		ite++;
		if (it == cont.end())
			return (vector);
	}

	return (vector);
}

std::vector<unsigned int>	PmergeMeVec::defineInsertOrderVec(unsigned int numberOfPairs, int lastElement)
{
	std::vector<unsigned int>	groupSizes;
	unsigned long long		currentSizesSum;
	unsigned int			JSFirst, JSSecond, JSNew;

	groupSizes.push_back(1);
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

	std::vector<unsigned int>	indexOrder;
	unsigned int	numberOfElementsLeftInGroup = *(groupSizes.begin());
	int				largestIndexInGroup = 0;
	int				vectorSize = 0;
	cVectorIt	it = groupSizes.begin();

	indexOrder.push_back(0);

	for (unsigned int i = 0; i + 1 < numberOfPairs; i++)
	{
		if (numberOfElementsLeftInGroup == 1)
			numberOfElementsLeftInGroup = *(++it);

		vectorSize = indexOrder.size() - 1;
		largestIndexInGroup = *it + vectorSize;
		if (largestIndexInGroup >= (int)numberOfPairs)
			largestIndexInGroup = (int)numberOfPairs - 1;

		while (largestIndexInGroup - vectorSize > 0)
		{
			indexOrder.push_back(largestIndexInGroup);
			largestIndexInGroup--;
		}

		numberOfElementsLeftInGroup--;
	}

	return (indexOrder);
}

std::vector<unsigned int> PmergeMeVec::insertElementsVec(const pairsVector &pairs, int lastElementFirst, int lastElementSecond, std::vector<unsigned int> insertOrder)
{
	std::vector<unsigned int> first;
	for (pairsVector::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		first.push_back((*it).first);

	std::vector<unsigned int>	seconds;
	for (pairsVector::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		seconds.push_back((*it).second);

	if (lastElementFirst != -1)
		first.push_back(lastElementFirst);
	if (lastElementSecond != -1)
		first.push_back(lastElementSecond);

	for (cVectorIt it = insertOrder.begin(); it != insertOrder.end(); it++)
	{
		cVectorIt	firstIndex = findSecIndex(first, it);

		unsigned int	index = binarySearchVec(*firstIndex, *(seconds.begin()), *(--(seconds.end())));

		vectorIt	findIndex = seconds.begin();
		for (; *findIndex != index && findIndex != seconds.end();)
			findIndex++;

		seconds.insert(findIndex, *firstIndex);
	}
	return (seconds);
}

cVectorIt	PmergeMeVec::findSecIndex(std::vector<unsigned int> &vector, cVectorIt orderIndex)
{
	cVectorIt	res = vector.begin();

	for (unsigned int i = 0; i < *orderIndex; i++)
		res++;

	return (res);
}

unsigned int	PmergeMeVec::binarySearchVec(unsigned int index, unsigned int begin, unsigned int end)
{
	if (end <= begin)
		return (begin);

	unsigned int	mid = (begin + end) / 2;

	if (index < mid)
		return (binarySearchVec(index, begin, mid));
	else if (index > mid)
		return (binarySearchVec(index, ++mid, end));
	return (mid);
}


pairsVector	PmergeMeVec::makePairsOfSecond(const pairsVector &src)
{
	pairsVector	vector;

	std::vector<basePair>::const_iterator it = src.begin();
	it++;

	std::vector<basePair>::const_iterator ite = src.begin();

	for (; it != src.end();)
	{
		if ((*it).second < (*ite).second)
			vector.push_back(std::make_pair((*it).second, (*ite).second));
		else
			vector.push_back(std::make_pair((*ite).second, (*it).second));

		it++;
		ite++;
		if (it == src.end())
			return (vector);
		it++;
		ite++;
		if (it == src.end())
			return (vector);
	}

	return (vector);
}

pairsVector	PmergeMeVec::sortSecondVec(const pairsVector &src)
{
	pairsVector	pairsOfSecond = makePairsOfSecond(src);
	
	// std::cerr << "pairsOfSecond: " << pairsOfSecond << std::endl;

	pairsVector	sortedPairsOfSecond;
	pairsVector	pushedTo;
	pairsVector	sorted;

	if (pairsOfSecond.size() > 1)
		sortedPairsOfSecond = sortSecondVec(pairsOfSecond);
	else
		sortedPairsOfSecond = pairsOfSecond;

	// std::cerr << "sortedpairsOfSecond: " << sortedPairsOfSecond << std::endl;

	std::vector<basePair>::const_iterator it = --sortedPairsOfSecond.end();
	for (std::vector<basePair>::const_iterator it = sortedPairsOfSecond.begin(); it != sortedPairsOfSecond.end(); it++)
	for (; it != sortedPairsOfSecond.begin(); --it)
		pushedTo.push_back(*it);
	pushedTo.push_back(*it);

	// std::cerr << "pushedTo: " << pushedTo << std::endl;

	sorted = sortPushed(src, pushedTo);

	// std::cerr << "sorted: " << sorted << std::endl;

	return (sorted);
}

pairsVector	PmergeMeVec::sortPushed(const pairsVector &origin, const pairsVector &src)
{
	int	lastElementFirst = (origin.size() % 2 == 0) ? -1 : (*(--origin.end())).first;
	int	lastElementSec = (origin.size() % 2 == 0) ? -1 : (*(--origin.end())).second;

	std::vector<unsigned int>	insertOrder = defineInsertOrderVec(src.size(), lastElementFirst);

	std::vector<unsigned int>	inserted = insertElementsVec(src, lastElementFirst, lastElementSec, insertOrder);

	// std::cerr << "inserted: " << inserted << std::endl;

	pairsVector	res;

	for (std::vector<unsigned int>::const_iterator it = inserted.begin(); it != inserted.end(); it++)
	{
		for (pairsVector::const_iterator ite = origin.begin(); ite != origin.end(); ite++)
		{
			if (*it == (*ite).second)
			{
				res.push_back(std::make_pair((*ite).first, (*ite).second));
				std::cerr << "res: " << res << std::endl;
				continue ;
			}
		}
	}

	return (res);
}

