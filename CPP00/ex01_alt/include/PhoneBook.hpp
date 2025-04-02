/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:38 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/02 14:33:58 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>	// std::atoi
#include "Contact.hpp"

class PhoneBook {

private:

	Contact	my_contact[8];
	Contact		*getContact(int index);
	bool		ft_isnum(std::string line);
	std::string	ft_getline(std::string prompt);

public:

	PhoneBook( void );
	~PhoneBook( void );

	void		add_contact(PhoneBook &phone_book);
	void		search_contact(PhoneBook phone_book);
	void		show_menu(int role);

};

#endif
