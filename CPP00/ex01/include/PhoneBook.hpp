/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:38 by mlarieux          #+#    #+#             */
/*   Updated: 2025/01/23 13:57:53 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include "Menu.hpp"

class PhoneBook {

private:

	Contact	my_contact[8];

public:

	PhoneBook( void );
	~PhoneBook( void );

	Contact		*getContact(int index) const;	

};

#endif
