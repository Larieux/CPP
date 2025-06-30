/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:31:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/14 19:40:10 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	_name( "random ShrubberyCreationForm" ),
	_isSigned( false ),
	_gradeToSign( 145 ),
	_gradeToExe( 137 )
{
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string name,
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

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) :
	_name( src.getName() ),
	_isSigned( src.getIsSigned() ),
	_gradeToSign( src.getGradeToSign() ),
	_gradeToExe( src.getGradeToExe() )
{
	std::cout	<< "copy constructor called for "
				<< _name
				<< std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout	<< "destructor called for "
				<< _name
				<< std::endl;
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

ShrubberyCreationForm &ShrubberyCreationForm::operator= ( const ShrubberyCreationForm &src )
{
	_isSigned = src.getIsSigned();
	return ( *this );
}

/******************************************************************************/
/* member classes                                                             */
/******************************************************************************/

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return ("Invalid grade : Maximum grade is 1");
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return ("Invalid grade : Minimum grade is 150");
}

/******************************************************************************/
/* geters                                                                     */
/******************************************************************************/

const std::string	ShrubberyCreationForm::getName( void ) const
{
	return ( _name );
}

bool			ShrubberyCreationForm::getIsSigned( void ) const
{
	return ( _isSigned );
}

int			ShrubberyCreationForm::getGradeToSign( void ) const
{
	return ( _gradeToSign );
}

int			ShrubberyCreationForm::getGradeToExe( void ) const
{
	return ( _gradeToExe );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

std::string			ShrubberyCreationForm::printIsSigned( void ) const
{
	if ( getIsSigned() == false )
		return ( "not signed" );
	else
		return ( "signed" );
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<< (std::ostream &out, const ShrubberyCreationForm &src )
{
	out	<< "Name : " << src.getName() << ",\n"
		<< "is : " << src.printIsSigned() << ",\n"
		<< "grade required to sign : " << src.getGradeToSign() << ",\n"
		<< "grade required to execute : " << src.getGradeToExe() << std::endl;
	
	return ( out );
}
