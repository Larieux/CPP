#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP

#include "PmergeMe.hpp"

typedef std::pair< unsigned int, unsigned int > basePair;
typedef std::vector< basePair > pairsVector;

class PmergeMeVec : public PmergeMe< std::vector<unsigned int> >
{
public:
	PmergeMeVec();
	PmergeMeVec(const std::vector<unsigned int> &src);
	PmergeMeVec(const PmergeMeVec &src);
	virtual ~PmergeMeVec();

	PmergeMeVec &operator=(const PmergeMeVec &src);

	std::vector<unsigned int>	sortVec();

private:
	pairsVector makePairs();
	pairsVector	makePairsOfSecond(const pairsVector &src);
	pairsVector	sortSecondVec(const pairsVector &src);

};

#endif