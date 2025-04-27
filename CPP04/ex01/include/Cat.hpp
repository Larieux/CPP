/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:17:20 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 17:52:48 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat( void );
	Cat( const Cat &src );
	~Cat( void );

	Cat &operator= ( const Cat &src );

	void	makeSound( void ) const;

protected:


private:
	Brain	*_brain;

};

#endif