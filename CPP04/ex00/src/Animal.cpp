/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:18:59 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/18 02:11:50 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void )
{
	_type = "random animal that's probably a cryptid";

	std::cout	<< "There's a "
				<< _type
				<< "in these woods..."
				<< std::endl;

	return ;
}

Animal::Animal( std::string type ) :
	_type( type )
{
	std::cout	<< "There's a "
				<< _type
				<< "in these woods...\n"
				<< "And that's probably a cryptid too, I tell ya!"
				<< std::endl;

	return ;
}

Animal::Animal( const Animal &src )
{
	_type = src._type;

	std::cout	<< "there's another "
				<< _type
				<< "in these woods...\n"
				<< "Fate have mercy upon us... they multiply!"
				<< std::endl;

	return ;
}

Animal::~Animal( void )
{
	std::cout	<< "there's no more "
				<< _type
				<< "in these woods.\n"
				<< "I guess we survived the night!\n"
				<< "...\n let's take some rest, we've earned it."
				<< std::endl;

	return ;
}


Animal &Animal::operator= ( const Animal &src )
{
	std::cout	<< "That "
				<< _type
				<< "is turning into that "
				<< src._type
				<< "!\n"
				<< "It's a shapeshifting monster! "
				<< std::endl;

	_type = src._type;

	return ( *this );
}

void	Animal::makeSound( void )
{
	std::cout	<< "SCRHEEEEEEEKSFHRUGHIR!!!\n...\n...\n"
				<< "yeah that's a cryptid.\n...\n Let's kill it!"
				<< std::endl;
	return ;
}

std::string	Animal::getType( void )
{
	return (_type);
}
