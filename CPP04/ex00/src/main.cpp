/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:26:02 by mlarieux         ###   ########.fr       */
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
	const Animal	*sec_cryptid = new Animal( *cryptid );

	std::cout << cryptid->getType() << " " << std::endl;
	std::cout << sec_cryptid->getType() << " " << std::endl;

	cryptid->makeSound();
	sec_cryptid->makeSound();

	delete sec_cryptid;
	delete cryptid;

	std::cout << "\n***test dog***\n\n" << std::endl;

	const Animal	*dog = new Dog();

	std::cout << dog->getType() << " " << std::endl;

	dog->makeSound();

	delete dog;

	std::cout << "\n***test cat***\n\n" << std::endl;

	const Animal	*cat = new Cat();

	std::cout << cat->getType() << " " << std::endl;

	cat->makeSound();

	delete cat;


	std::cout << "\n***test wrong animal and worngcat***\n\n" << std::endl;

	const WrongAnimal	*wrong_animal = new WrongAnimal();
	const WrongAnimal	*wrong_cat = new WrongCat();

	std::cout << wrong_animal->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;

	wrong_animal->makeSound();
	wrong_cat->makeSound();

	delete wrong_cat;
	delete wrong_animal;

	return (0);
}