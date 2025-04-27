/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:51:38 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/25 16:51:12 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";

	std::cout	<< "There's a "
				<< _type
				<< " in these woods..."
				<< std::endl;

	return ;
}

Cat::Cat( const std::string type ) : Animal( type )
{
	_type = type;

	std::cout	<< "There's a "
				<< _type
				<< " in these woods...\n"
				<< "And that's either a mimic or a devil's familiar, I tell ya!"
				<< std::endl;

	return ;
}

Cat::Cat( const Cat &src ) : Animal( src )
{
	_type = src._type;

	std::cout	<< "there's another "
				<< _type
				<< " in these woods...\n"
				<< "they group up in clans, then atack humans!"
				<< std::endl;

	return ;
}

Cat::~Cat( void )
{
	std::cout	<< "there's no more "
				<< _type
				<< " in these woods.\n"
				<< "I guess we've destroyed every clan!\n"
				<< "...\n let's take some rest, we've earned it.\n"
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

	_type = src._type;

	return ( *this );
}

void	Cat::makeSound( void ) const
{
	std::cout	<< "meow mrrp mreow prrrrrrrrr\n...\n"
				<< "Wait stop! it's okay people, it's a trans girl!\n"
				<< "give her headpats and call her a good girl, "
				<< "she'll think you're the best person in the world "
				<< "and lay devastation upon your enemies.\n"
				<< "she'll never leave you though...\n"
				<< std::endl;
	return ;
}
