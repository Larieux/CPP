#ifndef PMERGEMELI_HPP
# define PMERGEMELI_HPP

#include "PmergeMe.hpp"

typedef std::pair< int, int >					intPair;
typedef std::list< intPair >					intPairsList;
typedef std::list<int>::const_iterator			cIntListIt;
typedef std::list<int>::iterator				intListIt;
typedef std::pair< unsigned int, unsigned int >	basePair;
typedef std::list< basePair >					pairsList;
typedef std::list<unsigned int>::const_iterator	cListIt;
typedef std::list<unsigned int>::iterator		listIt;

typedef struct s_result_li
{
	intPairsList	pairs;
	intPairsList	leftoverPairs;
}					t_result_li;

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

	t_result_li				makePairs(std::list<unsigned int> cont);
	std::list<unsigned int>	defineInsertOrderLi(unsigned int numberOfPairs);
	std::list<int>			insertElementsLi(const intPairsList &pairs,
	intPairsList forgottenElements, std::list<unsigned int> insertOrder);
	cListIt					findSecIndex(std::list<unsigned int> &list, cListIt orderIndex);
	intListIt				binarySearchLi(std::list<int> &lst,
		int value);
	t_result_li				makePairsOfSecond(const t_result_li &src);
	t_result_li				sortSecondLi(const t_result_li &src);
	intPairsList			sortPushed(const t_result_li &origin, const t_result_li &src);

};

std::ostream& operator<<(std::ostream& out, const pairsList &src);
std::ostream& operator<<(std::ostream& out, const intPairsList &src);

#endif