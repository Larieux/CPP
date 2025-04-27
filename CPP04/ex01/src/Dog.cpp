/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:33:16 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:16:31 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	_type = "Dog";

	std::cout	<< "Oh! it's a big meanie "
				<< _type
				<< std::endl;

	_brain = new Brain();

	return ;
}

Dog::Dog( const Dog &src ) : Animal( src )
{
	_type = src._type;

	std::cout	<< "Oh! it's another big meanie "
				<< _type
				<< "\nIt's a whole pack!"
				<< std::endl;

	_brain = new Brain();

	return ;
}

Dog::~Dog( void )
{
	delete ( _brain );

	std::cout	<< "there's no more "
				<< _type
				<< " in these woods.\n"
				<< "I guess we've killed all the mimics!\n"
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

	if ( this == &src )
		return ( *this );
	Animal::operator=(src);
	if ( _brain != NULL )
		delete _brain;
	_brain = new Brain( *src._brain );
	return ( *this );
}

void	Dog::makeSound( void ) const
{
	std::cout	<< "BARK!! BARK! BARK! BARK!!!\n"
				<< "That's a mimic! let's kill it!"
				<< std::endl;
	return ;
}
