
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:56:04 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/17 14:17:51 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( const std::string name ) :
		_name(name)
{
	return ;
}

HumanB::~HumanB( void )
{
	return;
}

void	HumanB::setWeapon ( Weapon weapon )
{
	_weapon = weapon;
}

void	HumanB::attack ( void )
{
	std::cout	<< _name
				<< " attacks with their "
				<< _weapon.getType()
				<< std::endl;
}
