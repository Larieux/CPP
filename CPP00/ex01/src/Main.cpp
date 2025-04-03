/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:13:08 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 01:54:57 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main( void )
{
	PhoneBook	my_phonebook;

	my_phonebook.display_menu();
	while (my_phonebook.get_cmd( my_phonebook ).compare( "EXIT" ) != 0)
		my_phonebook.display_menu();
}