/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:10:04 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/03 17:37:58 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap(),
	ScavTrap(),
	FragTrap()
{
	std::cout << "Diamond trap" << " constructed" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Diamond trap" << " deconstructed" << std::endl;
}
