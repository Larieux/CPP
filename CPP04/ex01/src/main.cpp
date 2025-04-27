/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 19:05:02 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	std::cout << "\n***test animal***\n\n" << std::endl;

	const Animal	*cryptid = new Animal();

	std::cout << cryptid->getType() << " " << std::endl;

	cryptid->makeSound();

	delete cryptid;

	std::cout << "\n***test animal array***\n\n" << std::endl;

	Animal *animals[NUM_AN];

	for ( int i  = 0; i < NUM_AN; i++)
	{
		if ( i < NUM_AN / 2 )
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	for (int an = 0; an < NUM_AN; an++)
	{
		for ( int id = 0; id < NUM_IDEAS; id++ )
			std::cout << animals[an]->getBrain( id );
	}

	Cat copy;
	{
		Cat paste = copy;
	}

	return (0);
}