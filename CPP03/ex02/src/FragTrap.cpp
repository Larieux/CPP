/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:12:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/17 04:07:28 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	setName( "FBubbline" );
	setHP( 100 );
	setEP( 100 );
	setAD( 30 );

	std::cout	<< "FragTrap default constructor called!\n"
				<< getName()
				<< " now exists!"
				<< std::endl;
	return ;
}

FragTrap::FragTrap( const std::string Name ) : ClapTrap ( Name )
{
	setName( Name );
	setHP( 100 );
	setEP( 100 );
	setAD( 30 );

	std::cout	<< "FragTrap constructor called!\n"
				<< getName()
				<< " now exists!"
				<< std::endl;
	return ;
}

FragTrap::FragTrap( const FragTrap &original ) : ClapTrap( original )
{
	std::cout	<< "FragTrap copy constructor called!\n"
				<< "a copy of "
				<< getName()
				<< " now exists!"
				<< std::endl;
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout	<< "FragTrap destructor called!\n"
				<< getName()
				<< " no longer exist!"
				<< std::endl;
	return ;
}


FragTrap	&FragTrap::operator= ( const FragTrap &original )
{
	std::cout	<< "FragTrap Assignment operator called for "
				<< getName()
				<< "!"
				<< std::endl;

	std::cout << getName() << std::endl;
	if ( this != &original )
		ClapTrap::operator=( original );

	return ( *this );
}

void	FragTrap::attack( ClapTrap &target )
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
		std::cout	<< "FragTrap "
					<< getName()
					<< " attacks "
					<< target.getName()
					<< ", dealing "
					<< getAD()
					<< " points of damage!"
					<< std::endl;
		setEP( getEP() - 10 );
	}
	return ;
}

void	FragTrap::highFivesGuys( void )
{
	if ( getHP() <= 0 )
	{
		std::cout	<< getName()
					<< " is already dead! "
					<< " they can't boost the party's morale! "
					<< std::endl;
	}
	else
	{
		std::cout	<< "FragTrap "
					<< getName()
					<< " sings a song that boosts the party's morale!"
					<< std::endl;
	}
}
