/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:32 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 01:45:40 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>

class PhoneBook
{
private:
	Contact	Contacts[8];
	int		index;

	Contact	*get_contact( int index );
	void	add_contact( PhoneBook &phone_book );
	void	search_contact( PhoneBook phone_book );

public:
	PhoneBook( void );
	~PhoneBook( void );

	void		display_menu( void );
	std::string	get_cmd ( PhoneBook &phone_book );
	std::string	get_input( std::string prompt );

};

#endif
