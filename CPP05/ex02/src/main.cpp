/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:58 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 16:01:35 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	try
	{
		Bureaucrat				a( "benedicte", 147 );
		Bureaucrat				b( "bella", 139 );
		ShrubberyCreationForm	f;

		std::cout << "a: " << a.getGrade() << "\nf: " << f.getGradeToSign() << "\n" << f.getGradeToExe() << std::endl; 

		a.signForm( f );
		b.exeForm( f );
		f.printIsSigned();
		a.icrementGrade();
		b.icrementGrade();
		a.signForm( f );
		b.exeForm( f );
		f.printIsSigned();
		a.icrementGrade();
		b.icrementGrade();
		a.signForm( f );
		b.exeForm( f );
		f.printIsSigned();
		a.decrementGrade();
		b.decrementGrade();
		a.signForm( f );
		b.exeForm( f );
		f.printIsSigned();
	}
	catch ( const std::exception &e )
	{
		std::cerr	<< "Exception caught: "
					<< e.what()
					<< std::endl;
	}

	return (0);
}