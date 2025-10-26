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

std::ostream& operator<<(std::ostream& out, const intPairsList &src)
{
	for (intPairsList::const_iterator it = src.begin(); it != src.end(); it++)
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
	leftBehindHandler pairs = makePairs(_cont);

	leftBehindHandler sortedResult = sortSecondLi(pairs);

	intPairsList forgottenElements;
	intPairsList	SRCpy = sortedResult.getPairsLi();
	for (intPairsList::const_iterator it = SRCpy.begin();
		it != SRCpy.end(); it++)
	{
		if (it->first != -1)
		{
			bool found = false;
			intPairsList	pairsCpy = pairs.getPairsLi();
			for (intPairsList::const_iterator ite = pairsCpy.begin();
					ite != pairsCpy.end(); ++ite)
			{
				if (ite->first == it->first || ite->second == it->first)
				{
					found = true;
					break;
				}
			}
			if (!found && it->first != -1)
				forgottenElements.push_back(std::make_pair(it->first, -1));
		}
		if (it->second != -1)
		{
			bool found = false;
			intPairsList	pairsCpy = pairs.getPairsLi();
			for (intPairsList::const_iterator ite = pairsCpy.begin();
					ite != pairsCpy.end(); ++ite)
			{
				if (ite->first == it->second || ite->second == it->second)
				{
					found = true;
					break;
				}
			}
			if (!found && it->second != -1)
				forgottenElements.push_back(std::make_pair(it->second, -1));
		}
	}
	std::list<unsigned int> insertOrder = defineInsertOrderLi(sortedResult.getPairsLi().size() + forgottenElements.size());

	std::list<int> tmp = insertElementsLi(sortedResult.getPairsLi(), forgottenElements, insertOrder);

	std::list<unsigned int> res(tmp.begin(), tmp.end());

	return (res);
}


leftBehindHandler	PmergeMeLi::makePairs(std::list<unsigned int>	cont)
{
	leftBehindHandler	list;
	intPairsList		leftOver;
	intPairsList		pairs;

	unsigned int a;

	for (listIt it = cont.begin(); it != cont.end();)
	{
		a = *(it++);
		if (it == cont.end())
		{
			leftOver.push_back(std::make_pair(a, -1));
			break;
		}
		unsigned int b = *(it++);
		pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	list.setPairsLi(pairs);
	list.setLeftOversLi(leftOver);

	return (list);
}

std::list<unsigned int>	PmergeMeLi::defineInsertOrderLi(unsigned int numberOfPairs)
{
	std::list<unsigned int>	groupSizes;

	groupSizes.push_back(1);

	std::list<unsigned int> jSeq;
	jSeq.push_back(1);
	jSeq.push_back(3);
	while (jSeq.back() < numberOfPairs + 1)
	{
		listIt last = jSeq.end();
		--last;
		listIt secondLast = last;
		--secondLast;

		jSeq.push_back((*last) + (2 * (*secondLast)));
	}

	std::list<unsigned int> indexOrder;
	std::vector<bool> used(numberOfPairs, false);

	for (std::list<unsigned int>::iterator it = jSeq.begin(); it != jSeq.end(); ++it)
	{
		if (*it <= numberOfPairs && !used[*it - 1])
		{
			indexOrder.push_back(*it - 1);
			used[*it - 1] = true;
		}
	}

	for (unsigned int i = 0; i < numberOfPairs; ++i)
	{
		if (!used[i])
		{
			indexOrder.push_back(i);
			used[i] = true;
		}
	}

	return (indexOrder);
}

std::list<int> PmergeMeLi::insertElementsLi(const intPairsList &pairs,
	intPairsList forgottenElements, std::list<unsigned int> insertOrder)
{
	std::list<unsigned int> first;
	for (intPairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		first.push_back((*it).first);

	std::list<int>	second;
	for (intPairsList::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		second.push_back((*it).second);

	for (intPairsList::const_iterator it = forgottenElements.begin(); it != forgottenElements.end(); it++)
	{
		if (it->first != -1 && std::find(first.begin(), first.end(), it->first) == first.end())
			first.push_back(it->first);
		if (it->second != -1 && std::find(first.begin(), first.end(), it->second) == first.end())
			first.push_back(it->second);
	}

	for (cListIt it = insertOrder.begin(); it != insertOrder.end(); ++it)
	{
		if (*it >= first.size())
			continue;

		cListIt valueIt = first.begin();
		std::advance(valueIt, *it);
		int value = *valueIt;

		intListIt findIndex = binarySearchLi(second, value);

		second.insert(findIndex, value);
	}

	for (cListIt it = first.begin(); it != first.end(); ++it)
	{
		int val = *it;
		if (std::find(second.begin(), second.end(), val) == second.end())
		{
			intListIt pos = binarySearchLi(second, val);
			second.insert(pos, val);
		}
	}

	return (second);
}

cListIt	PmergeMeLi::findSecIndex(std::list<unsigned int> &list, cListIt orderIndex)
{
	cListIt	res = list.begin();

	for (unsigned int i = 0; i < *orderIndex; i++)
		res++;

	return (res);
}

intListIt PmergeMeLi::binarySearchLi(std::list<int> &lst,
	int value)
{
	intListIt low = lst.begin();
	intListIt high = lst.end();

	while (low != high)
	{
		intListIt mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (*mid < value)
			low = ++mid;
		else
			high = mid;
	}
	return (low);
}


leftBehindHandler	PmergeMeLi::makePairsOfSecond(const leftBehindHandler &src)
{
	intPairsList					srcCpy = src.getPairsLi();
	intPairsList::const_iterator	it = srcCpy.begin();
	intPairsList					list;
	leftBehindHandler				res;
	intPairsList					leftOver;
	bool hasLeftover = false;

	unsigned int a;

	for (; it != srcCpy.end();)
	{
		a = (it++)->second;
		if (it == srcCpy.end())
		{
			leftOver.push_back(std::make_pair(a, -1));
			hasLeftover = true;
			break;
		}
		unsigned int b = (it++)->second;
		list.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	res.setPairsLi(list);
	res.setLeftOversLi(leftOver);
	return (res);
}

leftBehindHandler PmergeMeLi::sortSecondLi(const leftBehindHandler &src)
{
	leftBehindHandler	pairsOfSecond = makePairsOfSecond(src);

	leftBehindHandler recResult;
	if (pairsOfSecond.getPairsLi().size() > 1)
		recResult = sortSecondLi(pairsOfSecond);
	else {
		recResult = pairsOfSecond;
	}

	intPairsList sorted = sortPushed(src, recResult);

	leftBehindHandler	res;
	intPairsList		pairs;
	intPairsList		leftOver;
	pairs = sorted;
	leftOver = src.getLeftOversLi();
	intPairsList	recRes = recResult.getPairsLi();
	for (intPairsList::const_iterator it = recRes.begin();
		it != recRes.end(); it++)
	{
		if (it->first != -1)
			leftOver.push_back(std::make_pair(it->first, -1));
		if (it->second != -1)
			leftOver.push_back(std::make_pair(it->second, -1));
	}

	res.setPairsLi(pairs);
	res.setLeftOversLi(leftOver);

	return (res);
}

intPairsList	PmergeMeLi::sortPushed(const leftBehindHandler &origin, const leftBehindHandler &src)
{
	std::list<unsigned int> insertOrder = defineInsertOrderLi(src.getPairsLi().size() + src.getLeftOversLi().size());

	std::list<int> inserted = insertElementsLi(src.getPairsLi(), src.getLeftOversLi(), insertOrder);

	intPairsList res;
	std::list<bool> used(origin.getPairsLi().size(), false);

	cIntListIt insertedIt = inserted.begin();
	intPairsList	ori = origin.getPairsLi();
	for (; insertedIt != inserted.end(); ++insertedIt)
	{
		intPairsList::const_iterator	originIt = ori.begin();
		std::list<bool>::iterator	usedIt = used.begin();
		for (; originIt != ori.end(); ++originIt, ++usedIt)
		{
			if (*insertedIt == originIt->second && !*usedIt)
			{
				res.push_back(*originIt);
				*usedIt = true;
				break;
			}
		}
	}

	return (res);
}
