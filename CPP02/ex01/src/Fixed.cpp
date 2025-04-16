/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:06:24 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/16 02:00:50 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const &original )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
	return ;
}

Fixed::Fixed( const int to_fixed )
{
	std::cout << "Int constructor called" << std::endl;
	_value = to_fixed * (1 << _bits);
	return ;
}


Fixed::Fixed( const float to_fixed )
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(to_fixed * (1 << _bits));
	return ;
}


Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator= ( Fixed const &original )
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = original.getRawBits();
	return ( *this );
}

int		Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	int		intValue = getRawBits();
	float	floatValue = 0.0;

	floatValue = intValue / (float)(1 << _bits);
	return ( floatValue );
}

int		Fixed::toInt( void ) const
{
	return ( _value / (1 << _bits) );
}

std::ostream &operator<< ( std::ostream &outStream, Fixed const &fixed )
{
	outStream << fixed.toFloat();
	return ( outStream );
}
