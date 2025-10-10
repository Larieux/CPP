#include "Iter.hpp"

int	main( void )
{
	size_t	dit_array[] = {0, 1, 42, 'a'};
	std::string	str_array[] = {"my", "eyes", "are", "made", "of", "acid"};

	iter(dit_array, 4, print_value);
	iter(dit_array, 4, double_value);
	iter(dit_array, 4, print_value);

	iter(str_array, 6, print_value);
	iter(str_array, 6, double_value);
	iter(str_array, 6, print_value);

	const std::string	const_str_array[] = {"my", "tongue", "is", "sharp", "with", "spite"};

	iter(const_str_array, 6, print_value);

	return (0);
}