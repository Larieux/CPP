/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:23:13 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 19:39:32 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact():
	FirstName(""), LastName(""), Nickname(""), PhoneNumber(""), Secret("")
{
	is_set = false;
}

Contact::~Contact()
{
}

std::string	Contact::truncate_display( std::string display )
{
	if ( display.size() > 10 )
		return (display.substr(0, 9) + '.');
	while (display.size() < 10)
		display.append( " " );
	return (display);
}

void	Contact::set_FirstName( std::string input )
{
	FirstName = input;
}

void	Contact::set_LastName( std::string input )
{
	LastName = input;
}

void	Contact::set_Nickname( std::string input )
{
	Nickname = input;
}

void	Contact::set_PhoneNumber( std::string input )
{
	PhoneNumber = input;
}

void	Contact::set_Secret( std::string input )
{
	Secret = input;
}

void	Contact::display_contact( Contact contact )const
{
	std::cout	<< "First Name : " << contact.FirstName << "\n"
				<< "Last Name : " << contact.LastName << "\n"
				<< "Nickame : " << contact.Nickname << "\n"
				<< "Number : " << contact.PhoneNumber << "\n"
				<< "deepest darkest secret :\n"
				<< contact.Secret
				<< std::endl;
}

std::string	Contact::display_search( Contact contact )const
{
	return ( "|" + contact.truncate_display( contact.FirstName )
				+ "|" + contact.truncate_display( contact.LastName )
				+ "|" + contact.truncate_display( contact.Nickname ) );
}
