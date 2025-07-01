/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:41 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 14:04:32 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm &src );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm &operator= ( const ShrubberyCreationForm &src );

	void	printExecute( void ) const ;

protected:

private:
	std::string	_target;

};

std::ostream	&operator<< (std::ostream &out, const ShrubberyCreationForm &src );

#endif