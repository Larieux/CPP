/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:17:55 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/14 19:38:25 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
public:
	AForm( void );
	AForm( const std::string name, const int gToSign, const int gToExe );
	AForm( const AForm &src );
	~AForm( void );

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

	const std::string	getName( void ) const;
	bool				getIsSigned( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExe( void ) const;

	void				beSigned( const Bureaucrat &b ) const;
	std::string			printIsSigned( void ) const;

protected:


private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExe;

};

std::ostream	&operator<< (std::ostream &out, const AForm &src );

#endif