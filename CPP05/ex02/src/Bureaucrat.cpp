/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:46 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/14 19:33:28 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

Bureaucrat::Bureaucrat( void ) :
			_name("Beatriz"),
			_grade(MIN_GRADE)
{
	std::cout	<< "default Bureaucrat constructor called"
				<< std::endl;

	return ;
}

Bureaucrat::Bureaucrat( const std::string &name, const int &grade ):
			_name( name )
{
	if ( grade < MAX_GRADE )
		throw(GradeTooHighException());
	if ( grade > MIN_GRADE )
		throw(GradeTooLowException());

	_grade = grade;

	std::cout	<< _name
				<< " hired! their grade: "
				<< _grade
				<< std::endl;

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

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

Bureaucrat &Bureaucrat::operator= ( const Bureaucrat &src )
{
	_grade = src.getGrade();

	std::cout	<< "copy assignment operator called"
				<< std::endl;

	return ( *this );
}

/******************************************************************************/
/* member classes                                                             */
/******************************************************************************/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Invalid grade : Maximum grade is 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Invalid grade : Minimum grade is 150");
}

/******************************************************************************/
/* geters                                                           */
/******************************************************************************/

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade() const
{
	return (_grade);
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

void		Bureaucrat::icrementGrade()
{
	if ( _grade <= MAX_GRADE )
		throw(GradeTooHighException());
	_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if ( _grade >= MIN_GRADE )
		throw(GradeTooLowException());
	_grade++;
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return ( out );
}