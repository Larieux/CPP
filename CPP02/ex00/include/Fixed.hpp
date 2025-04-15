/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:42:03 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/15 23:18:49 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const &original );
	~Fixed( void );

	Fixed &operator= (Fixed const &original);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

private:
	int					_value;
	static const int	_bits;

};

#endif