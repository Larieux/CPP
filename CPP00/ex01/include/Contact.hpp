/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 01:30:39 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	Secret;

public:
	Contact();
	~Contact();

	void	set_FirstName( std::string input );
	void	set_LastName( std::string input );
	void	set_Nickname( std::string input );
	void	set_PhoneNumber( std::string input );
	void	set_Secret( std::string input );
};

#endif
