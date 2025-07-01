/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:17:55 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 12:16:29 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm( void );
	AForm( const std::string name, const int gToSign, const int gToExe );
	AForm( const AForm &src );
	virtual ~AForm( void );

	AForm &operator= ( const AForm &src );

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

	class IsNotSignedException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};

	const std::string	getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExe( void ) const;

	void				setTarget( std::string target );
	void				beSigned( const Bureaucrat &b );
	std::string			printIsSigned( void ) const;
	virtual void		printExecute( void ) const  = 0;
	void				execute( Bureaucrat const & executor ) const;

protected:
	std::string	_name;
	bool		_isSigned;
	int			_gradeToSign;
	int			_gradeToExe;

private:

};

std::ostream	&operator<< (std::ostream &out, const AForm &src );

#endif