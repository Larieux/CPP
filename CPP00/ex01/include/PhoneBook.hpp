/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:32 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 19:38:58 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
public:
	PhoneBook( void );
	~PhoneBook( void );

	bool		isnum( std::string input )const;
	std::string	get_input( std::string prompt )const;
	std::string	get_cmd( PhoneBook &phone_book );
	void		display_menu( void )const;

private:
	Contact	Contacts[8];
	int		index;

	Contact		*get_contact( int index );
	void		add_contact( PhoneBook &phone_book );
	void		display_all( PhoneBook &phone_book )const;
	void		search_contact( PhoneBook &phone_book )const;

};

#endif
