/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:47:10 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 13:36:16 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <map>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm;

class Intern
{
public:
	Intern( void );
	Intern( const Intern &src );
	~Intern( void );

	Intern &operator= ( const Intern &src );

	class UnknownFormTypeException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	AForm	*Shrub( const std::string target );
	AForm	*Rob( const std::string target );
	AForm	*Pardon( const std::string target );
	AForm	*makeForm( const std::string name, const std::string target );

protected:

private:

};

#endif