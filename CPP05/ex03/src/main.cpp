/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:58 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/02 11:24:32 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	try
	{
		Bureaucrat				a( "benedicte", 73 );
		Bureaucrat				b( "bella", 46 );
		Intern 					someRandomIntern;
		AForm* 					f = someRandomIntern.makeForm("Robotomy Request", "Bender");

		std::cout << *f;

		a.signForm( *f );
		b.executeForm( *f );
		f->printIsSigned();
		a.icrementGrade();
		b.icrementGrade();
		a.signForm( *f );
		b.executeForm( *f );
		f->printIsSigned();
		delete (f);
	}
	catch ( const std::exception &e )
	{
		std::cerr	<< "Exception caught: "
					<< e.what()
					<< std::endl;
	}

	try
	{
		Intern 					someRandomIntern;
		AForm* 					n = someRandomIntern.makeForm("notaform", "Botcher");
		n->printIsSigned();
	}
	catch ( const std::exception &e )
	{
		std::cerr	<< "Exception caught: "
					<< e.what()
					<< std::endl;
	}

	return (0);
}