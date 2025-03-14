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

	Weapon weapon;
	std::string name;

public :

	HumanB( std::string _name );
	~HumanB( void );

	void	set_weapon ( Weapon _weapon );
	void	attack ( void );

};

#endif