/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:57:10 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/14 13:36:58 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private :

	Weapon weapon;
	std::string name;

public :

	HumanA( std::string _name, Weapon _weapon );
	~HumanA( void );

	void	attack ( void );

};

#endif