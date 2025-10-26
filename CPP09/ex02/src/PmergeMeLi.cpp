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
	t_result_li pairs = makePairs(_cont);

	t_result_li sortedResult = sortSecondLi(pairs);

	intPairsList forgottenElements;
	for (intPairsList::const_iterator it = sortedResult.leftoverPairs.begin();
		it != sortedResult.leftoverPairs.end(); it++)
	{
		if (it->first != -1)
		{
			bool found = false;
			for (intPairsList::const_iterator ite = pairs.pairs.begin(); ite != pairs.pairs.end(); ++ite) {
				if (ite->first == it->first || ite->second == it->first) {
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
			for (intPairsList::const_iterator ite = pairs.pairs.begin(); ite != pairs.pairs.end(); ++ite) {
				if (ite->first == it->second || ite->second == it->second) {
					found = true;
					break;
				}
			}
			if (!found && it->second != -1)
				forgottenElements.push_back(std::make_pair(it->second, -1));
		}
	}
	std::list<unsigned int> insertOrder = defineInsertOrderLi(sortedResult.pairs.size() + forgottenElements.size());

	std::list<int> tmp = insertElementsLi(sortedResult.pairs, forgottenElements, insertOrder);

	std::list<unsigned int> res(tmp.begin(), tmp.end());

	return (res);
}


t_result_li	PmergeMeLi::makePairs(std::list<unsigned int>	cont)
{
	t_result_li	list;

	unsigned int a;

	for (listIt it = cont.begin(); it != cont.end();)
	{
		a = *(it++);
		if (it == cont.end())
		{
			list.leftoverPairs.push_back(std::make_pair(a, -1));
			break;
		}
		unsigned int b = *(it++);
		list.pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

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


t_result_li	PmergeMeLi::makePairsOfSecond(const t_result_li &src)
{
	intPairsList::const_iterator it = src.pairs.begin();
	intPairsList	list;
	t_result_li	res;
	bool hasLeftover = false;

	unsigned int a;

	for (; it != src.pairs.end();)
	{
		a = (it++)->second;
		if (it == src.pairs.end())
		{
			res.leftoverPairs.push_back(std::make_pair(a, -1));
			hasLeftover = true;
			break;
		}
		unsigned int b = (it++)->second;
		list.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	res.pairs = list;
	return (res);
}

t_result_li PmergeMeLi::sortSecondLi(const t_result_li &src)
{
	t_result_li	pairsOfSecond = makePairsOfSecond(src);

	t_result_li recResult;
	if (pairsOfSecond.pairs.size() > 1)
		recResult = sortSecondLi(pairsOfSecond);
	else {
		recResult = pairsOfSecond;
	}

	intPairsList sorted = sortPushed(src, recResult);

	t_result_li res;
	res.pairs = sorted;
	res.leftoverPairs = src.leftoverPairs;
	for (intPairsList::const_iterator it = recResult.leftoverPairs.begin();
		it != recResult.leftoverPairs.end(); it++)
	{
		if (it->first != -1)
			res.leftoverPairs.push_back(std::make_pair(it->first, -1));
		if (it->second != -1)
			res.leftoverPairs.push_back(std::make_pair(it->second, -1));
	}
	
	return (res);
}

intPairsList	PmergeMeLi::sortPushed(const t_result_li &origin, const t_result_li &src)
{
	std::list<unsigned int> insertOrder = defineInsertOrderLi(src.pairs.size() + src.leftoverPairs.size());

	std::list<int> inserted = insertElementsLi(src.pairs, src.leftoverPairs, insertOrder);

	intPairsList res;
	std::list<bool> used(origin.pairs.size(), false);

	cIntListIt insertedIt = inserted.begin();
	for (; insertedIt != inserted.end(); ++insertedIt)
	{
		intPairsList::const_iterator	originIt = origin.pairs.begin();
		std::list<bool>::iterator	usedIt = used.begin();
		for (; originIt != origin.pairs.end(); ++originIt, ++usedIt)
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
