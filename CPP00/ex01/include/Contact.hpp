/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:17:35 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/03 19:39:22 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
public:
	Contact();
	~Contact();

	void		set_FirstName( std::string input );
	void		set_LastName( std::string input );
	void		set_Nickname( std::string input );
	void		set_PhoneNumber( std::string input );
	void		set_Secret( std::string input );
	void		display_contact( Contact contact )const;
	std::string	display_search( Contact contact )const;

	bool		is_set;

private:
	std::string	truncate_display( std::string display );
	std::string	FirstName;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	Secret;

};

#endif
