#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP

#include "PmergeMe.hpp"

typedef std::pair< int, int >						intPair;
typedef std::vector< intPair >						intPairsVector;
typedef std::vector<int>::const_iterator			cIntVectorIt;
typedef std::vector<int>::iterator					intVectorIt;
typedef std::pair< unsigned int, unsigned int >		basePair;
typedef std::vector< basePair >						pairsVector;
typedef std::vector<unsigned int>::const_iterator	cVectorIt;
typedef std::vector<unsigned int>::iterator			vectorIt;

typedef struct s_result_vec
{
	intPairsVector	pairs;
	intPairsVector	leftoverPairs;
}					t_result_vec;

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

	t_result_vec				makePairs(std::vector<unsigned int> cont);
	std::vector<unsigned int>	defineInsertOrderVec(unsigned int numberOfPairs);
	std::vector<int>			insertElementsVec(const intPairsVector &pairs,
	intPairsVector forgottenElements, std::vector<unsigned int> insertOrder);
	intVectorIt					binarySearchVec(std::vector<int> &lst,
		int value);
	t_result_vec				makePairsOfSecond(const t_result_vec &src);
	t_result_vec				sortSecondVec(const t_result_vec &src);
	intPairsVector				sortPushed(const t_result_vec &origin, const t_result_vec &src);
};

std::ostream& operator<<(std::ostream& out, const pairsVector &src);
std::ostream& operator<<(std::ostream& out, const intPairsVector &src);

#endif