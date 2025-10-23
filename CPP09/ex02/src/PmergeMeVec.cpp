#include "PmergeMeVec.hpp"

PmergeMeVec::PmergeMeVec() : PmergeMe< std::vector<unsigned int> >()
{

}

PmergeMeVec::PmergeMeVec(const std::vector<unsigned int> &src) : PmergeMe< std::vector<unsigned int> >(src)
{

}

PmergeMeVec::PmergeMeVec(const PmergeMeVec &src):
	PmergeMe< std::vector<unsigned int> >(src)
{
	*this = src;
}

PmergeMeVec::~PmergeMeVec()
{

}


PmergeMeVec &PmergeMeVec::operator=(const PmergeMeVec &src)
{
	_cont = src.getCont();

	return (*this);
}


std::vector<unsigned int>	PmergeMeVec::sortVec()
{
	pairsVector	pairs = makePairs();
	pairsVector	sortedSecond = sortSecondVec(pairs);


	return (_cont);
}


pairsVector	PmergeMeVec::makePairs()
{
	pairsVector	vector;

	std::vector<unsigned int>::const_iterator it = _cont.begin();
	it++;

	std::vector<unsigned int>::const_iterator ite = _cont.begin();


	for (; it != _cont.end();)
	{
		if (*it < *ite)
			vector.push_back(std::make_pair(*it, *ite));
		else
			vector.push_back(std::make_pair(*ite, *it));


		it++;
		ite++;
		if (it == _cont.end())
			return (vector);
		it++;
		ite++;
		if (it == _cont.end())
			return (vector);

	}

	return (vector);
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
	pairsVector	sortedPairsOfSecond;
	pairsVector	sorted;

	if (pairsOfSecond.size() > 2)
		sortedPairsOfSecond = sortSecondVec(pairsOfSecond);

	std::vector<basePair>::const_iterator it = sortedPairsOfSecond.end()--;
	for (; it != sortedPairsOfSecond.begin(); it--)
		sorted.push_back(*it);
	sorted.push_back(*it);

	return (sorted);
}
