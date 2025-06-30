/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marceline <marceline@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:41 by mlarieux          #+#    #+#             */
/*   Updated: 2025/06/30 18:30:11 by marceline        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( const RobotomyRequestForm &src );
	~RobotomyRequestForm( void );

	RobotomyRequestForm &operator= ( const RobotomyRequestForm &src );

	void				execute( const Bureaucrat &b ) const;

protected:

private:

};

std::ostream	&operator<< (std::ostream &out, const RobotomyRequestForm &src );

#endif