/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:42:50 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/08 21:09:28 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void )
{
	Zombie	*infected( NULL );

	infected = newZombie( "Infected" );
	infected->announce();
	delete (infected);

	randomChump( "Undead" );
	return (0);
}