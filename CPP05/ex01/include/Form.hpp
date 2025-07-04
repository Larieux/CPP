/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:17:55 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 12:16:29 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form( void );
	Form( const std::string name, const int gToSign, const int gToExe );
	Form( const Form &src );
	~Form( void );

	Form &operator= ( const Form &src );

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	const std::string	getName( void ) const;
	bool			getIsSigned( void ) const;
	int			getGradeToSign( void ) const;
	int			getGradeToExe( void ) const;

	void				beSigned( const Bureaucrat &b );
	std::string			printIsSigned( void ) const;

protected:


private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExe;

};

std::ostream	&operator<< (std::ostream &out, const Form &src );

#endif