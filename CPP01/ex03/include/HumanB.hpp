/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:07:43 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/14 13:28:17 by mlarieux         ###   ########.fr       */
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

	Weapon _weapon;
	std::string _name;

public :

	HumanB( std::string name );
	~HumanB( void );

	void	setWeapon ( Weapon weapon );
	void	attack ( void );

};

#endif
