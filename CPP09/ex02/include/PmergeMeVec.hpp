#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP

#include "PmergeMe.hpp"

typedef std::pair< unsigned int, unsigned int >		basePair;
typedef std::vector< basePair > pairsVector;
typedef std::vector<unsigned int>::const_iterator	cVectorIt;
typedef std::vector<unsigned int>::iterator			vectorIt;

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
	pairsVector	makePairs();
	std::vector<unsigned int>	defineInsertOrderVec(unsigned int numberOfPairs, int lastElement);
	std::vector<unsigned int> insertElementsVec(const pairsVector &pairs, int lastElement, std::vector<unsigned int> insertOrder);
	cVectorIt		findSecondsIndex(std::vector<unsigned int> &vector, cVectorIt orderIndex);
	vectorIt		binarySearchVec(cVectorIt index, vectorIt begin, cVectorIt end, const std::vector<unsigned int> &vector);
	pairsVector	makePairsOfSecond(const pairsVector &src);
	pairsVector	sortSecondVec(const pairsVector &src);
	pairsVector	sortPushed(const pairsVector &src);
};

#endif