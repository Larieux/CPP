#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP

#include "PmergeMe.hpp"

typedef std::pair< unsigned int, unsigned int >		basePair;
typedef std::vector< basePair >						pairsVector;
typedef std::vector<unsigned int>::const_iterator	cVectorIt;
typedef std::vector<unsigned int>::iterator			vectorIt;

class PmergeMeVec
{
public:
	PmergeMeVec();
	PmergeMeVec(const std::vector<unsigned int> &src);
	PmergeMeVec(const PmergeMeVec &src);
	virtual ~PmergeMeVec();

	PmergeMeVec &operator=(const PmergeMeVec &src);

	std::vector<unsigned int>	getCont() const;

	void	clearVec();

	std::vector<unsigned int>	sortVec();

private:
	std::vector<unsigned int>	_cont;

	pairsVector					makePairs(std::vector<unsigned int> cont);
	std::vector<unsigned int>	defineInsertOrderVec(unsigned int numberOfPairs, int lastElement);
	std::vector<unsigned int>	insertElementsVec(const pairsVector &pairs,
		int lastElementFirst, int lastElementSec, std::vector<unsigned int> insertOrder);
	cVectorIt					findSecIndex(std::vector<unsigned int> &vector, cVectorIt orderIndex);
	unsigned int				binarySearchVec(unsigned int index, unsigned int begin, unsigned int end);
	pairsVector					makePairsOfSecond(const pairsVector &src);
	pairsVector					sortSecondVec(const pairsVector &src);
	pairsVector					sortPushed(const pairsVector &origin, const pairsVector &src);
};

#endif