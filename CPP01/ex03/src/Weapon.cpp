/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:08:37 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/20 14:37:52 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string &type ) :
		_type(type)
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

std::string	&Weapon::getType( void )
{
	return (_type);
}

void	Weapon::setType( std::string &type )
{
	_type = type;
}
