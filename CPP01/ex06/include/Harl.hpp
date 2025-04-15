/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:03:40 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/08 00:05:25 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

#define LEVEL_NB	5
#define DEBUG_MSG	"debug message"
#define INFO_MSG	"info message"
#define WARNING_MSG	"warning message"
#define ERROR_MSG	"error message"
#define OTHER_MSG	"other message"

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
	void	other( void );

};

#endif