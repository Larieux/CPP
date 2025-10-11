#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int to_find);

#endif