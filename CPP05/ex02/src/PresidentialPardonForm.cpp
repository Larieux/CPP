/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/09/13 18:46:26 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm( "Presidentian Pardon Form", 25, 5),
	_target("home")
{
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	AForm( "Presidentian Pardon Form", 25, 5),
	_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) :
	AForm( "Presidentian Pardon Form", 25, 5),
	_target("home")
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

PresidentialPardonForm &PresidentialPardonForm::operator= ( const PresidentialPardonForm &src )
{
	if (this != &src)
		_target = src.getTarget();
	return ( *this );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return ( _target );
}

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
