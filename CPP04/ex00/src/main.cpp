/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/25 17:02:18 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
	std::cout << "\n***subject main***\n\n" << std::endl;

	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;

	std::cout << "\n***test animal***\n\n" << std::endl;

	const Animal	*cryptid = new Animal();
	const Animal	*thunderbird = new Animal( "thunderird" );
	const Animal	*sec_thunderbird = new Animal( *thunderbird );

	std::cout << cryptid->getType() << " " << std::endl;
	std::cout << thunderbird->getType() << " " << std::endl;
	std::cout << sec_thunderbird->getType() << " " << std::endl;

	cryptid->makeSound();
	thunderbird->makeSound();
	sec_thunderbird->makeSound();

	delete cryptid;
	delete sec_thunderbird;
	delete thunderbird;

	std::cout << "\n***test dog***\n\n" << std::endl;

	const Animal	*dog = new Dog();
	const Animal	*hellhound = new Dog( "hellhound" );

	std::cout << dog->getType() << " " << std::endl;
	std::cout << hellhound->getType() << " " << std::endl;

	dog->makeSound();
	hellhound->makeSound();

	delete dog;
	delete hellhound;

	std::cout << "\n***test wrong animal and worngcat***\n\n" << std::endl;

	const WrongAnimal	*wrong_animal = new WrongAnimal();
	const WrongAnimal	*wrong_cat = new WrongCat( "unfamiliar" );

	std::cout << wrong_animal->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;

	wrong_animal->makeSound();
	wrong_cat->makeSound();

	delete wrong_cat;
	delete wrong_animal;

	return (0);
}