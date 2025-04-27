/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:51:38 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:17:00 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";

	std::cout	<< "Oh! it's a cute "
				<< _type
				<< std::endl;

	_brain = new Brain();

	return ;
}

Cat::Cat( const Cat &src ) : Animal( src )
{
	_type = src._type;

	std::cout	<< "Oh! It's another cute "
				<< _type
				<< "they group up in clans, then atack humans!"
				<< std::endl;

	_brain = new Brain();

	return ;
}

Cat::~Cat( void )
{
	delete ( _brain );

	std::cout	<< "there's no more "
				<< _type
				<< " in these woods.\n"
				<< "I guess we've destroyed every clan!\n"
				<< std::endl;

	return ;
}


Cat &Cat::operator= ( const Cat &src )
{
	std::cout	<< "That "
				<< _type
				<< " is turning into that "
				<< src._type
				<< "!\n"
				<< " the "
				<< _type
				<< " was indeed a mimic!"
				<< std::endl;

	if ( this == &src )
		return ( *this );
	Animal::operator=(src);
	if ( _brain != NULL )
		delete _brain;
	_brain = new Brain( *src._brain );

	return ( *this );
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
