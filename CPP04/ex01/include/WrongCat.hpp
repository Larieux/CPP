/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:50:09 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/27 18:30:55 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat( void );
	WrongCat( const WrongCat &src );
	~WrongCat( void );

	WrongCat &operator= ( const WrongCat &src );

	std::string	getIdea( int which ) const;

	void	makeSound( void ) const;

protected:


private:


};

#endif