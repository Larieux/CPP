#include "Span.hpp"


Span::Span(unsigned int n): N(n)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span	&Span::operator=(const Span &src)
{
	if (this != &src) {
		N = src.N;
		vec.clear();
		for (unsigned int i = 0; i < src.getVec().size(); i++)
			vec.push_back(src.getVec()[i]);
	}
	return (*this);
}

const std::vector<int>	Span::getVec() const
{
	return (vec);
}

Span::~Span()
{
}

void	Span::addNumber(int n)
{
	if (N <= vec.size())
		throw (std::out_of_range("Span already full >:3"));
	vec.push_back(n);
}

unsigned int	Span::shortestSpan()
{
	unsigned int	minSpan;

	minSpan = UINT_MAX;
	if (vec.size() < 2) {
		throw (std::domain_error("please add numbers in the span for this to work -_-"));
	}
	std::sort(vec.begin(), vec.end());
	for (unsigned int i = 1; i < vec.size(); i++) {
		minSpan = std::min(minSpan,
			static_cast<unsigned int>(std::abs(vec[i] - vec[i - 1])));	
	}
	return (minSpan);
}

unsigned int	Span::longestSpan()
{
	if (vec.size() < 2) {
		throw (std::domain_error("please add numbers in the span for this to work -_-"));
	}
	return (*std::max_element(vec.begin(),
		vec.end()) - *std::min_element(vec.begin(), vec.end()));
}
