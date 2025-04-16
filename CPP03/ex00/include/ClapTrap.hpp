/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:12:48 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/16 22:42:09 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <map>

class ClapTrap
{
public:
	ClapTrap( void );
	ClapTrap( const std::string Name );
	ClapTrap( const ClapTrap &original );
	~ClapTrap( void );

	ClapTrap &operator= ( const ClapTrap &original );

	std::string	getName( void );
	int			getHP( void );
	int			getEP( void );
	int			getAD( void );

	void		setAD( unsigned int amount );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

private:
	std::string	_Name;
	int			_Hit_points;
	int			_Energy_points;
	int			_Attack_Damage;

};

#endif