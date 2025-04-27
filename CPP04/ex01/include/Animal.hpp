/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:52:05 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 19:00:10 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#define NUM_AN 10

class Animal
{
public:
	Animal( void );
	Animal( const Animal &src );
	virtual ~Animal( void );

	Animal &operator= ( const Animal &src );

	std::string			getType( void ) const;
	virtual std::string	getBrain( int which ) const;

	virtual void		makeSound( void ) const;

protected:
	std::string _type;

private:


};

#endif