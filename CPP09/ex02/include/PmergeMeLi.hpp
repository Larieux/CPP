#ifndef PMERGEMELI_HPP
# define PMERGEMELI_HPP

#include "PmergeMe.hpp"
#include "incePairs.hpp"

typedef incePairs< std::pair< const unsigned int, const unsigned int > > pairsInception;
typedef std::list< pairsInception > pairsList;

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
	pairsList	launchIncePairs();
	std::pair< pairsInception, pairsInception >	makePairs();

};

#endif