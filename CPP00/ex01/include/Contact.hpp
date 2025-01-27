/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:41 by mlarieux          #+#    #+#             */
/*   Updated: 2025/01/23 13:58:36 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {

private:

	static int	contact_number;

	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;

public:

	Contact( void );
	~Contact( void );


	void	displaySearch(int mode)const;
	void	truncateDisplay(std::string field)const;

	int		getContactNumber(void)const;
	void	setContactNumber(void);

	void	setFirstName(std::string value);
	void	setLastName(std::string value);
	void	setNickname(std::string value);
	void	setPhoneNumber(std::string value);
	void	setSecret(std::string value);

};

#endif
