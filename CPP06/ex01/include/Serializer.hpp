#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <stdint.h>

typedef struct	SData
{
	int	value;

} Data;

class Serializer
{
public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &src);
};

#endif