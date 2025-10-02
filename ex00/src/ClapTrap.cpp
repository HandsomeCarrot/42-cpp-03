/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:34 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/02 16:07:43 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	m_name("noname"),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "constructed " << *this << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	m_name(name),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "constructed " << *this << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) :
	m_name(other.getName()),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "copy constructed " << *this << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "deconstructed " << *this << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	this->setName(other.getName());
	return (*this);
}

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

void	ClapTrap::attack(std::string const &target)
{
	unsigned int	attackDamage = this->getAttackDamage();

	if (!this->takeAction())
		return;
	std::cout << *this
	<< " attacks " << target
	<< ", causing " << attackDamage
	<< " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	healthPoints = getHitPoints();

	if (dead())
		return;
	else if (amount >= healthPoints)
		amount = healthPoints;
	setHitPoints(healthPoints - amount);
	std::cout << *this << " took "
	<< amount << " points of damage and now has "
	<< getHitPoints() << " health points!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	healthPoints = getHitPoints();

	if (!takeAction())
		return;
	healthPoints += amount;
	setHitPoints(healthPoints);
	std::cout << *this << " got repaired for "
	<< amount << " health points and has "
	<< healthPoints << " health points!" << std::endl;
}

bool	ClapTrap::dead(void) const
{
	if (getHitPoints() > 0)
		return (false);
	std::cout << *this << " is already dead." << std::endl;
	return (true);
}

bool	ClapTrap::outOfMana(void) const
{
	if (getEnergyPoints() > 0)
		return (false);
	std::cout << *this << " is out of energy points!" << std::endl;
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

