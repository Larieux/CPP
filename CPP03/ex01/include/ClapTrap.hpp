/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:12:48 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/29 20:16:22 by mlarieux         ###   ########.fr       */
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

	void		setName( std::string Name );
	void		setHP( unsigned int amount );
	void		setEP( unsigned int amount );
	void		setAD( unsigned int amount );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

protected:
	std::string	_Name;
	int			_Hit_points;
	int			_Energy_points;
	int			_Attack_Damage;

private:

};

#endif