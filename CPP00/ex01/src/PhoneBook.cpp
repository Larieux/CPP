/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:17:31 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/02 22:19:41 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
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

void	PhoneBook::get_cmd( PhoneBook &phone_book )
{
	std::string	input;

	input = phone_book.get_input();
	if (input.compare("ADD") == 0)
		phone_book.add_contact( phone_book );
	else if (input.compare("SEARCH") == 0)
		phone_book.search_contact( phone_book );
}

std::string	PhoneBook::get_input( void )
{
	std::string	input;
	
	std::cin >> input;
	return ( input );
}

void	PhoneBook::add_contact( PhoneBook &phone_book )
{
	(void) phone_book;
}

void	PhoneBook::search_contact( PhoneBook phone_book )
{
	(void) phone_book;
}

void	PhoneBook::exit_phonebook( void )
{
	
}
