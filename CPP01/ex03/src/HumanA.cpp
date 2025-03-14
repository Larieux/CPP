/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:52:56 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/14 13:38:22 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon _weapon )
{
	this->name = _name;
	this->weapon.set_type( _weapon.getType() );
}

HumanA::~HumanA( void )
{
}

void	HumanA::attack ( void )
{
	std::cout	<< this->name
				<< " attacks with their "
				<< this->weapon.getType();
}