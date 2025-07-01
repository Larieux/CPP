/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marceline <marceline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 17:17:35 by marceline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm(),
	_target("home")
{
	_name = "hi";
	_isSigned = false;
	_gradeToSign = 145;
	_gradeToExe = 137;
	_target = "home";
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	AForm(),
	_target(target)
{
	_gradeToSign = 145;
	_gradeToExe = 137;
	std::cout	<< "default constructor called for "
				<< _name
				<< std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) :
	AForm( src ),
	_target("home")
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

void				ShrubberyCreationForm::printExecute( void ) const 
{
	std::string		shName;
	shName = _target + "_shrubbery";
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
