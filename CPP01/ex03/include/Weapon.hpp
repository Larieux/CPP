/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:47:16 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/15 22:34:44 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private :

	std::string _type;

public :

	Weapon( void );
	Weapon( const std::string &type );
	~Weapon( void );

	void		setType( const std::string &type );
	std::string	&getType( void );

};

#endif
