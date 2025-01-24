
#include <iostream>
#include "Phonebook.hpp"
#include "include/PhoneBook.hpp"

int	main(void)
{
	Phonebook	phone_book;
	std::string	line;

	PhoneBook::show_menu(init);
	while (std::cin.eof() == false)
	{
		std::getline(std::cin, line);
		if (line.compare("EXIT") == 0)
			break ;
		else if (line.compare("ADD") == 0)
			PhoneBook::add_contact(phone_book);
		else if (line.compare("SEARCH") == 0)
			PhoneBook::search_contact(phone_book);
		else if (std::cin.eof() == false)
			std::cout "\nInvalid input, try:\nADD/SEARCH/EXIT\n" << std::endl;
		PhoneBook::show_menu(menu);
	}
	PhoneBook::show_menu(end);
	return (0);
}
