/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marceline <marceline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 17:20:32 by marceline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm(),
	_target("home")
{
	_name = "hi";
	_isSigned = false;
	_gradeToSign = 25;
	_gradeToExe = 5;
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	AForm(),
	_target(target)
{
	_name = "hi";
	_isSigned = false;
	_gradeToSign = 25;
	_gradeToExe = 5;
	std::cout	<< "alt constructor called for "
				<< _name
				<< std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) :
	AForm(),
	_target("home")
{
	*this = src;
	std::cout	<< "copy constructor called for "
				<< _name
				<< std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout	<< "destructor called for "
				<< _name
				<< std::endl;
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

PresidentialPardonForm &PresidentialPardonForm::operator= ( const PresidentialPardonForm &src )
{
	_isSigned = src.getIsSigned();
	return ( *this );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

void				PresidentialPardonForm::printExecute( void ) const 
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<< (std::ostream &out, const PresidentialPardonForm &src )
{
	out	<< "Name : " << src.getName() << ",\n"
		<< "is : " << src.printIsSigned() << ",\n"
		<< "grade required to sign : " << src.getGradeToSign() << ",\n"
		<< "grade required to execute : " << src.getGradeToExe() << std::endl;
	
	return ( out );
}
