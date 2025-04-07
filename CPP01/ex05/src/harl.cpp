/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:03:43 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/07 16:44:23 by mlarieux         ###   ########.fr       */
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
	std::cout	<< "debug message"
				<< std::endl;
}

void	Harl::info( void )
{
	std::cout	<< "info message"
				<< std::endl;
}

void	Harl::warning( void )
{
	std::cout	<< "warning message"
				<< std::endl;
}

void	Harl::error( void )
{
	std::cout	<< "error message"
				<< std::endl;
}


void	Harl::complain( std::string level )
{
	
}
