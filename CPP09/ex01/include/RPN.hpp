#ifndef RPN_HPP
# define RPN_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stack>
#include <ctime>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

class RPN
{
private:
	std::stack<int>	stack;

public:
	RPN();
	RPN(const RPN& src);
	RPN& operator=(const RPN& src);
	~RPN();

	void compute(std::string const &expression);

	class Error : public std::exception
	{
		private:
			std::string	msg;

		public :
			Error(const std::string &msg);
			virtual ~Error() throw();
			virtual const char *what() const throw();
	};
};

#endif