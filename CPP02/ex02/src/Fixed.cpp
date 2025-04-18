/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:06:24 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/18 15:52:35 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0)
{
	return ;
}

Fixed::Fixed( const Fixed &original )
{
	*this = original;
	return ;
}

Fixed::Fixed( const int to_fixed )
{
	_value = to_fixed * (1 << _bits);
	return ;
}


Fixed::Fixed( const float to_fixed )
{
	_value = roundf(to_fixed * (1 << _bits));
	return ;
}


Fixed::~Fixed( void )
{
	return ;
}

Fixed &Fixed::operator= ( const Fixed &original )
{
	if (this != &original)
	_value = original.getRawBits();
	return ( *this );
}

bool Fixed::operator== ( const Fixed &comp_to ) const
{
	return (this->getRawBits() == comp_to._value);
}

bool Fixed::operator!= ( const Fixed &comp_to ) const
{
	return (this->getRawBits() != comp_to._value);
}

bool Fixed::operator<= ( const Fixed &comp_to ) const
{
	return (this->getRawBits() <= comp_to._value);
}

bool Fixed::operator>= ( const Fixed &comp_to ) const
{
	return (this->getRawBits() >= comp_to._value);
}

bool Fixed::operator< ( const Fixed &comp_to ) const
{
	return (this->getRawBits() < comp_to._value);
}

bool Fixed::operator> ( const Fixed &comp_to ) const
{
	return (this->getRawBits() > comp_to._value);
}


Fixed Fixed::operator+ ( const Fixed &worked_from ) const
{
	return (Fixed(this->toFloat() + worked_from.toFloat()));
}

Fixed Fixed::operator- ( const Fixed &worked_from ) const
{
	return (Fixed(this->toFloat() - worked_from.toFloat()));
}

Fixed Fixed::operator* ( const Fixed &worked_from ) const
{
	return (Fixed(this->toFloat() * worked_from.toFloat()));
}

Fixed Fixed::operator/ ( const Fixed &worked_from ) const
{
	return (Fixed(this->toFloat() / worked_from.toFloat()));
}


Fixed &Fixed::operator++ ( void )
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++ ( int )
{
	Fixed tmp;

	tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed &Fixed::operator-- ( void )
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator-- ( int )
{
	Fixed tmp;

	tmp = *this;
	this->_value--;
	return (tmp);
}


Fixed &Fixed::min (Fixed &comp_from, Fixed &comp_to)
{
	return (comp_from._value <= comp_to._value ? comp_from : comp_to);
}

const Fixed &Fixed::min (const Fixed &comp_from, const Fixed &comp_to)
{
	return (comp_from._value <= comp_to._value ? comp_from : comp_to);
}

Fixed &Fixed::max (Fixed &comp_from, Fixed &comp_to)
{
	return (comp_from._value >= comp_to._value ? comp_from : comp_to);
}

const Fixed &Fixed::max (const Fixed &comp_from, const Fixed &comp_to)
{
	return (comp_from._value >= comp_to._value ? comp_from : comp_to);
}


int		Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	int		intValue = getRawBits();
	float	floatValue = 0.0;

	floatValue = (float)intValue / (float)(1 << _bits);
	return ( floatValue );
}

int		Fixed::toInt( void ) const
{
	return ( _value / (1 << _bits) );
}

std::ostream &operator<< ( std::ostream &outStream, const Fixed &fixed )
{
	outStream << fixed.toFloat();
	return ( outStream );
}
