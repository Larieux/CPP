/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:50:59 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/10 17:06:39 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string* ptr = &str;
	std::string& ref = str;

	std::cout << &str << '\n' << ptr << '\n' << &ref << std::endl;
	std::cout << str << '\n' << *ptr << '\n' << ref << std::endl;

	return (0);
}