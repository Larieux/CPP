#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <climits>

class Span
{
public:
	Span();
	Span(unsigned int n);
	Span(Span const &src);
	Span &operator=(Span const &src);
	~Span();

	const std::vector<int>	getVec() const;

	void			addNumber(int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();

	template <typename Iterator>
	void	addRange(Iterator begin, Iterator end)
	{
		if (distance(begin, end) + vec.size() > N) {
			throw (std::out_of_range("not enough space left in the span T_T"));
		}
		vec.insert(vec.end(), begin, end);
	}

private:
	unsigned int		N;
	std::vector<int>	vec;
};

#endif