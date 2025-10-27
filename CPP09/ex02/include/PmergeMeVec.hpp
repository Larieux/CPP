#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP

#include "leftBehindHandler.hpp"

typedef std::pair< int, int >						intPair;
typedef std::vector< intPair >						intPairsVector;
typedef std::vector<int>::const_iterator			cIntVectorIt;
typedef std::vector<int>::iterator					intVectorIt;
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
	~PmergeMeVec();

	PmergeMeVec &operator=(const PmergeMeVec &src);

	std::vector<unsigned int>	getCont() const;

	void	clearVec();

	std::vector<unsigned int>	sortVec();

private:
	std::vector<unsigned int>	_cont;

	leftBehindHandler				makePairs(std::vector<unsigned int> cont);
	std::vector<unsigned int>		defineInsertOrderVec(unsigned int numberOfPairs);
	std::vector<int>				insertElementsVec(const leftBehindHandler &src,
		std::vector<unsigned int> insertOrder);
	intVectorIt						binarySearchVec(std::vector<int> &lst,
		int value);
	leftBehindHandler				makePairsOfSecond(const leftBehindHandler &src);
	leftBehindHandler				sortSecondVec(const leftBehindHandler &src);
	intPairsVector					sortPushed(const leftBehindHandler &origin,
		const leftBehindHandler &src);
};

std::ostream& operator<<(std::ostream& out, const pairsVector &src);
std::ostream& operator<<(std::ostream& out, const intPairsVector &src);

#endif