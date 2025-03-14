/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:56:04 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/14 16:26:44 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string _name ) :
		
{
	return;
}

HumanB::~HumanB( void )
{
	return;
}

void	HumanB::set_weapon ( Weapon _weapon )
{
	Weapon	weapon;

	weapon = new Weapon( _weapon );
}

void	HumanB::attack ( void )
{
	std::cout	<< this->name
				<< " attacks with their "
				<< this->weapon.getType()
				<< std::endl;
}