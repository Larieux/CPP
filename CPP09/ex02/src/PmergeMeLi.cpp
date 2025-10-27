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

	std::list<unsigned int> insertOrder = defineInsertOrderLi(sortedResult.getPairsLi().size()
		+ sortedResult.getLeftOversLi().size());

	std::list<int> tmp = insertElementsLi(sortedResult, insertOrder);

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

std::list<int>	PmergeMeLi::insertElementsLi(const leftBehindHandler &src,
	std::list<unsigned int> insertOrder)
{
	std::list<int>	first;
	std::list<int>	second;
	intPairsList	srcPairs = src.getPairsLi();

	for (intPairsList::const_iterator it = srcPairs.begin(); it != srcPairs.end(); it++)
	{
		if (it->first != -1 && std::find(first.begin(), first.end(), it->first) == first.end())
			first.push_back(it->first);
		if (it->second != -1 && std::find(second.begin(), second.end(), it->second) == second.end())
			second.push_back(it->second);
	}

	srcPairs.clear();
	srcPairs = src.getLeftOversLi();
	for (intPairsList::const_iterator it = srcPairs.begin();
		it != srcPairs.end(); it++)
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

		cIntListIt valueIt = first.begin();
		std::advance(valueIt, *it);
		int value = *valueIt;

		intListIt findIndex = binarySearchLi(second, value);

		second.insert(findIndex, value);
	}

	for (cIntListIt it = first.begin(); it != first.end(); ++it)
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

	unsigned int a;

	leftOver = src.getLeftOversLi();

	for (; it != srcCpy.end();)
	{
		a = (it++)->second;
		if (it == srcCpy.end())
		{
			leftOver.push_back(std::make_pair(a, -1));
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

	res.setPairsLi(sorted);

	return (res);
}

intPairsList	PmergeMeLi::sortPushed(const leftBehindHandler &origin
	, const leftBehindHandler &src)
{
	std::list<unsigned int> insertOrder = defineInsertOrderLi(src.getPairsLi().size()
		+ src.getLeftOversLi().size());

	std::list<int> inserted = insertElementsLi(src, insertOrder);

	intPairsList res;

	intPairsList		ori = origin.getPairsLi();
	intPairsList		oriLeftOver = origin.getLeftOversLi();

	std::list<bool>	used(ori.size(), false);
	std::list<bool>	usedLeftOver(oriLeftOver.size(), false);

	cIntListIt insertedIt = inserted.begin();
	for (; insertedIt != inserted.end(); insertedIt++)
	{
		intPairsList::const_iterator	originIt = ori.begin();
		std::list<bool>::iterator	usedIt = used.begin();
		for (; originIt != ori.end(); originIt++, usedIt++)
		{
			if (*insertedIt == originIt->second && !*usedIt)
			{
				res.push_back(*originIt);
				*usedIt = true;
				break;
			}
		}
		originIt = oriLeftOver.begin();
		usedIt = usedLeftOver.begin();
		for (; originIt != oriLeftOver.end(); originIt++, usedIt++)
		{
			if ((*insertedIt == originIt->first || *insertedIt == originIt->second)
				&& !*usedIt)
			{
				res.push_back(*originIt);
				*usedIt = true;
				break;
			}
		}
	}

	return (res);
}
