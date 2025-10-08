/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:55:21 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/08 17:29:46 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) :
	ClapTrap("noname", DefaultHitPoints, DefaultEnergyPoints, DefaultAttackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name, DefaultHitPoints, DefaultEnergyPoints, DefaultAttackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

ScavTrap::ScavTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) :
	ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) :
	ClapTrap(other)
{
	std::cout << "copy constructed " << *this << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "deconstructed " << *this << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	unsigned int	attackDamage = this->getAttackDamage();

	if (!this->takeAction())
		return;
	std::cout << *this
	<< " attacks " << target
	<< ", causing " << attackDamage
	<< " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << *this << " is now in gate keeper mode" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, ScavTrap const &st)
{
	os << "ScavTrap " << st.getName();
	return (os);
}
