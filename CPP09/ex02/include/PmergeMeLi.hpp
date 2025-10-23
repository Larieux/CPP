#ifndef PMERGEMELI_HPP
# define PMERGEMELI_HPP

#include "PmergeMe.hpp"

typedef std::pair< unsigned int, unsigned int > basePair;
typedef std::list< basePair > pairsList;

class PmergeMeLi : public PmergeMe< std::list<unsigned int> >
{
public:
	PmergeMeLi();
	PmergeMeLi(const std::vector<unsigned int> &src);
	PmergeMeLi(const PmergeMeLi &src);
	virtual ~PmergeMeLi();

	PmergeMeLi &operator=(const PmergeMeLi &src);

	std::list<unsigned int>	sortLi();

private:
	pairsList	makePairs();
	pairsList	makePairsOfSecond(const pairsList &src);
	pairsList	sortSecondLi(const pairsList &src);
	pairsList	sortPushed(const pairsList &src);

};

#endif