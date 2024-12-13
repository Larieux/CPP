/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:58:07 by mlarieux          #+#    #+#             */
/*   Updated: 2024/12/13 13:51:01 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

void	PhoneBook::addContact()
{
	std::string	str;

	std::cout << "please write contact's first name\n";
	std::getline(std::cin, str);
	std::cout << str << std::endl;
}