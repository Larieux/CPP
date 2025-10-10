#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <cstdlib>

class Base
{

public:
	virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif