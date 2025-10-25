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

	int	lastElement = (_cont.size() % 2 == 0) ? -1 : _cont.back();

	std::vector<unsigned int>	insertOrder = defineInsertOrderVec(sortedSecond.size(), lastElement);

	std::vector<unsigned int> res = insertElementsVec(sortedSecond, lastElement, -1, insertOrder);

	sortedSecond.clear();

	return (res);
}


pairsVector	PmergeMeVec::makePairs(std::vector<unsigned int>	cont)
{
	pairsVector vec;
	vectorIt it = cont.begin();
		
	while (it != cont.end())
	{
		unsigned int a = *it;
		++it;

		if (it == cont.end())
			break;

		unsigned int b = *it;
		++it;

		vec.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	return (vec);
}

std::vector<unsigned int>	PmergeMeVec::defineInsertOrderVec(unsigned int numberOfPairs,
	int lastElement)
{
	std::vector<unsigned int>	groupSizes;
	unsigned long long		currentSizesSum;

	groupSizes.push_back(1);
	currentSizesSum = 4;

	std::vector<unsigned int> jSeq;
	jSeq.push_back(1);
	jSeq.push_back(3);
	while (jSeq.back() < numberOfPairs)
	{
		size_t n = jSeq.size();
		unsigned int next = 2 * jSeq[n - 1] + jSeq[n - 2];
		jSeq.push_back(next);
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
		{
			it++;
			numberOfElementsLeftInGroup = *it;
		}

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

std::vector<unsigned int> PmergeMeVec::insertElementsVec(const pairsVector &pairs,
	int lastElementFirst, int lastElementSecond, std::vector<unsigned int> insertOrder)
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

		size_t	findIndex = binarySearchVec(seconds, *firstIndex);

		seconds.insert(seconds.begin() + findIndex, *firstIndex);
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

size_t PmergeMeVec::binarySearchVec(std::vector<unsigned int> &vec,
	unsigned int value)
{
	size_t low = 0;
	size_t high = vec.size();

	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (vec[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return (low);
}


pairsVector	PmergeMeVec::makePairsOfSecond(const pairsVector &src)
{
	pairsVector vec;
	pairsVector::const_iterator it = src.begin();
		
	while (it != src.end())
	{
		unsigned int a = (*it).second;
		++it;

		if (it == src.end())
			break;

		unsigned int b = (*it).second;
		++it;

		vec.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	return (vec);
}

pairsVector	PmergeMeVec::sortSecondVec(const pairsVector &src)
{
	pairsVector	pairsOfSecond = makePairsOfSecond(src);

	pairsVector	sortedPairsOfSecond;
	pairsVector	pushedTo;
	pairsVector	sorted;

	if (pairsOfSecond.size() > 1)
		sortedPairsOfSecond = sortSecondVec(pairsOfSecond);
	else
		sortedPairsOfSecond = pairsOfSecond;

	if (src.size() % 2 != 0)
		pushedTo.push_back(src.back());

	for (pairsVector::const_iterator it = sortedPairsOfSecond.begin(); it != sortedPairsOfSecond.end(); it++)
		pushedTo.push_back(*it);


	sorted = sortPushed(src, pushedTo);

	return (sorted);
}

pairsVector	PmergeMeVec::sortPushed(const pairsVector &origin, const pairsVector &src)
{
	int	lastElementFirst = (origin.size() % 2 == 0) ? -1 : (origin.back()).first;
	int	lastElementSec = (origin.size() % 2 == 0) ? -1 : (origin.back()).second;

	std::vector<unsigned int>	insertOrder = defineInsertOrderVec(src.size(),
		lastElementFirst);

	std::vector<unsigned int>	inserted = insertElementsVec(src, lastElementFirst,
		lastElementSec, insertOrder);

	pairsVector	res;

	for (cVectorIt it = inserted.begin(); it != inserted.end(); it++)
	{
		for (pairsVector::const_iterator ite = origin.begin(); ite != origin.end(); ite++)
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
