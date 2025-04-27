/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:18:59 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 19:25:08 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	_type = "random animal that's probably a cryptid";

	std::cout	<< "There's a "
				<< _type
				<< " in these woods..."
				<< " ( Animal constructor )"
				<< std::endl;

	return ;
}

Animal::Animal( const Animal &src )
{
	*this = src;

	std::cout	<< "there's another "
				<< _type
				<< " in these woods...\n"
				<< "Fate have mercy upon us... they multiply!"
				<< " ( Animal copy constructor )"
				<< std::endl;

	return ;
}

Animal::~Animal( void )
{
	std::cout	<< "...let's take some rest, we've earned it."
				<< "( Animal destructor )\n"
				<< std::endl;

	return ;
}


Animal &Animal::operator= ( const Animal &src )
{
	std::cout	<< "That "
				<< _type
				<< " is turning into that "
				<< src._type
				<< "!\n"
				<< "It's a shapeshifting monster!"
				<< " ( Animal '=' operator )"
				<< std::endl;

	if (this == &src)
		return (*this);
	_type = src._type;

	return ( *this );
}

std::string	Animal::getType( void ) const
{
	return (_type);
}

std::string	Animal::getBrain( int which ) const
{
	(void)which;

	return ( NULL );
}

void	Animal::makeSound( void ) const
{
	std::cout	<< "SCRHEEEEEEEKSFHRUGHIR!!!\n...\n...\n"
				<< "yeah that's a cryptid.\n...\n Let's kill it!\n"
				<< std::endl;
	return ;
}
