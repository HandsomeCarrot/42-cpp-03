/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:34 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 19:07:37 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	m_name("noname"),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{}

ClapTrap::ClapTrap(std::string name) :
	m_name(name),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{}

ClapTrap::~ClapTrap(void)
{}

std::string	ClapTrap::getName(void) const
{
	return (m_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (m_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (m_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (m_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	m_name = name;
}

void	ClapTrap::setHitPoints(unsigned int amount)
{
	m_hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	m_energyPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	m_attackDamage = amount;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	this->setName(other.getName());
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	unsigned int	attackDamage = this->getAttackDamage();

	if (!this->takeAction())
		return;
	std::cout << this
	<< " attacks " << target
	<< ", causing " << attackDamage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	healthPoints = getHitPoints();

	std::cout << this;

	if (dead())
		return;
	else if (amount >= healthPoints)
		amount = healthPoints;
	setHitPoints(healthPoints - amount);
	std::cout << " took " << amount
	<< " points of damage and now has "
	<< getHitPoints() << " health points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	healthPoints = getHitPoints();

	std::cout << this;

	if (!takeAction())
		return;
	healthPoints += amount;
	setHitPoints(healthPoints);
	std::cout << this << " got repaired for "
	<< amount << " health points and now has "
	<< healthPoints << " health points!" << std::endl;
}

bool	ClapTrap::dead(void) const
{
	if (getHitPoints() > 0)
		return (false);
	std::cout << this << " is already dead." << std::endl;
	return (true);
}

bool	ClapTrap::outOfMana(void) const
{
	if (getEnergyPoints() > 0)
		return (false);
	std::cout << this << " is out of energy points!" << std::endl;
	return (true);
}

bool	ClapTrap::takeAction(void)
{
	if (dead() || outOfMana())
		return (false);

	setEnergyPoints(getEnergyPoints() - 1);
	return (true);
}

std::ostream	&operator<<(std::ostream &os, ClapTrap const &ct)
{
	os << "ClapTrap " << ct.getName();
	return (os);
}
