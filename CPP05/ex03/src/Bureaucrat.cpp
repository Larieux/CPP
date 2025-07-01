/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marceline <marceline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:46 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 17:15:28 by marceline        ###   ########.fr       */
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
			_name( name ),
			_grade( grade )
{
	if ( grade < MAX_GRADE )
		throw(GradeTooHighException());
	if ( grade > MIN_GRADE )
		throw(GradeTooLowException());

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
		throw( GradeTooLowException() );
	_grade++;
}

void		Bureaucrat::signForm( AForm &f )
{
	try
	{
		f.beSigned( *this );
	}
	catch ( const std::exception &e )
	{
		std::cerr	<< getName()
					<< " could not sign "
					<< f.getName()
					<< " because "
					<< e.what()
					<< std::endl;
		return ;
	}

	std::cout	<< getName()
				<< " signed "
				<< f.getName()
				<< std::endl;
}

void		Bureaucrat::executeForm( AForm const & form ) const
{
	try
	{
		form.execute( *this );
	}
	catch ( const std::exception &e )
	{
		std::cerr	<< getName()
					<< " could not execute "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
		return ;
	}

	std::cout	<< getName()
				<< " executed "
				<< form.getName()
				<< std::endl;
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return ( out );
}