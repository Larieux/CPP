#ifndef PMERGEMELI_HPP
# define PMERGEMELI_HPP

#include "PmergeMe.hpp"

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

};

#endif