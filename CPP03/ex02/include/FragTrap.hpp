/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarieux <mlarieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:08:25 by mlarieux          #+#    #+#             */
/*   Updated: 2025/04/30 14:15:54 by mlarieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FragTRAP_HPP
# define FragTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>
#include <map>

class FragTrap : public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( const std::string Name );
	FragTrap( const FragTrap &original );
	~FragTrap( void );

	FragTrap &operator= ( const FragTrap &original );

	void	attack( const std::string &target );
	void	highFivesGuys( void );

private:

};

#endif