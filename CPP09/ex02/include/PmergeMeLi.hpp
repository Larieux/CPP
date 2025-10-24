#ifndef PMERGEMELI_HPP
# define PMERGEMELI_HPP

#include "PmergeMe.hpp"

typedef std::pair< unsigned int, unsigned int >	basePair;
typedef std::list< basePair >					pairsList;
typedef std::list<unsigned int>::const_iterator	cListIt;
typedef std::list<unsigned int>::iterator		listIt;

class PmergeMeLi
{
public:
	PmergeMeLi();
	PmergeMeLi(const std::vector<unsigned int> &src);
	PmergeMeLi(const PmergeMeLi &src);
	virtual ~PmergeMeLi();

	PmergeMeLi &operator=(const PmergeMeLi &src);

	std::list<unsigned int>	getCont() const;

	void	clearLi();

	std::list<unsigned int>	sortLi();

private:
	std::list<unsigned int>	_cont;

	pairsList				makePairs(std::list<unsigned int> cont);
	std::list<unsigned int>	defineInsertOrderLi(unsigned int numberOfPairs, int lastElement);
	std::list<unsigned int>	insertElementsLi(const pairsList &pairs, int lastElementFirst, int lastElementSecond, std::list<unsigned int> insertOrder);
	cListIt					findSecondsIndex(std::list<unsigned int> &list, cListIt orderIndex);
	unsigned int			binarySearchLi(unsigned int index, unsigned int begin, unsigned int end);
	pairsList				makePairsOfSecond(const pairsList &src);
	pairsList				sortSecondLi(const pairsList &src);
	pairsList				sortPushed(const pairsList &origin, const pairsList &src);

};

#endif