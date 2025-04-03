/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:17:31 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 02:10:29 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	std::cout	<< "******************************\n"
				<< "*   Phone Book initialized   *\n"
				<< "******************************"
				<< std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout	<< "******************************\n"
				<< "*   All contacts erased,     *\n"
				<< "*   Phone Book shut down.    *\n"
				<< "******************************"
				<< std::endl;
}

void	PhoneBook::display_menu( void )
{
	std::cout	<< "******************************\n"
				<< "*                            *\n"
				<< "* The All Mighty PhoneBook ! *\n"
				<< "*                            *\n"
				<< "*   ~~~~~~~~~~~~~~~~~~~~~~   *\n"
				<< "*                            *\n"
				<< "*  ADD                       *\n"
				<< "*  SEARCH                    *\n"
				<< "*  EXIT                      *\n"
				<< "*                            *\n"
				<< "******************************"
				<< std::endl;
}

std::string	PhoneBook::get_cmd( PhoneBook &phone_book )
{
	std::string	input;

	input = phone_book.get_input( ">" );
	if (input.compare("ADD") == 0)
		phone_book.add_contact( phone_book );
	else if (input.compare("SEARCH") == 0)
		phone_book.search_contact( phone_book );
	else
		std::cout << "wrong input\ntry ADD/SEARCH/EXIT" << std::endl;
	return (input);
}

std::string	PhoneBook::get_input( std::string prompt )
{
	std::string	input;

	std::cout << prompt << std::flush;
	std::getline(std::cin, input);
	return ( input );
}

Contact	*PhoneBook::get_contact( int index )
{
	return (&Contacts[index]);
}

void	PhoneBook::add_contact( PhoneBook &phone_book )
{
	if (++phone_book.index == 9)
		phone_book.index = 1;
	phone_book.get_contact( phone_book.index )
		->set_FirstName( get_input( "Enter first name: " ) );
	phone_book.get_contact( phone_book.index )
		->set_LastName( get_input( "Enter last name: " ) );
	phone_book.get_contact( phone_book.index )
		->set_Nickname( get_input( "Enter nickname: " ) );
	phone_book.get_contact( phone_book.index )
		->set_PhoneNumber( get_input( "Enter number: " ) );
	phone_book.get_contact( phone_book.index )
		->set_Secret( get_input( "Enter their deepest darkest secret: " ) );
}

void	PhoneBook::search_contact( PhoneBook phone_book )
{
	(void) phone_book;
}
