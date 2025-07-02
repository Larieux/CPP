/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:47 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/02 11:23:03 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

/******************************************************************************/
/* structors                                                                  */
/******************************************************************************/

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm( "Shrubbery Creation Form", 145, 137),
	_target("home")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	AForm( "Shrubbery Creation Form", 145, 137),
	_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) :
	AForm( "Shrubbery Creation Form", 145, 137),
	_target("home")
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

/******************************************************************************/
/* operator overload                                                          */
/******************************************************************************/

ShrubberyCreationForm &ShrubberyCreationForm::operator= ( const ShrubberyCreationForm &src )
{
	if (this != &src)
		_target = src.getTarget();
	return ( *this );
}

/******************************************************************************/
/* member functions                                                           */
/******************************************************************************/

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return ( _target );
}

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
