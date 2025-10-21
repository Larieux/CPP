#ifndef PMERGEMEINPUT_HPP
# define PMERGEMEINPUT_HPP

#include "PmergeMe.hpp"

class PmergeMeInput : public PmergeMe< std::vector<int> >
{
public:
	PmergeMeInput();
	PmergeMeInput(int argc = 0, char **argv = NULL);
	PmergeMeInput(const PmergeMeInput &src);
	virtual ~PmergeMeInput();

	PmergeMeInput &operator=(const PmergeMeInput &src);

	void	fillInput(char **argv);

private:

};

#endif