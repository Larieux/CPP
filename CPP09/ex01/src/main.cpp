#include "RPN.hpp"


static void test(RPN calculator)
{
	std::cout  << std::endl;
	std::cout << "input: 8 9 * 9 - 9 - 9 - 4 - 1 +" << std::endl;
	calculator.compute("8 9 * 9 - 9 - 9 - 4 - 1 +");
	std::cout  << std::endl;
	std::cout << "input: 7 7 * 7 -" << std::endl;
	calculator.compute( "7 7 * 7 -"); 
	std::cout  << std::endl;
	std::cout << "input: 1 2 * 2 / 2 * 2 4 - +" << std::endl;
	calculator.compute( "1 2 * 2 / 2 * 2 4 - +");
	std::cout  << std::endl;
	std::cout << "input: (1 + 1)" << std::endl;
	calculator.compute( "(1 + 1)");
	std::cout  << std::endl;

	std::cout << "input: 3 4 +" << std::endl;
	calculator.compute("3 4 +");
	std::cout  << std::endl;
	std::cout << "input: 3 4 -" << std::endl;
	calculator.compute("3 4 -");
	std::cout  << std::endl;
	std::cout << "input: 9 9 *" << std::endl;
	calculator.compute( "9 9 *");
	std::cout  << std::endl;
	std::cout << "input: 9 3 /" << std::endl;
	calculator.compute( "9 3 /");
	std::cout  << std::endl;
	std::cout << "input: h" << std::endl;
	calculator.compute( "h");
	std::cout  << std::endl;
	std::cout << "input: 11 + 1" << std::endl;
	calculator.compute( "11 + 1");
	std::cout  << std::endl;
	std::cout << "input: 1 + 1" << std::endl;
	calculator.compute( "1 + 1");
	std::cout  << std::endl;
	std::cout << "input: 1 10 +" << std::endl;
	calculator.compute( "1 10 +");
	std::cout  << std::endl;
	std::cout << "input: 1 -8 +" << std::endl;
	calculator.compute( "1 -8 +");
	std::cout  << std::endl;
	std::cout << "input: 1 0 /" << std::endl;
	calculator.compute( "1 0 /");
	std::cout  << std::endl;
	std::cout << "input: 0 1 /" << std::endl;
	calculator.compute( "0 1 /");
	std::cout  << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout	<< "Usage: ./RPN ['Reverse Police Notation' type input]"
					<< std::endl;
		return (0);
	}
	RPN calculator;
	if (std::string(argv[1]).find("test") != std::string::npos) {
		test(calculator);
	}
	else {
		calculator.compute(argv[1]);
	}
	return (0);
}