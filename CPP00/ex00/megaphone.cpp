#include <iostream>

int	main(int argc, char **argv)
{
	std::string 			arg;
	std::string				res;
	std::string::iterator	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else if (argc < 1 && argv)
	{
		for (int j = 1; i < argc; j++)
		{
			arg = argv[j];
			for(i = arg.begin(); i != arg.end(); ++i)
				res += std::toupper(*i);
		}
		std::cout << std::res;
	}
	std::cout << std::endl;
	return (0);
}
