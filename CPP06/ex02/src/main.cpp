#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	{
		std::cout << "--- Test using random generator ---" << std::endl;
		srand(time(NULL));
		Base *base = generate();
		std::cout << "Identifying pointer:" << std::endl;
		identify(base);
		std::cout << "Identifying reference:" << std::endl;
		identify(*base);

		std::cout << "\n";

		Base *base1 = generate();
		std::cout << "Identifying pointer:" << std::endl;
		identify(base1);
		std::cout << "Identifying reference:" << std::endl;
		identify(*base1);
		delete base1;
		delete base;
	}
	{
		std::cout << "\n--- Test with Null base pointer ---" << std::endl;
		srand(time(NULL));
		Base *base = NULL;
		std::cout << "Identifying pointer:" << std::endl;
		identify(base);
		std::cout << "Identifying reference:" << std::endl;
		identify(*base);
		delete base;
	}

	return (0);
}