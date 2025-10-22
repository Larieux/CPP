#ifndef INCEPAIRS_HPP
# define INCEPAIRS_HPP

#include "PmergeMe.hpp"


template < class container >
class incePairs
{
public:
	incePairs();
	incePairs(const container &srcFirst, const container &srcSecond);
	incePairs(const incePairs &src);
	~incePairs();

	incePairs &operator=(const incePairs &src);

	void		setAbomination(const container &src);
	void		setAbomination(const unsigned int &srcFirst, const unsigned int &srcSecond);

	container	getAbomination() const;

	container	sortPairs();

private:
	unsigned int		findSecond(container abomi);
	container			makePairs(container &src);

	container			_abomination;

};

typedef std::list< incePairs< std::pair< const unsigned int, const unsigned int > > > pairsList;

#include "incePairs.tpp"

#endif