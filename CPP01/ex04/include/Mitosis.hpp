/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mitosis.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:05:52 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/06 04:28:11 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MITOSIS_HPP
# define MITOSIS_HPP

#include <iostream>
#include <fstream>

class Mitosis
{
public:
	Mitosis( void );
	~Mitosis( void );

	bool	exonuclease( int argc, char **argv );
	void	set_file_name( std::string file_name );
	void	set_s1( std::string s1 );
	void	set_s2( std::string s2 );
	void	mitosing( void );

private:
	std::string		_file_name;
	std::ifstream	_infile;
	std::ofstream	_outfile;
	std::string		_s1;
	std::string		_s2;
	std::string		msg;

	bool			dsa( void );
	void			mutating( std::string &dna );

};

#endif
