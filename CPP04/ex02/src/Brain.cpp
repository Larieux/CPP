/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:04:43 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/29 17:24:46 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	for ( int i = 0; i < NUM_IDEAS; i++ )
		_ideas[i] = "food";
	std::cout	<< "It has one brain cell!"
				<< "( Brain constructor )"
				<< std::endl;

	return ;
}

Brain::Brain( const Brain &src )
{
	*this = src;
	std::cout	<< "It has a clone of a brain cell!"
				<< "( Brain copy constructor )"
				<< std::endl;

	return ;
}

Brain::~Brain( void )
{
	std::cout	<< "wooops! I stole the brain cell!"
				<< "( Brain destructor )"
				<< std::endl;

	return ;
}


Brain &Brain::operator= ( const Brain &src )
{
	std::cout	<< "Awww it gave the brain cell!"
				<< "( Brain '=' operator )"
				<< std::endl;

	if (this == &src)
		return ( *this );
	for ( int i = 0; i < NUM_IDEAS; i++ )
		_ideas[i] = src.getIdea(i);
	return ( *this );
}

const std::string	Brain::getIdea( int which ) const
{
	return ( _ideas[which] );
}
