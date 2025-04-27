/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:51:38 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 19:23:12 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";

	std::cout	<< "Oh! it's a cute "
				<< _type
				<< " ( Cat constructor )"
				<< std::endl;

	_brain = new Brain();

	return ;
}

Cat::Cat( const Cat &src ) : Animal( src )
{
	*this = src;

	std::cout	<< "Oh! It's another cute "
				<< _type
				<< "!\nThey group up in clans, then atack humans!"
				<< " ( Cat copy constructor )"
				<< std::endl;

	return ;
}

Cat::~Cat( void )
{
	delete ( _brain );

	std::cout	<< "there's no more "
				<< _type
				<< " in these woods.\n"
				<< "I guess we've destroyed every clan!"
				<< " ( Cat destructor )\n"
				<< std::endl;

	return ;
}


Cat &Cat::operator= ( const Cat &src )
{
	std::cout	<< "That thing is turning into that "
				<< src._type
				<< "!\n"
				<< "It was indeed a mimic!"
				<< " ( Cat '=' operator )"
				<< std::endl;

	if ( this == &src )
		return ( *this );
	Animal::operator=(src);
	if ( _brain != NULL )
		delete _brain;
	_brain = new Brain( *src._brain );

	return ( *this );
}

std::string	Cat::getBrain( int which ) const
{
	return ( _brain->getIdea( which ) );
}

void	Cat::makeSound( void ) const
{
	std::cout	<< "meow mrrp mreow purrrrrrrrr\n...\n"
				<< "Wait stop! it's okay people, it's a trans girl!\n"
				<< "give her headpats and call her a good girl, "
				<< "she'll think you're the best person in the world "
				<< "and lay devastation upon your enemies.\n"
				<< "she'll never leave you though...\n"
				<< std::endl;
	return ;
}
