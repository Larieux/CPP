/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:44:09 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/08 21:13:20 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mitosis.hpp"

int	main( int argc, char **argv )
{
	Mitosis	mitosis;

	if (!mitosis.exonuclease( argc, argv ))
		return ( 1 );
	mitosis.set_file_name( argv[1] );
	mitosis.set_s1( argv[2] );
	mitosis.set_s2( argv[3] );
	mitosis.mitosing();
	return ( 0 );
}