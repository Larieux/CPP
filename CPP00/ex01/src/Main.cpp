/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:19:54 by mlarieux          #+#    #+#             */
/*   Updated: 2025/02/18 14:34:40 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <iomanip>	// std::setw
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	line;

	phone_book.show_menu(0);
	while (std::cin.eof() == false)
	{
		std::getline(std::cin, line);
		if (line.compare("EXIT") == 0)
			break ;
		else if (line.compare("ADD") == 0)
			phone_book.add_contact(phone_book);
		else if (line.compare("SEARCH") == 0)
			phone_book.search_contact(phone_book);
		else if (std::cin.eof() == false)
			std::cout << "\nInvalid input, try:"
				<< "\nADD/SEARCH/EXIT\n" << std::endl;
		phone_book.show_menu(1);
	}
	phone_book.show_menu(2);
	return (0);
}
