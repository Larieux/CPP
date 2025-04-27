/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 18:51:38 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:22:47 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal()
{
	_type = "Cat";

	std::cout	<< "It's a cute "
				<< _type
				<< "!"
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
