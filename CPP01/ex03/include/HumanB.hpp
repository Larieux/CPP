/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:07:43 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/12 14:08:14 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>

class HumanB
{
private :

	std::string weapon;
	std::string name;

public :

	HumanB( void );
	~HumanB( void );

	void	attack ( void );

};

#endif