#include "easyfind.tpp"

int	main( void )
{
	std::vector<int>	vect;
	std::list<int>		list;
	std::deque<int>		deq;

	for (int i = 0; i < 9; i++)
	{
		vect.push_back(i);
		list.push_back(i);
		deq.push_back(i);
	}

	try {
		std::cout << *easyfind(vect, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind(list, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind(deq, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << *easyfind(vect, 9) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind(list, 9) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << *easyfind(deq, 9) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
