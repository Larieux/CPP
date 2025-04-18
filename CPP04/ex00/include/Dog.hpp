/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:05:13 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/17 17:15:10 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <Animal.hpp>

class Dog : protected Animal
{
public:
	Dog( void );
	Dog( std::string type );
	Dog( const Dog &src );
	~Dog( void );

	Dog &operator= ( const Dog &src );

protected:


private:


};

#endif