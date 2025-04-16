/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:42:03 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/16 17:09:00 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed( void );
	Fixed( Fixed const &original );
	Fixed( const int to_fixed );
	Fixed( const float to_fixed );
	~Fixed( void );

	Fixed &operator= ( Fixed const &original );

	bool operator== ( Fixed const &comp_to ) const;
	bool operator!= ( Fixed const &comp_to ) const;
	bool operator<= ( Fixed const &comp_to ) const;
	bool operator>= ( Fixed const &comp_to ) const;
	bool operator< ( Fixed const &comp_to ) const;
	bool operator> ( Fixed const &comp_to ) const;

	Fixed operator+ ( Fixed const &worked_from );
	Fixed operator- ( Fixed const &worked_from );
	Fixed operator* ( Fixed const &worked_from );
	Fixed operator/ ( Fixed const &worked_from );

	Fixed &operator++ ( void );
	Fixed operator++ ( int );
	Fixed &operator-- ( void );
	Fixed operator-- ( int );

	static Fixed &min (Fixed &comp_from, Fixed &comp_to);
	static const Fixed &min (const Fixed &comp_from, const Fixed &comp_to);
	static Fixed &max (Fixed &comp_from, Fixed &comp_to);
	static const Fixed &max (const Fixed &comp_from, const Fixed &comp_to);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					_value;
	static const int	_bits = 8;

};

std::ostream &operator<< ( std::ostream &outStream, Fixed const &fixed );

#endif