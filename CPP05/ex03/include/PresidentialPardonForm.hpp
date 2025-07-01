/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:31:41 by mlarieux          #+#    #+#             */
/*   Updated: 2025/07/01 14:04:33 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESITENTIALPARDONFORM_HPP
# define PRESITENTIALPARDONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm &src );
	~PresidentialPardonForm( void );

	PresidentialPardonForm &operator= ( const PresidentialPardonForm &src );

	void	printExecute( void ) const ;

protected:

private:
	std::string	_target;

};

std::ostream	&operator<< (std::ostream &out, const PresidentialPardonForm &src );

#endif