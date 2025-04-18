/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:51:16 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/18 01:57:08 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	_type = "random wronganimal that's a hundred percent just an animal";

	std::cout	<< "There's a "
				<< _type
				<< "in these woods."
				<< std::endl;

	return ;
}

WrongAnimal::WrongAnimal( std::string type ) :
	_type( type )
{
	std::cout	<< "There's a "
				<< _type
				<< "in these woods...\n"
				<< "And that's just an animal, I tell ya!"
				<< std::endl;

	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal &src )
{
	_type = src._type;

	std::cout	<< "there's another "
				<< _type
				<< "in these woods...\n"
				<< "Let's just continue onward, we're completely safe!"
				<< std::endl;

	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout	<< "there's no more "
				<< _type
				<< "in these woods.\n"
				<< "Darn it! the cryptids must have eaten 'em all!\n"
				<< "let's just go back home."
				<< std::endl;

	return ;
}


WrongAnimal &WrongAnimal::operator= ( const WrongAnimal &src )
{
	std::cout	<< "That "
				<< _type
				<< "is turning into that "
				<< src._type
				<< ".\n"
				<< "nothing to see here."
				<< std::endl;

	_type = src._type;

	return ( *this );
}

void	WrongAnimal::makeSound( void )
{
	std::cout	<< "Yiip!\n...\n...\n"
				<< "See? that's just a fox! Told ya they were just random animals!"
				<< std::endl;
	return ;
}
