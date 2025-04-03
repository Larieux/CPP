/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:17:31 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 19:46:53 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = -1;
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

std::string	PhoneBook::get_input( std::string prompt )const
{
	std::string	input;

	input = "";
	while (input.compare( "" ) == 0 && std::cin.eof() == false)
	{
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
	}
	
	return ( input );
}

Contact	*PhoneBook::get_contact( int index )
{
	return (&Contacts[index]);
}

bool	PhoneBook::isnum( std::string input )const
{
	std::string::iterator	it;

	for ( it = input.begin(); it != input.end(); it++ )
	{
		if ( *it < '0' || *it > '9' )
			return (false);
	}
	return (true);
}

void	PhoneBook::add_contact( PhoneBook &phone_book )
{
	if (++phone_book.index == 8)
		phone_book.index = 0;
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
	phone_book.get_contact( phone_book.index )->is_set = true;
}

void	PhoneBook::display_all( PhoneBook &phone_book )const
{
	int	i;

	i = 0;
	std::cout	<< "[" << 0 << "]|menu" << std::endl;
	while ( i < 8 && phone_book.get_contact(i)->is_set == true )
	{
		std::cout	<< "[" << i + 1 << "]"
					<< phone_book.get_contact(i)
					->display_search( *(phone_book.get_contact(i)) )
					<< std::endl;
		i++;
	}
	
}

void	PhoneBook::search_contact( PhoneBook &phone_book )const
{
	std::string	input;
	int			index;

	if (phone_book.get_contact(0)->is_set == false)
	{
		std::cout	<< "no contacts set." << std::endl;
		return ;
	}
	phone_book.display_all( phone_book );
	input = phone_book.get_input( ">" );
	index = std::atoi( input.c_str() );
	if ( phone_book.isnum( input ) == false || !(index >= 0 && index < 9)
			|| (index != 0 && phone_book.get_contact( index - 1 )->is_set == false))
	{
		std::cout	<< "Please write a number between '1'"
					<< " and [number of set contacts]\n"
					<< "or '0' to return to main menu"
					<< std::endl;
		phone_book.search_contact( phone_book );
	}
	else if ( index > 0 && index < 9
		&& phone_book.get_contact( index - 1 )->is_set == true )
	{
		phone_book.get_contact( index - 1 )
			->display_contact( *(phone_book.get_contact( index - 1 )) );
	}
	else if ( index == 0 )
		return ;
}

std::string	PhoneBook::get_cmd( PhoneBook &phone_book )
{
	std::string	input;

	input = phone_book.get_input( ">" );
	if (input.compare("ADD") == 0)
		phone_book.add_contact( phone_book );
	else if (input.compare("SEARCH") == 0)
		phone_book.search_contact( phone_book );
	else if (input.compare("EXIT") != 0)
		std::cout << "wrong input\ntry ADD/SEARCH/EXIT" << std::endl;
	return (input);
}

void	PhoneBook::display_menu( void )const
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
