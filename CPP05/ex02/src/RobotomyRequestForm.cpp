/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marceline <marceline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 18:30:11 by marceline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm()
{
	_gradeToSign = 72;
	_gradeToExe = 45;
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) : AForm( src )
{
	*this = src;
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
/* member functions                                                           */
/******************************************************************************/

void				ShrubberyCreationForm::execute( const Bureaucrat &b ) const
{
	if ( b.getGrade() > _gradeToExe )
		throw(GradeTooLowException());

	std::cout << "*deafening drilling noises*" << std::endl;
	if (std::rand() % 2)
		std::cout << _name << " has been successfully robotomized" << std::endl;
	else
		std::cout << _name << " robotomy failed" << std::endl;
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<< (std::ostream &out, const ShrubberyCreationForm &src )
{
	out	<< "Name : " << src.getName() << ",\n"
		<< "is : " << src.printIsSigned() << ",\n"
		<< "grade required to sign : " << src.getGradeToSign() << ",\n"
		<< "grade required to exeForm : " << src.getGradeToExe() << std::endl;
	
	return ( out );
}
