#ifndef PMERGEMELI_HPP
# define PMERGEMELI_HPP

#include "PmergeMe.hpp"

class PmergeMeLi : public PmergeMe< std::list<int> >
{
public:
	PmergeMeLi();
	PmergeMeLi(const std::vector<int> &src);
	PmergeMeLi(const PmergeMeLi &src);
	virtual ~PmergeMeLi();

	PmergeMeLi &operator=(const PmergeMeLi &src);

private:

};

#endif