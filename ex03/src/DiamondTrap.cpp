/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:10:04 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/08 17:35:28 by vpoka            ###   ########.fr       */
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
	std::cout << "Diamond trap " << m_name << " constructed" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Diamond trap" << " deconstructed" << std::endl;
}
