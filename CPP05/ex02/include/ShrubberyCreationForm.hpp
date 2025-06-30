/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationFor.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:17:55 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/14 19:38:25 by mlarieux         ###   ########.fr       */
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
	ShrubberyCreationForm( const ShrubberyCreationForm &src );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm &operator= ( const ShrubberyCreationForm &src );

	void				beExe( const Bureaucrat &b ) const;

protected:

private:

};

std::ostream	&operator<< (std::ostream &out, const ShrubberyCreationForm &src );

#endif