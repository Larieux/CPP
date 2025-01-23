/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:35:15 by mlarieux          #+#    #+#             */
/*   Updated: 2025/01/23 11:35:19 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	std::string 			str;
	std::string::iterator	it;
	std::string				res;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1 && argv)
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (it = str.begin(); it != str.end(); ++it)
				res += std::toupper(*it);
		}
		std::cout << res << std::endl;
	}
	return (0);
}