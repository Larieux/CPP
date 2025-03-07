/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:38:59 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/07 15:39:01 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>

class Zombie {
private:

	std::string	_name;

public:

	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );
	Zombie*	zombieHorde( int N, std::string name );
};

#endif