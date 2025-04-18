/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:50:09 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/18 01:50:29 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP

#include <WrongAnimal.hpp>

class WrongCat : protected WrongAnimal
{
public:
	WrongCat( void );
	WrongCat( std::string type );
	WrongCat( const WrongCat &src );
	~WrongCat( void );

	WrongCat &operator= ( const WrongCat &src );

protected:


private:


};

#endif