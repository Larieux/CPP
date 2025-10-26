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
	t_result_vec pairs = makePairs(_cont);

	t_result_vec sortedResult = sortSecondVec(pairs);

	intPairsVector forgottenElements;
	for (intPairsVector::const_iterator it = sortedResult.leftoverPairs.begin();
		it != sortedResult.leftoverPairs.end(); it++)
	{
		if (it->first != -1)
		{
			bool found = false;
			for (intPairsVector::const_iterator ite = pairs.pairs.begin(); ite != pairs.pairs.end(); ++ite) {
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
			for (intPairsVector::const_iterator ite = pairs.pairs.begin(); ite != pairs.pairs.end(); ++ite) {
				if (ite->second == it->second || ite->second == it->second) {
					found = true;
					break;
				}
			}
			if (!found && it->second != -1)
				forgottenElements.push_back(std::make_pair(it->second, -1));
		}
	}
	std::vector<unsigned int> insertOrder = defineInsertOrderVec(sortedResult.pairs.size(), forgottenElements);

	std::vector<int> tmp = insertElementsVec(sortedResult.pairs, forgottenElements, insertOrder);

	std::vector<unsigned int> res(tmp.begin(), tmp.end());

	return (res);
}


t_result_vec	PmergeMeVec::makePairs(std::vector<unsigned int>	cont)
{
	t_result_vec	vector;

	unsigned int a;

	for (vectorIt it = cont.begin(); it != cont.end();)
	{
		a = *(it++);
		if (it == cont.end())
		{
			vector.leftoverPairs.push_back(std::make_pair(a, -1));
			break;
		}
		unsigned int b = *(it++);
		vector.pairs.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	return (vector);
}

std::vector<unsigned int>	PmergeMeVec::defineInsertOrderVec(unsigned int numberOfPairs,
	intPairsVector forgottenElements)
{
	std::vector<unsigned int>	groupSizes;

	groupSizes.push_back(1);
	numberOfPairs += forgottenElements.size();

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

std::vector<int> PmergeMeVec::insertElementsVec(const intPairsVector &pairs,
	intPairsVector forgottenElements, std::vector<unsigned int> insertOrder)
{
	std::vector<unsigned int> first;
	for (intPairsVector::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		first.push_back((*it).first);

	std::vector<int>	second;
	for (intPairsVector::const_iterator it = pairs.begin(); it != pairs.end(); it++)
		second.push_back((*it).second);

	for (intPairsVector::const_iterator it = forgottenElements.begin(); it != forgottenElements.end(); it++)
	{
		if (it->first != -1 && std::find(first.begin(), first.end(), it->first) == first.end())
			first.push_back(it->first);
		if (it->second != -1 && std::find(first.begin(), first.end(), it->second) == first.end())
			first.push_back(it->second);
	}

	for (cVectorIt it = insertOrder.begin(); it != insertOrder.end(); it++)
	{
		cVectorIt	firstIndex = findSecIndex(first, it);

		intVectorIt	findIndex = binarySearchVec(second, *firstIndex);

		second.insert(findIndex, *firstIndex);
	}

	for (cVectorIt it = first.begin(); it != first.end(); ++it)
	{
		if (std::find(second.begin(), second.end(), *it) == second.end())
		{
			intVectorIt findIndex = binarySearchVec(second, *it);
			second.insert(findIndex, *it);
		}
	}

	return (second);
}

cVectorIt	PmergeMeVec::findSecIndex(std::vector<unsigned int> &vector, cVectorIt orderIndex)
{
	cVectorIt	res = vector.begin();

	for (unsigned int i = 0; i < *orderIndex; i++)
		res++;

	return (res);
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


t_result_vec	PmergeMeVec::makePairsOfSecond(const t_result_vec &src)
{
	intPairsVector::const_iterator it = src.pairs.begin();
	intPairsVector	vector;
	t_result_vec	res;
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
		vector.push_back(std::make_pair(std::min(a, b), std::max(a, b)));
	}

	res.pairs = vector;
	return (res);
}

t_result_vec PmergeMeVec::sortSecondVec(const t_result_vec &src)
{
	t_result_vec	pairsOfSecond = makePairsOfSecond(src);

	t_result_vec recResult;
	if (pairsOfSecond.pairs.size() > 1)
		recResult = sortSecondVec(pairsOfSecond);
	else {
		recResult = pairsOfSecond;
	}

	intPairsVector sorted = sortPushed(src.pairs, recResult.pairs);

	t_result_vec res;
	res.pairs = sorted;
	res.leftoverPairs = src.leftoverPairs;
	for (intPairsVector::const_iterator it = recResult.leftoverPairs.begin();
		it != recResult.leftoverPairs.end(); it++)
	{
		if (it->first != -1)
			res.leftoverPairs.push_back(std::make_pair(it->first, -1));
		if (it->second != -1)
			res.leftoverPairs.push_back(std::make_pair(it->second, -1));
	}
	
	return (res);
}

intPairsVector	PmergeMeVec::sortPushed(const intPairsVector &origin, const intPairsVector &src)
{
	intPairsVector	forgottenElements;

	std::vector<unsigned int>	insertOrder = defineInsertOrderVec(src.size(),
		forgottenElements);

	std::vector<int>	inserted = insertElementsVec(src, forgottenElements, insertOrder);

	std::cerr << "src: " << src << std::endl;

	intPairsVector	res;
	std::vector<bool> usedIndic(origin.size(), false);

	for (cIntVectorIt it = inserted.begin(); it != inserted.end(); it++)
	{
		unsigned int j = 0;
		for (intPairsVector::const_iterator originIt = origin.begin();
			originIt != origin.end(); ++originIt, j++)
		{
			if (usedIndic[j])
				continue;
			if (*it == originIt->first || *it == originIt->second)
			{
				res.push_back(*originIt);
				usedIndic[j] = true;
				break;
			}
		}
	}
	std::cerr << "res: " << res << std::endl;

	return (res);
}
