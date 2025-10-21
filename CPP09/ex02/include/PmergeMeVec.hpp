#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP

#include "PmergeMe.hpp"

class PmergeMeVec : public PmergeMe< std::vector<int> >
{
public:
	PmergeMeVec();
	PmergeMeVec(const std::vector<int> &src);
	PmergeMeVec(const PmergeMeVec &src);
	virtual ~PmergeMeVec();

	PmergeMeVec &operator=(const PmergeMeVec &src);

private:

};

#endif