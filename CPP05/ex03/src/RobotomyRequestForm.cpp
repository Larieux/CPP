/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/02 11:23:20 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RobotomyRequestForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm( "Robotomy Request Form", 72, 45),
	_target("home")
{
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	AForm( "Robotomy Request Form", 72, 45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) :
	AForm( "Robotomy Request Form", 72, 45),
	_target("home")
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

RobotomyRequestForm &RobotomyRequestForm::operator= ( const RobotomyRequestForm &src )
{
	if (this != &src)
		_target = src.getTarget();
	return ( *this );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return ( _target );
}

void				RobotomyRequestForm::printExecute( void ) const 
{
	std::cout << "*deafening drilling noises*" << std::endl;
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << _target << " has been successfully robotomized" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
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
