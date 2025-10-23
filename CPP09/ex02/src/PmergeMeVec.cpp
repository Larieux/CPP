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
	
	return (_cont);
}


pairsVector PmergeMeVec::makePairs()
{
	pairsVector	pairs;

	std::vector<unsigned int>::const_iterator it = _cont.begin();
	it++;
	for (std::vector<unsigned int>::const_iterator ite = _cont.begin(); it != _cont.end();)
	{
		if (*it < *ite)
			pairs.push_back(std::make_pair(*it, *ite));
		else
			pairs.push_back(std::make_pair(*ite, *it));

		it++;
		ite++;
		if (it == _cont.end())
			return (pairs);
		it++;
		ite++;
	}

	return (pairs);
}
