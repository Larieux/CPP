/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:46:58 by mlarieux          #+#    #+#             */
/*   Updated: 2025/05/12 19:37:39 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
	try
	{
		Bureaucrat	a;

		std::cout << a << std::endl;
		a.icrementGrade();
		std::cout << a << std::endl;
		a.icrementGrade();
		std::cout << a << std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cerr	<< "Exception caught: "
					<< e.what()
					<< std::endl;
	}

	try
	{
		Bureaucrat	min( "Ahntwann", MIN_GRADE - 2 );

		std::cout << min << std::endl;
		min.decrementGrade();
		std::cout << min << std::endl;
		min.decrementGrade();
		std::cout << min << std::endl;
		min.decrementGrade();
		std::cout << min << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< "Exception caught: "
					<< e.what()
					<< std::endl;
	}

	try
	{
		Bureaucrat	max( "guy", MAX_GRADE + 2 );

		std::cout << max << std::endl;
		max.icrementGrade();
		std::cout << max << std::endl;
		max.icrementGrade();
		std::cout << max << std::endl;
		max.icrementGrade();
		std::cout << max << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr	<< "Exception caught: "
					<< e.what()
					<< std::endl;
	}
	
	try
	{
		Bureaucrat	lolilol( "lolilol", MAX_GRADE - 1 );
	}
	catch(const std::exception& e)
	{
		std::cerr	<< "Exception caught: "
					<< e.what()
					<< std::endl;
	}
	return (0);
}