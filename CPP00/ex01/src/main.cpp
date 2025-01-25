
#include <iostream>
#include <iomanip>	// std::setw
#include <cstdlib>	// std::atoi
#include "Phonebook.hpp"

bool	ft_isnum(std::string line)
{
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
		if (isdigit(*it) == false)
			return (false);
	return (true);
}

std::string	ft_getline(std::string prompt)
{
	std::string line;

	line = "";
	while (line.compare("") == 0 && std::cin.eof() == false)
	{
		std::cout << std::endl;
		std::cout << prompt;
		std::getline(std::cin, line);
	}
	return (line);
}

void	add_contact(Phonebook &phone_book)
{
	std::string	line;
	int	i = 0;

	i = phone_book.getContact(i)->getContactNumber() - 1;
	if (i == 8)
		i = 0;
	phone_book.getContact(i)->setFirstName(ft_getline(" Enter First Name: "));
	phone_book.getContact(i)->setLastName(ft_getline(" Enter Last Name: "));
	phone_book.getContact(i)->setNickname(ft_getline(" Enter Nickname: "));
	phone_book.getContact(i)->setPhoneNumber(ft_getline(" Enter Phone Number: "));
	phone_book.getContact(i)->setSecret(ft_getline(" Enter Darkest Secret: "));
	phone_book.getContact(i)->setContactNumber();
	if (std::cin.eof() == false)
		std::cout << std::endl << "Contact added successfully!" << std::endl;
}

void	search_contact(PhoneBook phone_book)
{
	std::string	line;
	int	search_index;
	
	std::cout << std::setw(10) << "\nIndex" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
		phone_book.getContact(i)->displaySearch(0);
	std::cout << std::endl << " Enter contact index for more information, or press enter to return to main menu: ";
	std::getline(std::cin, line);
	if (ft_isnum(line) == true)
	{
		search_index = std::atoi(line.c_str());
		if (search_index > 0 && search_index <= 8)
			phone_book.getContact(search_index - 1)->displaySearch(1);
		else if (std::cin.eof() == false)
			std::cout << "\nInvalid index" << std::endl;
	}
	else if (std::cin.eof() == false || line.compare("") == 0)
		std::cout << "\nInvalid index" << std::endl;
	return ;
}

void	show_menu(Roles role)
{
	if (std::cin.eof() == false && role == init)
	{
		std::cout << std::endl;
		std::cout << "*------------------------------------*\n";
		std::cout << "* Welcome to your awesome phonebook! *\n";
		std::cout << "*------------------------------------*" << std::endl;
	}
	if (std::cin.eof() == false && (role == init || role == menu))
	{
		std::cout << std::endl;
		std::cout << "~~~~~~~~~~\n";
		std::cout << "	Menu:\n";
		std::cout << "	ADD\n";
		std::cout << "	SEARCH\n";
		std::cout << "	EXIT\n";
		std::cout << "~~~~~~~~~~\n" << std::endl;
	}
	if (role == end)
	{
		std::cout << std::endl;
		std::cout << "*----------------------------*\n";
		std::cout << "* contacts cleared, Goodbye! *\n";
		std::cout << "*----------------------------*" << std::endl;
	}
}


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
