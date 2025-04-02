/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:32 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/02 16:23:21 by mlarieux         ###   ########.fr       */
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

	void	add();
	void	search();
	void	exit();

public:
	PhoneBook();
	~PhoneBook(); 
};

#endif
