/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/30 14:12:42 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	bubbline;
	ScavTrap	sbubbline;
	ScavTrap	korra( "Korra" );
	ScavTrap	pyco( korra );
	ScavTrap	asami( "Asami" );

	std::cout << std::endl;

	std::cout 	<< "it's getting out of hand!"
				<<" Now there's two of them!"
				<< std::endl;

	std::cout << std::endl;

	ScavTrap	copy( "pyco" );

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

	korra.attack( "copy" );
	copy.takeDamage( korra.getAD() );
	korra.attack( "copy" );
	copy.takeDamage( korra.getAD() );

	std::cout << std::endl;

	copy = pyco;
	std::cout << std::endl;

	std::cout << "There's too many of them!" << std::endl;
	std::cout << std::endl;

	korra.attack( "copy" );
	copy.takeDamage( korra.getAD() );
	pyco.attack( "korra" );
	korra.takeDamage( pyco.getAD() );

	std::cout << std::endl;

	korra.beRepaired( 30 );

	std::cout << std::endl;

	korra.guardGate();
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

	korra.guardGate();
	std::cout << std::endl;

	return (0);
}