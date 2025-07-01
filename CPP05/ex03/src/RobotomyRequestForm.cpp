/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marceline <marceline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 17:19:51 by marceline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm(),
	_target("home")
{
	_name = "hi";
	_isSigned = false;
	_gradeToSign = 72;
	_gradeToExe = 45;
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	AForm(),
	_target(target)
{
	_gradeToSign = 72;
	_gradeToExe = 45;
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) :
	AForm( src ),
	_target("home")
{
	*this = src;
	std::cout	<< "copy constructor called for "
				<< _name
				<< std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout	<< "destructor called for "
				<< _name
				<< std::endl;
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

RobotomyRequestForm &RobotomyRequestForm::operator= ( const RobotomyRequestForm &src )
{
	_isSigned = src.getIsSigned();
	return ( *this );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

void				RobotomyRequestForm::printExecute( void ) const 
{
	std::cout << "*deafening drilling noises*" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << _name << " has been successfully robotomized" << std::endl;
	else
		std::cout << _name << " robotomy failed" << std::endl;
}

/******************************************************************************/
/* stream operator overload                                                   */
/******************************************************************************/

std::ostream	&operator<< (std::ostream &out, const RobotomyRequestForm &src )
{
	out	<< "Name : " << src.getName() << ",\n"
		<< "is : " << src.printIsSigned() << ",\n"
		<< "grade required to sign : " << src.getGradeToSign() << ",\n"
		<< "grade required to execute : " << src.getGradeToExe() << std::endl;
	
	return ( out );
}
