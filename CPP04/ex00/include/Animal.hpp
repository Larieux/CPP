/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:52:05 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:19:24 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal( void );
	Animal( const Animal &src );
	virtual ~Animal( void );

	Animal &operator= ( const Animal &src );

	virtual void		makeSound( void ) const;
	std::string			getType( void ) const;

protected:
	std::string _type;

private:


};

#endif