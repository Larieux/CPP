/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:47:34 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/25 16:55:47 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal( void );
	WrongAnimal( const std::string type );
	WrongAnimal( const WrongAnimal &src );
	~WrongAnimal( void );

	WrongAnimal &operator= ( const WrongAnimal &src );

	void				makeSound( void ) const;
	std::string			getType( void ) const;

protected:
	std::string _type;

private:


};

#endif