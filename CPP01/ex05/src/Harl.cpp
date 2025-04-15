/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:03:43 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/08 21:14:37 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout	<< DEBUG_MSG
				<< std::endl;
}

void	Harl::info( void )
{
	std::cout	<< INFO_MSG
				<< std::endl;
}

void	Harl::warning( void )
{
	std::cout	<< WARNING_MSG
				<< std::endl;
}

void	Harl::error( void )
{
	std::cout	<< ERROR_MSG
				<< std::endl;
}

void	Harl::other( void )
{
	std::cout	<< OTHER_MSG
				<< std::endl;
}


void	Harl::complain( std::string level )
{
	static void	(Harl::*fptr[LEVEL_NB]) () =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::other
	};

	std::string	levels[LEVEL_NB] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"OTHER"
	};

	int	i = 0;
	while ( i < LEVEL_NB && level.compare( levels[i] ) != 0 )
		i++;
	if (i == LEVEL_NB)
		i--;

	(this->*fptr[i])();
}
