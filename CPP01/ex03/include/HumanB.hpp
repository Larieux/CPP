/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:07:43 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/20 14:42:07 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private :

	std::string &_name;
	Weapon *_weapon;

public :

	HumanB( const std::string &name );
	HumanB( const std::string &name );
	~HumanB( void );

	void	setWeapon ( Weapon &weapon );
	void	attack ( void );

};

#endif
