/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:41 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/02 11:06:08 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm &src );
	~RobotomyRequestForm( void );

	RobotomyRequestForm &operator= ( const RobotomyRequestForm &src );

	std::string	getTarget( void ) const;

	void	printExecute( void ) const ;

protected:

private:
	std::string	_target;

};

std::ostream	&operator<< (std::ostream &out, const RobotomyRequestForm &src );

#endif