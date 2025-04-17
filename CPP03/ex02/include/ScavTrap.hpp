/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:08:25 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/17 02:51:50 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>
#include <map>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( const std::string Name );
	ScavTrap( const ScavTrap &original );
	~ScavTrap( void );

	ScavTrap &operator= ( const ScavTrap &original );

	void	attack( ClapTrap &target );
	void	guardGate( void );

private:

};

#endif