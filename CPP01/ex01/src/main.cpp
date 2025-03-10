/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:42:50 by mlarieux          #+#    #+#             */
/*   Updated: 2025/03/10 14:44:14 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include "zombie.hpp"

#define THERES_TOO_MANY_OF_THEM	9
#define AND_THEIR_NAME_IS		"Brian"

Zombie*	zombieHorde( int N, std::string name );

int	main( void )
{
	Zombie 			*horde;
	int				N;

	N = THERES_TOO_MANY_OF_THEM;
	horde = zombieHorde(N, AND_THEIR_NAME_IS);
	for (int i = 0; i < N; i++)
		horde->announce();

	return (0);
}