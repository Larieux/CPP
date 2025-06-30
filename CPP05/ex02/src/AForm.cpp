/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:31:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 12:01:02 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

AForm::AForm( void ) :
	_name( "random_Aform" ),
	_isSigned( false ),
	_gradeToSign( 150 ),
	_gradeToExe( 150 )
{
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

AForm::AForm( const std::string name,
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

AForm::AForm( const AForm &src ) :
	_name( src.getName() ),
	_isSigned( src.getIsSigned() ),
	_gradeToSign( src.getGradeToSign() ),
	_gradeToExe( src.getGradeToExe() )
{
	std::cout	<< "copy constructor called for "
				<< _name
				<< std::endl;
}

AForm::~AForm( void )
{
	std::cout	<< "destructor called for "
				<< _name
				<< std::endl;
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

AForm &AForm::operator= ( const AForm &src )
{
	_isSigned = src.getIsSigned();
	return ( *this );
}

/******************************************************************************/
/* member classes                                                             */
/******************************************************************************/

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Invalid grade : grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Invalid grade : grade too low");
}

/******************************************************************************/
/* geters                                                                     */
/******************************************************************************/

const std::string	AForm::getName( void ) const
{
	return ( _name );
}

bool			AForm::getIsSigned( void ) const
{
	return ( _isSigned );
}

int			AForm::getGradeToSign( void ) const
{
	return ( _gradeToSign );
}

int			AForm::getGradeToExe( void ) const
{
	return ( _gradeToExe );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

void				AForm::beSigned( const Bureaucrat &b )
{
	if ( b.getGrade() > _gradeToSign )
		throw(GradeTooLowException());
	_isSigned = true;
	std::cout << getName() << " is signed." << std::endl;
}

std::string			AForm::printIsSigned( void ) const
{
	if ( getIsSigned() == false )
		return ( "not signed" );
	else
		return ( "signed" );
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<< (std::ostream &out, const AForm &src )
{
	out	<< "Name : " << src.getName() << ",\n"
		<< "is : " << src.printIsSigned() << ",\n"
		<< "grade required to sign : " << src.getGradeToSign() << ",\n"
		<< "grade required to execute : " << src.getGradeToExe() << std::endl;
	
	return ( out );
}
