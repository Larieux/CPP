/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:31:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 15:13:32 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

Form::Form( void ) :
	_name( "random form" ),
	_isSigned( false ),
	_gradeToSign( 150 ),
	_gradeToExe( 150 )
{
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

Form::Form( const std::string name,
	const int gradeToSign, const int gradeToExe ) :
		_name( name ),
		_isSigned( false ),
		_gradeToSign( gradeToSign ),
		_gradeToExe( gradeToExe )
{
	std::cout	<< "filler constructor called for "
				<< _name
				<< std::endl;
}

Form::Form( const Form &src ) :
	_name( src.getName() ),
	_isSigned( src.getIsSigned() ),
	_gradeToSign( src.getGradeToSign() ),
	_gradeToExe( src.getGradeToExe() )
{
	std::cout	<< "copy constructor called for "
				<< _name
				<< std::endl;
}

Form::~Form( void )
{
	std::cout	<< "destructor called for "
				<< _name
				<< std::endl;
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

Form &Form::operator= ( const Form &src )
{
	_isSigned = src.getIsSigned();
	return ( *this );
}

/******************************************************************************/
/* member classes                                                             */
/******************************************************************************/

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Invalid grade : grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Invalid grade : grade too low");
}

/******************************************************************************/
/* geters                                                                     */
/******************************************************************************/

const std::string	Form::getName( void ) const
{
	return ( _name );
}

bool			Form::getIsSigned( void ) const
{
	return ( _isSigned );
}

int			Form::getGradeToSign( void ) const
{
	return ( _gradeToSign );
}

int			Form::getGradeToExe( void ) const
{
	return ( _gradeToExe );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

void				Form::beSigned( const Bureaucrat &b )
{
	if ( b.getGrade() > _gradeToSign )
		throw(GradeTooLowException());
	_isSigned = true;
}

std::string			Form::printIsSigned( void ) const
{
	if ( getIsSigned() == false )
		return ( "not signed" );
	else
		return ( "signed" );
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<< (std::ostream &out, const Form &src )
{
	out	<< "Name : " << src.getName() << ",\n"
		<< "is : " << src.printIsSigned() << ",\n"
		<< "grade required to sign : " << src.getGradeToSign() << ",\n"
		<< "grade required to execute : " << src.getGradeToExe() << std::endl;
	
	return ( out );
}
