/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:01:09 by mlarieux         ###   ########.fr       */
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

	return (0);
}