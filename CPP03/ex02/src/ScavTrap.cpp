/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:12:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/30 14:11:38 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	setName( "SBubbline" );
	setHP( 100 );
	setEP( 50 );
	setAD( 20 );

	std::cout	<< "ScavTrap default constructor called!\n"
				<< getName()
				<< " now exists!"
				<< std::endl;
	return ;
}

ScavTrap::ScavTrap( const std::string Name ) : ClapTrap ( Name )
{
	setName( Name );
	setHP( 100 );
	setEP( 50 );
	setAD( 20 );

	std::cout	<< "ScavTrap constructor called!\n"
				<< getName()
				<< " now exists!"
				<< std::endl;
	return ;
}

ScavTrap::ScavTrap( const ScavTrap &original ) : ClapTrap( original )
{
	std::cout	<< "ScavTrap copy constructor called!\n"
				<< "a copy of "
				<< getName()
				<< " now exists!"
				<< std::endl;
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout	<< "ScavTrap destructor called!\n"
				<< getName()
				<< " no longer exist!"
				<< std::endl;
	return ;
}


ScavTrap	&ScavTrap::operator= ( const ScavTrap &original )
{
	std::cout	<< "ScavTrap Assignment operator called for "
				<< getName()
				<< "!"
				<< std::endl;

	if ( this != &original )
		ClapTrap::operator=( original );

	return ( *this );
}

void	ScavTrap::attack( const std::string &target )
{
	if ( getEP() <= 0 || getHP() <= 0 )
		setAD( 0 );
	if ( getHP() <= 0 )
	{
		std::cout	<< getName()
					<< " is already dead! "
					<< " they can't attack! "
					<< std::endl;
	}
	else if ( getEP() <= 0 )
	{
		std::cout	<< getName()
					<< " is too exhausted! "
					<< " they can't attack! "
					<< std::endl;
	}
	else
	{
		std::cout	<< "ScavTrap "
					<< getName()
					<< " attacks "
					<< target
					<< ", dealing "
					<< getAD()
					<< " points of damage!"
					<< std::endl;
		setEP( getEP() - 10 );
	}
	return ;
}

void	ScavTrap::guardGate( void )
{
	if ( getHP() <= 0 )
	{
		std::cout	<< getName()
					<< " is already dead! "
					<< " they can't guard the gate! "
					<< std::endl;
	}
	else
	{
		std::cout	<< "ScavTrap "
					<< getName()
					<< " is now in gate keeper mode."
					<< std::endl;
	}
}
