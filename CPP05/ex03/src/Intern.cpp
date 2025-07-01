/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:46 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 13:58:07 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

Intern::Intern( void )
{
	std::cout	<< "default Intern constructor called"
				<< std::endl;

	return ;
}

Intern::Intern( const Intern &src )
{
	*this = src;
	std::cout	<< "copy Intern constructor called"
				<< std::endl;

	return ;
}

Intern::~Intern( void )
{
	std::cout	<< "default Intern destructor called"
				<< std::endl;

	return ;
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

Intern &Intern::operator= ( const Intern &src )
{
	(void)src;
	std::cout	<< "copy assignment operator called"
				<< std::endl;

	return ( *this );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

AForm	*Intern::Shrub( const std::string target )
{
	return ( new ShrubberyCreationForm( target ) );
}

AForm	*Intern::Rob( const std::string target )
{
	return ( new RobotomyRequestForm( target ) );
}

AForm	*Intern::Pardon( const std::string target )
{
	return ( new PresidentialPardonForm( target ) );
}

const char *Intern::UnknownFormTypeException::what() const throw()
{
	return ("Invalid form type");
}


AForm	*Intern::makeForm( const std::string name, const std::string target )
{
	static std::map<std::string, AForm *(Intern::*)( const std::string target ) > formType;
	formType["Shrubbery Creation"] = &Intern::Shrub;
	formType["Robotomy Request"] = &Intern::Rob;
	formType["Presitential Pardon"] = &Intern::Pardon;

	std::map<std::string, AForm *(Intern::*)( const std::string target ) >::iterator it;
	it = formType.find( name );
	if ( it == formType.end() )
		throw ( UnknownFormTypeException() );
	std::cout << "Intern creates " << target << std::endl;
	return (( this->*( it->second ) )( target ));
}
