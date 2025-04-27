/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:04:43 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:00:15 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	for ( int i = 0; i < NUM_IDEAS; i++ )
		_ideas[i] = "food";
	std::cout	<< "It has one brain cell!"
				<< std::endl;
}

Brain::Brain( const Brain &src )
{
	if (this == &src)
		return ;
	for ( int i = 0; i < NUM_IDEAS; i++ )
		_ideas[i] = src._ideas[i];
	std::cout	<< "It has a clone of a brain cell!"
				<< std::endl;
}

Brain::~Brain( void )
{
	std::cout	<< "wooops! I stole the brain cell!"
				<< std::endl;
}


Brain &Brain::operator= ( const Brain &src )
{
	std::cout	<< "Awww it gave the brain cell!"
				<< std::endl;

	if (this == &src)
		return ( *this );
	for ( int i = 0; i < NUM_IDEAS; i++ )
		_ideas[i] = src._ideas[i];
	return ( *this );
}
