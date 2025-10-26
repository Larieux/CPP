#ifndef LEFTBEHINDHANDLER_HPP
# define LEFTBEHINDHANDLER_HPP

#include "PmergeMe.hpp"

typedef std::pair< int, int >					intPair;
typedef std::list< intPair >					intPairsList;
typedef std::pair< int, int >					intPair;
typedef std::vector< intPair >					intPairsVector;

class leftBehindHandler
{
public:
	leftBehindHandler();
	leftBehindHandler(const leftBehindHandler &src);
	~leftBehindHandler();

	leftBehindHandler &operator=(const leftBehindHandler &src);

	intPairsList	getPairsLi() const;
	intPairsList	getLeftOversLi() const;
	intPairsVector	getPairsVec() const;
	intPairsVector	getLeftOversVec() const;

	void	setPairsLi(const intPairsList &src);
	void	setLeftOversLi(const intPairsList &src);
	void	setPairsVec(const intPairsVector &src);
	void	setLeftOversVec(const intPairsVector &src);

private:
	intPairsList	pairsLi;
	intPairsList	leftoverPairsLi;
	intPairsVector	pairsVec;
	intPairsVector	leftoverPairsVec;

};

#endif