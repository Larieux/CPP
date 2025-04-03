/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:23:13 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 01:52:47 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
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
