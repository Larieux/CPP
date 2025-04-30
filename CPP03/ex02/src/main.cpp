/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/30 14:14:52 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap	bubbline;
	ScavTrap	sbubbline;
	FragTrap	korra( "Korra" );
	ScavTrap	pyco( sbubbline );
	ScavTrap	asami( "Asami" );
	FragTrap	fbubbline;
	FragTrap	copy( korra );
	FragTrap	fasami( "FAsami" );
	FragTrap	pycopy( "pycopy" );

	std::cout << std::endl;

	std::cout 	<< "there's clearly too many of them to count..."
				<< std::endl;

	std::cout << std::endl;

	korra.attack( "copy" );
	copy.takeDamage( korra.getAD() );
	copy.attack( "korra" );
	korra.takeDamage( copy.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	pyco.attack( "korra" );
	korra.takeDamage( pyco.getAD() );

	std::cout << std::endl;

	korra.attack( "pycopy" );
	pycopy.takeDamage( korra.getAD() );
	korra.attack( "pycopy" );
	pycopy.takeDamage( korra.getAD() );
	korra.attack( "fasami" );
	fasami.takeDamage( korra.getAD() );

	std::cout << std::endl;

	pycopy = fasami;
	std::cout << std::endl;

	korra.attack( "pycopy" );
	pycopy.takeDamage( korra.getAD() );
	pyco.attack( "korra" );
	korra.takeDamage( pyco.getAD() );

	std::cout << std::endl;

	korra.beRepaired( 60 );

	std::cout << std::endl;

	sbubbline.guardGate();
	std::cout << std::endl;

	korra.highFivesGuys();
	std::cout << std::endl;

	korra.setAD( 25 );

	korra.attack( "bubbline" );
	bubbline.takeDamage( korra.getAD() );
	korra.attack( "pyco" );
	pyco.takeDamage( korra.getAD() );
	korra.attack( "copy" );
	copy.takeDamage( korra.getAD() );

	std::cout << std::endl;

	sbubbline.setAD( 1 );

	sbubbline.attack( "korra" );
	korra.takeDamage( sbubbline.getAD() );
	sbubbline.attack( "korra" );
	korra.takeDamage( sbubbline.getAD() );
	sbubbline.attack( "korra" );
	korra.takeDamage( sbubbline.getAD() );
	sbubbline.attack( "korra" );
	korra.takeDamage( sbubbline.getAD() );
	sbubbline.attack( "korra" );
	korra.takeDamage( sbubbline.getAD() );
	sbubbline.attack( "korra" );
	korra.takeDamage( sbubbline.getAD() );
	sbubbline.attack( "korra" );
	korra.takeDamage( sbubbline.getAD() );
	sbubbline.attack( "korra" );

	std::cout << std::endl;

	asami.attack( "korra" );
	korra.takeDamage( asami.getAD() );
	asami.attack( "korra" );
	korra.takeDamage( asami.getAD() );
	asami.attack( "korra" );
	korra.takeDamage( asami.getAD() );
	asami.attack( "korra" );
	korra.takeDamage( asami.getAD() );
	asami.attack( "korra" );
	korra.takeDamage( asami.getAD() );

	std::cout << std::endl;

	sbubbline.guardGate();
	korra.highFivesGuys();
	std::cout << std::endl;

	return (0);
}