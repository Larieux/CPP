/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:33:16 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:23:40 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	_type = "Dog";

	std::cout	<< "It's a big meanie "
				<< _type
				<< "!"
				<< std::endl;

	return ;
}

Dog::Dog( const Dog &src ) : Animal( src )
{
	_type = src._type;

	std::cout	<< "It's another big meanie "
				<< _type
				<< "!1\nIt's a whole pack!"
				<< std::endl;

	return ;
}

Dog::~Dog( void )
{
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
