/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:52:05 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/18 02:11:33 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
	Animal( void );
	Animal( std::string type );
	Animal( const Animal &src );
	~Animal( void );

	Animal &operator= ( const Animal &src );

	void		makeSound( void );
	std::string	getType( void );

protected:
	std::string _type;

private:


};

#endif