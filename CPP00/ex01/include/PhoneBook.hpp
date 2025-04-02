/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:32 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/02 22:22:51 by mlarieux         ###   ########.fr       */
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
public:
	PhoneBook( void );
	~PhoneBook( void );

	void		display_menu( void );
	void		get_cmd ( PhoneBook &phone_book );
	std::string	get_input( void );

private:
	Contact	Contacts[8];

	void	add_contact( PhoneBook &phone_book );
	void	search_contact( PhoneBook phone_book );
	void	exit_phonebook( void );

};

#endif
