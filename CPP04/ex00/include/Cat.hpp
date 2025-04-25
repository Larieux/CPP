/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:17:20 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/25 15:51:42 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat( void );
	Cat( const std::string type );
	Cat( const Cat &src );
	~Cat( void );

	Cat &operator= ( const Cat &src );

	void	makeSound( void ) const;

protected:


private:


};

#endif