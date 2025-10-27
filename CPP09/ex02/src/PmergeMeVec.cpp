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

std::ostream& operator<<(std::ostream& out, const intPairsVector &src)
{
	for (intPairsVector::const_iterator it = src.begin(); it != src.end(); it++)
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
	leftBehindHandler pairs = makePairs(_cont);

	leftBehindHandler sortedResult = sortSecondVec(pairs);

	std::vector<unsigned int> insertOrder = defineInsertOrderVec(sortedResult.getPairsVec().size()
		+ sortedResult.getLeftOversVec().size());

	std::vector<int> tmp = insertElementsVec(sortedResult, insertOrder);

	std::vector<unsigned int> res(tmp.begin(), tmp.end());

	return (res);
}


leftBehindHandler	PmergeMeVec::makePairs(std::vector<unsigned int>	cont)
{
	leftBehindHandler	vector;
	intPairsVector		leftOver;
	intPairsVector		pairs;

	unsigned int a;

	for (vectorIt it = cont.begin(); it != cont.end();)
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

	vector.setPairsVec(pairs);
	vector.setLeftOversVec(leftOver);

	return (vector);
}

std::vector<unsigned int>	PmergeMeVec::defineInsertOrderVec(unsigned int numberOfPairs)
{
	std::vector<unsigned int>	groupSizes;

	groupSizes.push_back(1);

	std::vector<unsigned int> jSeq;
	jSeq.push_back(1);
	jSeq.push_back(3);
	while (jSeq.back() < numberOfPairs + 1)
	{
		vectorIt last = jSeq.end();
		--last;
		vectorIt secondLast = last;
		--secondLast;

		jSeq.push_back((*last) + (2 * (*secondLast)));
	}

	std::vector<unsigned int> indexOrder;
	std::vector<bool> used(numberOfPairs, false);

	for (std::vector<unsigned int>::iterator it = jSeq.begin(); it != jSeq.end(); ++it)
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

std::vector<int> PmergeMeVec::insertElementsVec(const leftBehindHandler &src,
	std::vector<unsigned int> insertOrder)
{
	std::vector<int>	first;
	std::vector<int>	second;
	intPairsVector	srcPairs = src.getPairsVec();

	for (intPairsVector::const_iterator it = srcPairs.begin(); it != srcPairs.end(); it++)
	{
		if (it->first != -1 && std::find(first.begin(), first.end(), it->first) == first.end())
			first.push_back(it->first);
		if (it->second != -1 && std::find(second.begin(), second.end(), it->second) == second.end())
			second.push_back(it->second);
	}

	srcPairs.clear();
	srcPairs = src.getLeftOversVec();
	for (intPairsVector::const_iterator it = srcPairs.begin();
		it != srcPairs.end(); it++)
	{
		if (it->first != -1 && std::find(first.begin(), first.end(), it->first) == first.end())
			first.push_back(it->first);
		if (it->second != -1 && std::find(first.begin(), first.end(), it->second) == first.end())
			first.push_back(it->second);
	}

	for (cVectorIt it = insertOrder.begin(); it != insertOrder.end(); it++)
	{
		if (*it >= first.size())
			continue;

		int value = first[*it];

		intVectorIt	findIndex = binarySearchVec(second, value);

		second.insert(findIndex, value);
	}

	for (size_t i = 0; i < first.size(); ++i)
	{
		int val = first[i];
		if (std::find(second.begin(), second.end(), val) == second.end())
		{
			intVectorIt pos = binarySearchVec(second, val);
			second.insert(pos, val);
		}
	}

	return (second);
}

intVectorIt PmergeMeVec::binarySearchVec(std::vector<int> &lst,
	int value)
{
	intVectorIt low = lst.begin();
	intVectorIt high = lst.end();

	while (low != high)
	{
		intVectorIt mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (*mid < value)
			low = ++mid;
		else
			high = mid;
	}
	return (low);
}


leftBehindHandler	PmergeMeVec::makePairsOfSecond(const leftBehindHandler &src)
{
	intPairsVector					srcCpy = src.getPairsVec();
	intPairsVector::const_iterator	it = srcCpy.begin();
	intPairsVector					vector;
	leftBehindHandler				res;
	intPairsVector					leftOver;

	unsigned int a;

	leftOver = src.getLeftOversVec();

	for (; it != srcCpy.end();)
	{
		a = (it++)->second;
		if (it == srcCpy.end())
		{
			leftOver.push_back(std::make_pair(a, -1));
			break;
		}
		unsigned int b = (it++)->second;
		vector.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	res.setPairsVec(vector);
	res.setLeftOversVec(leftOver);
	return (res);
}

leftBehindHandler PmergeMeVec::sortSecondVec(const leftBehindHandler &src)
{
	leftBehindHandler	pairsOfSecond = makePairsOfSecond(src);

	leftBehindHandler recResult;
	if (pairsOfSecond.getPairsVec().size() > 1)
		recResult = sortSecondVec(pairsOfSecond);
	else
		recResult = pairsOfSecond;

	intPairsVector sorted = sortPushed(src, recResult);

	leftBehindHandler	res;

	res.setPairsVec(sorted);
	
	return (res);
}

intPairsVector	PmergeMeVec::sortPushed(const leftBehindHandler &origin
	, const leftBehindHandler &src)
{
	std::vector<unsigned int>	insertOrder = defineInsertOrderVec(src.getPairsVec().size()
		+ src.getLeftOversVec().size());

	std::vector<int>	inserted = insertElementsVec(src, insertOrder);

	intPairsVector	res;

	intPairsVector		ori = origin.getPairsVec();
	intPairsVector		oriLeftOver = origin.getLeftOversVec();

	std::vector<bool>	used(ori.size(), false);
	std::vector<bool>	usedLeftOver(oriLeftOver.size(), false);

	for (size_t i = 0; i < inserted.size(); ++i)
	{
		for (size_t j = 0; j < ori.size(); j++)
		{
			if (inserted[i] == ori[j].second && !used[j])
			{
				res.push_back(ori[j]);
				used[j] = true;
				break;
			}
		}
		for (size_t j = 0; j < oriLeftOver.size(); j++)
		{
			if ((inserted[i] == oriLeftOver[j].first || inserted[i] == oriLeftOver[j].second)
				&& !usedLeftOver[j])
			{
				res.push_back(oriLeftOver[j]);
				usedLeftOver[j] = true;
				break;
			}
		}
	}

	return (res);
}
