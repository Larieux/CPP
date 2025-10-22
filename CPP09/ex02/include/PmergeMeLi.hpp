#ifndef PMERGEMELI_HPP
# define PMERGEMELI_HPP

#include "PmergeMe.hpp"
#include "incePairsList.hpp"

typedef std::list< std::pair<unsigned int, unsigned int> > pairsList;

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

};

#endif