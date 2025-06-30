/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 16:31:51 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm()
{
	_gradeToSign = 145;
	_gradeToExe = 137;
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

void				ShrubberyCreationForm::beExe( const Bureaucrat &b ) const
{
	if ( b.getGrade() > _gradeToExe )
		throw(GradeTooLowException());
	std::string		shName;
	shName = getName() + "_shrubbery";
	std::ofstream	file( shName.c_str() );

	file << "              v .   ._, |_  .,\n"
"           `-._\\/  .  \\ /    |/_\n"
"               \\\\  _\\, y | \\//\n"
"         _\\_.___\\\\, \\\\/ -.\\||\n"
"           `7-,--.`._||  / / ,\n"
"           /'     `-. `./ / |/_.'\n"
"                     |    |//\n"
"                     |_    /\n"
"                     |-   |\n"
"                     |   =|\n"
"                     |    |\n"
"                    / ,  . \\\n" << std::endl;
	file << "              v .   ._, |_  .,\n"
"           `-._\\/  .  \\ /    |/_\n"
"               \\\\  _\\, y | \\//\n"
"         _\\_.___\\\\, \\\\/ -.\\||\n"
"           `7-,--.`._||  / / ,\n"
"           /'     `-. `./ / |/_.'\n"
"                     |    |//\n"
"                     |_    /\n"
"                     |-   |\n"
"                     |   =|\n"
"                     |    |\n"
"                    / ,  . \\\n" << std::endl;
	file << "              v .   ._, |_  .,\n"
"           `-._\\/  .  \\ /    |/_\n"
"               \\\\  _\\, y | \\//\n"
"         _\\_.___\\\\, \\\\/ -.\\||\n"
"           `7-,--.`._||  / / ,\n"
"           /'     `-. `./ / |/_.'\n"
"                     |    |//\n"
"                     |_    /\n"
"                     |-   |\n"
"                     |   =|\n"
"                     |    |\n"
"                    / ,  . \\\n" << std::endl;
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
