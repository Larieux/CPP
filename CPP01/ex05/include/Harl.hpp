/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:03:40 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/07 16:15:33 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
public:
	Harl();
	~Harl();

	void	complain( std::string level );

private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );

};

#endif