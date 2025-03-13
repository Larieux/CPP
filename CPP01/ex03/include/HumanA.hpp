/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:57:10 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/12 14:07:31 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>

class HumanA
{
private :

	std::string weapon;
	std::string name;

public :

	HumanA( std::string weapon );
	~HumanA( void );

	void	attack ( void );

};

#endif