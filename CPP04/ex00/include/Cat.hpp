/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:17:20 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/17 17:17:28 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

#include <Animal.hpp>

class Cat : protected Animal
{
public:
	Cat( void );
	Cat( std::string type );
	Cat( const Cat &src );
	~Cat( void );

	Cat &operator= ( const Cat &src );

protected:


private:


};

#endif