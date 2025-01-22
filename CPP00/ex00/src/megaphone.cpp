#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j] ; j++)
			{
				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
					std::cout << (argv[i][j] -= 'a' - 'A');
				else
					std::cout << argv[i][j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
