/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:47:10 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/12 18:27:36 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

# define MAX_GRADE 1
# define MIN_GRADE 150

class Bureaucrat
{
public:
	Bureaucrat( void );
	Bureaucrat( const std::string &name, const int &grade );
	Bureaucrat( const Bureaucrat &src );
	virtual ~Bureaucrat( void );

	Bureaucrat &operator= ( const Bureaucrat &src );

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

	std::string	getName() const;
	int			getGrade() const;

	void		icrementGrade();
	void		decrementGrade();


protected:

private:
	const std::string	_name;
	int					_grade;

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src);

#endif