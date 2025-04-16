/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/16 23:37:09 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	bubbline;
	ClapTrap	korra( "Korra" );
	ClapTrap	pyco( bubbline );

	std::cout << std::endl;

	std::cout 	<< "it's getting out of hand!"
				<<" Now there's two of them!"
				<< std::endl;

	std::cout << std::endl;

	ClapTrap	copy( "pyco" );

	std::cout << std::endl;

	bubbline.setAD( 2 );
	korra.setAD( 2 );
	pyco.setAD( 2 );
	copy.setAD( 2 );

	std::cout << std::endl;

	korra.attack( copy.getName() );
	copy.takeDamage( korra.getAD() );
	copy.attack( korra.getName() );
	korra.takeDamage( copy.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( copy.getAD() );
	pyco.attack( korra.getName() );
	korra.takeDamage( pyco.getAD() );

	std::cout << std::endl;

	korra.attack( copy.getName() );
	copy.takeDamage( korra.getAD() );
	korra.attack( copy.getName() );
	copy.takeDamage( korra.getAD() );

	std::cout << std::endl;

	copy = bubbline;
	std::cout << std::endl;

	std::cout << "There's too many of them!" << std::endl;
	std::cout << std::endl;

	korra.attack( copy.getName() );
	copy.takeDamage( korra.getAD() );
	pyco.attack( korra.getName() );
	korra.takeDamage( pyco.getAD() );

	std::cout << std::endl;

	korra.beRepaired( 6 );

	std::cout << std::endl;

	korra.setAD( 6 );

	korra.attack( bubbline.getName() );
	bubbline.takeDamage( korra.getAD() );
	korra.attack( pyco.getName() );
	pyco.takeDamage( korra.getAD() );
	korra.attack( copy.getName() );
	copy.takeDamage( korra.getAD() );

	std::cout << std::endl;

	bubbline.setAD( 0 );

	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );
	bubbline.attack( korra.getName() );
	korra.takeDamage( bubbline.getAD() );

	std::cout << std::endl;

	pyco.attack( korra.getName() );
	korra.takeDamage( copy.getAD() );
	pyco.attack( korra.getName() );
	korra.takeDamage( copy.getAD() );
	pyco.attack( korra.getName() );
	korra.takeDamage( copy.getAD() );
	pyco.attack( korra.getName() );
	korra.takeDamage( copy.getAD() );
	pyco.attack( korra.getName() );
	korra.takeDamage( copy.getAD() );

	return (0);
}