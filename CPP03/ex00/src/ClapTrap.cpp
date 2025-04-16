/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 21:12:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/16 23:25:23 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) :
	_Name( "Bubbline" ), _Hit_points( 10 )
	, _Energy_points( 10 ), _Attack_Damage( 0 )
{
	std::cout	<< "ClapTrap default constructor called!\n"
				<< _Name
				<< " now exists!"
				<< std::endl;
	return ;
}

ClapTrap::ClapTrap( const std::string Name ) :
	_Name( Name ), _Hit_points( 10 )
	, _Energy_points( 10 ), _Attack_Damage( 0 )
{
	std::cout	<< "ClapTrap constructor called!\n"
				<< _Name
				<< " now exists!"
				<< std::endl;
	return ;
}

ClapTrap::ClapTrap( const ClapTrap &original )
{
	_Name = original._Name + "copy";
	_Hit_points = original._Hit_points;
	_Energy_points = original._Energy_points;
	_Attack_Damage = original._Attack_Damage;

	std::cout	<< "ClapTrap copy constructor called!\n"
				<< "a copy of "
				<< original._Name
				<< " now exists!\n"
				<< "let's call them "
				<< _Name
				<< "."
				<< std::endl;
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout	<< "ClapTrap destructor called!\n"
				<< _Name
				<< " no longer exist!"
				<< std::endl;
	return ;
}


ClapTrap	&ClapTrap::operator= ( const ClapTrap &original )
{
	std::cout	<< "Assignment operator called!\n"
				<< _Name
				<< " has now become "
				<< original._Name
				<< "'s perfect copy!"
				<< std::endl;

	_Name = original._Name + "pyco";
	_Hit_points = original._Hit_points;
	_Energy_points = original._Energy_points;
	_Attack_Damage = original._Attack_Damage;

	std::cout	<< "let's call them "
				<< _Name
				<< "."
				<< std::endl;

	return ( *this );
}

std::string	ClapTrap::getName( void )
{
	return ( _Name );
}

int			ClapTrap::getHP( void )
{
	return ( _Hit_points );
}

int			ClapTrap::getEP( void )
{
	return ( _Energy_points );
}

int			ClapTrap::getAD( void )
{
	return ( _Attack_Damage );
}

void		ClapTrap::setAD( unsigned int amount )
{
	_Attack_Damage = amount;
	std::cout	<< _Name
				<< "'s attack damage changes!\n"
				<< "they now deal "
				<< _Attack_Damage
				<< " damage points!"
				<< std::endl;
	return ;
}

void	ClapTrap::attack( const std::string& target )
{
	if ( _Hit_points <= 0 )
	{
		std::cout	<< _Name
					<< " is already dead! "
					<< " they can't attack! "
					<< std::endl;
	}
	else if ( _Energy_points <= 0 )
	{
		std::cout	<< _Name
					<< " is too exhausted! "
					<< " they can't attack! "
					<< std::endl;
	}
	else
	{
		std::cout	<< "ClapTrap "
					<< _Name
					<< " attacks "
					<< target
					<< ", dealing "
					<< _Attack_Damage
					<< " points of damage!"
					<< std::endl;
		_Energy_points--;
	}
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if ( _Hit_points == 0 )
	{
		std::cout	<< "Stop! "
					<< _Name
					<< " is already dead! "
					<< std::endl;
	}
	else
	{
		std::cout	<< "ClapTrap "
					<< _Name
					<< " takes "
					<< amount
					<< " points of damage!"
					<< std::endl;

		_Hit_points -= amount;

		std::cout	<< "ClapTrap "
					<< _Name
					<< " is now at "
					<< _Hit_points
					<< " HP!"
					<< std::endl;

		if (_Hit_points <= 0)
		{
			std::cout	<< "ClapTrap "
						<< _Name
						<< " died...\n"
						<< "the rest of the party watches in grief.\n"
						<< "\n"
						<< "You'll prepare a new character sheet for next time, Caroline."
						<< "\n"
						<< std::endl;
		}
	}
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if ( _Energy_points <= 0 )
	{
		std::cout	<< _Name
					<< " is too exhausted! "
					<< " they can't regenerate! "
					<< std::endl;
	}
	else
	{
		_Hit_points += amount;
		std::cout	<< "ClapTrap "
					<< _Name
					<< " regenerates "
					<< amount
					<< " HP, and is now at "
					<< _Hit_points
					<< " HP!"
					<< std::endl;
		_Energy_points--;
	}
	return ;
}
