/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 01:00:30 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:49:39 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

#define	NUM_IDEAS 100

class Brain
{
public:
	Brain( void );
	Brain( const Brain &src );
	~Brain( void );

	Brain &operator= ( const Brain &src );

	const std::string	getIdea( int which ) const;

protected:


private:
	std::string	_ideas[NUM_IDEAS];

};

#endif