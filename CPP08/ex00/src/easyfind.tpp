#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator found = std::find(container.begin(), container.end(), to_find);
	if (found == container.end()) {
		throw (std::runtime_error("value not found."));
	}
	return (found);
}