/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:14:23 by mlarieux          #+#    #+#             */
/*   Updated: 2025/01/23 13:35:16 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Phonebook::Phonebook(void)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

Contact	*Phonebook::getContact(int index)
{
	return (&m_contacts[index]);
}
