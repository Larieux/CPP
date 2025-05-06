/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:46 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/06 19:06:44 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) :
			_name(NULL),
			_grade(NULL)
{
	std::cout	<< "default Bureaucrat constructor called"
				<< std::endl;

	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat &src ) :
			_name(src.getName()),
			_grade(src.getGrade())
{
	std::cout	<< "copy Bureaucrat constructor called"
				<< std::endl;

	return ;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout	<< "default Bureaucrat destructor called"
				<< std::endl;

	return ;
}


Bureaucrat &Bureaucrat::operator= ( const Bureaucrat &src )
{
	_grade = src.getGrade();

	std::cout	<< "copy assignment operator called"
				<< std::endl;

	return ( *this );
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}
