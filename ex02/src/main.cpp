#include "Span.hpp"

#define MAX 99999

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Add number: 6\nAdd number: 3\nAdd number: 17" << std::endl;
		std::cout << "Add number: 9\nAdd number: 11" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		try {
			std::cout << "\nAdd number: 4" << std::endl;
			sp.addNumber(4);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	{
		Span sp = Span(MAX);
		try
		{
			sp.addNumber(999);
			for (unsigned int i = 0; i < MAX - 1; i++)
			{
				sp.addNumber(i * 42);
			}
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		Span sp = Span(42);
		try
		{
			for (unsigned int i = 0; i < 42; i++)
			{
				sp.addNumber(i * 42);
			}
			sp.addNumber(1);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{

		Span sp = Span(MAX);
		std::vector<int> vect;
		for (unsigned int i = 0; i < MAX; i++) {
			vect.push_back(i);
		}
		try {
			sp.addRange(vect.begin(), vect.end());
			std::cout << "add range of vec of size: " << MAX << std::endl;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{

		Span sp = Span(MAX);
		std::vector<int> vect;
		for (unsigned int i = 0; i <= MAX; i++) {
			vect.push_back(i);
		}
		try {
			sp.addRange(vect.begin(), vect.end());
			std::cout << "add range of vec of size: " << MAX << std::endl;
			std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}