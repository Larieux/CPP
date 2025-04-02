/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:17:31 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/02 16:20:08 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::cout	<< "Phone Book initialized"
				<< std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout	<< "All contacts erased,"
				<< "Phone Book shut down."
				<< std::endl;
}
