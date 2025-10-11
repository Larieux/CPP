#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T				*array;
	unsigned int	size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	Array	&operator=(const Array &src);
	~Array();

	T		&operator[](unsigned int index);
	const T	&operator[](unsigned int index) const;

	unsigned int	getSize() const;
};

#endif