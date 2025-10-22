#ifndef INCEPAIRSLIST_HPP
# define INCEPAIRSLIST_HPP

#include "PmergeMe.hpp"

template < class container >
class incePairsList
{
public:
	incePairsList();
	incePairsList(const container &src);
	incePairsList(const incePairsList &src);
	~incePairsList();

	incePairsList &operator=(const incePairsList &src);

	container	getAbomination() const;

	container	sortPairs();

private:
	unsigned int	findSecond(typename container::const_iterator it);
	container		makePairs();

	container	_abomination;

};

#include "incePairsList.tpp"

#endif