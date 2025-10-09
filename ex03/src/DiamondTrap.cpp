/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:10:04 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/09 16:18:35 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	m_name(name)
{
	this->setHitPoints(FragTrap::DefaultHitPoints);
	this->setEnergyPoints(ScavTrap::DefaultEnergyPoints);
	this->setAttackDamage(FragTrap::DefaultAttackDamage);
	std::cout << *this << " constructed" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << *this << " deconstructed" << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (this->m_name);
}

std::ostream	&operator<<(std::ostream &os, DiamondTrap const &dt)
{
	os << "DiamondTrap " << dt.getName();
	return (os);
}
