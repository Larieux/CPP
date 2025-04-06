/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mitosis.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 01:51:45 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/06 04:44:06 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mitosis.hpp"

Mitosis::Mitosis( void )
{
	std::cout << "initiating mitosis" << std::endl;
}

Mitosis::~Mitosis( void )
{
	std::cout << msg << std::endl;
}

bool	Mitosis::exonuclease( int argc, char **argv )
{
	std::string	args;

	if ( argc != 4 || std::string (argv[2]).compare( "" ) == 0)
	{
		std::cout	<< "invalid input, "
					<< "try <filename> [search_string] [replace_string]"
					<< std::endl;
		msg = std::string ("mitosis aborted").substr( 0, 16 );
		return ( false );
	}
	return ( true );
}

void	Mitosis::set_file_name( std::string file_name )
{
	_file_name = file_name;
}

void	Mitosis::set_s1( std::string s1 )
{
	_s1 = s1;
}

void	Mitosis::set_s2( std::string s2 )
{
	_s2 = s2;
}

bool	Mitosis::dsa( void )
{
	_infile.open( _file_name.c_str() );

	if ( _infile.good() == false )
	{
		std::cout	<< "error: couldn't open "
					<< _file_name
					<< std::endl;
		msg = std::string ("mitosis aborted").substr( 0, 16 );
			return ( false );
	}

	_outfile.open( _file_name.append( ".replace" ).c_str() );

	if ( _outfile.good() == false )
	{
		std::cout	<< "error: couldn't open "
					<< _file_name
					<< std::endl;
		msg = std::string ("mitosis aborted").substr( 0, 16 );
			return ( false );
	}

	return ( true );
}

void	Mitosis::mutating( std::string &dna )
{
	std::size_t	pos;
	std::size_t	prev_pos;

	prev_pos = 0;
	while ( (pos = dna.find( _s1, prev_pos )) != std::string::npos )
	{
		prev_pos = pos + _s2.length();
		dna.erase( pos, _s1.length() );
		dna.insert( pos, _s2 );
	}
}

void	Mitosis::mitosing( void )
{
	std::string	dna;

	if ( !dsa() )
		return ;

	std::getline( _infile, dna, '\0' );

	mutating( dna );

	_outfile << dna;

	msg = std::string ("mitosis complete").substr( 0, 17 );

	_infile.close();
	_outfile.close();
}
