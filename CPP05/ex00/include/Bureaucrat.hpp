/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:47:10 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/06 18:53:24 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat( void );
	Bureaucrat( const Bureaucrat &src );
	virtual ~Bureaucrat( void );

	Bureaucrat &operator= ( const Bureaucrat &src );

	std::string	getName() const;
	int			getGrade() const;

protected:

private:
	const std::string	_name;
	int					_grade;

};

#endif