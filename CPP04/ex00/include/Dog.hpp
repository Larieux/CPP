/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:05:13 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/25 15:51:36 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog( void );
	Dog( const std::string type );
	Dog( const Dog &src );
	~Dog( void );

	Dog &operator= ( const Dog &src );

	void	makeSound( void ) const;

protected:


private:


};

#endif