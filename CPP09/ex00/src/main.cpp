#include "BitcoinExchange.hpp"

int	main( int argc, char **argv )
{
	// Use a map!!
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (0);
	}

	BitcoinExchange do_the_thing;

	if (!do_the_thing.parseData(DATA_FILE))
		return (1);

	do_the_thing.convert(argv[1]);

	return (0);
}
