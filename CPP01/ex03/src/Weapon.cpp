/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:08:37 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/14 13:35:17 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) :
		_type(type)
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}

std::string	&Weapon::getType( void )
{
	std::string	&type = this->_type;

	return (type);
}
