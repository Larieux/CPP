/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:03:45 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/15 21:02:05 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		Harl	harl;
		if (std::string(argv[1]) == "42")
		{
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			harl.complain("no");
		}
		else
			harl.complain(argv[1]);
	}
	else
	{
		std::cout	<< "wrong input\ntry './theWorstHarl <LEVEL>'"
					<< std::endl;
	}
}