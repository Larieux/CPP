/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:05:13 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:52:17 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog( void );
	Dog( const Dog &src );
	~Dog( void );

	Dog &operator= ( const Dog &src );

	std::string	getBrain( int which ) const;

	void		makeSound( void ) const;

protected:


private:
	Brain	*_brain;

};

#endif