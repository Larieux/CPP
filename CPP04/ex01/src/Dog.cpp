/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:33:16 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/25 16:51:23 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	_type = "Dog";

	std::cout	<< "There's a "
				<< _type
				<< " in these woods..."
				<< std::endl;

	return ;
}

Dog::Dog( const std::string type ) : Animal( type )
{
	_type = type;

	std::cout	<< "There's a "
				<< _type
				<< " in these woods...\n"
				<< "And that's probably a mimic too, I tell ya!"
				<< std::endl;

	return ;
}

Dog::Dog( const Dog &src ) : Animal( src )
{
	_type = src._type;

	std::cout	<< "there's another "
				<< _type
				<< " in these woods...\n"
				<< "It's a whole pack!"
				<< std::endl;

	return ;
}

Dog::~Dog( void )
{
	std::cout	<< "there's no more "
				<< _type
				<< " in these woods.\n"
				<< "I guess we've killed all the mimics!\n"
				<< "...\n let's take some rest, we've earned it.\n"
				<< std::endl;

	return ;
}

Dog &Dog::operator= ( const Dog &src )
{
	std::cout	<< "That "
				<< _type
				<< " is turning into that "
				<< src._type
				<< "!\n"
				<< " the "
				<< _type
				<< " was actually a mimic!"
				<< std::endl;

	_type = src._type;

	return ( *this );
}

void	Dog::makeSound( void ) const
{
	std::cout	<< "BARK!! BARK! BARK! BARK!!!\n"
				<< "That's a mimic! let's kill it!"
				<< std::endl;
	return ;
}
