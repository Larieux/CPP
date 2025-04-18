/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:25:12 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/18 02:17:10 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	const Animal*	cryptid = new Animal();
	const Animal*	thunderbird = new Animal( "thunderird" );
	const Animal*	sec_thunderbird = new Animal( thunderbird );
	const Animal*	sec_cryptid = new Animal();

	const Animal*	Dog = new Dog();
	const Animal*	hellhound = new Dog( "hellhound" );
	const Animal*	sec_hellhound = new Dog( hellhound );
	const Animal*	sec_dog = new Dog();

	const Animal*	cat = new ;
	const Animal*	familiar( "familiar" ) = new ;
	const Animal*	sec_familiar( familiar ) = new ;
	const Animal*	sec_cat = new ;


}