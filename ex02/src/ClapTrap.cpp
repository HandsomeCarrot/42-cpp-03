/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:34 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/03 13:23:58 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * @brief Constructs a ClapTrap object with default values.
 *
 * Initializes a ClapTrap instance with the default name "noname",
 * 10 hit points, 10 energy points, and 0 attack damage. Outputs a
 * construction message to standard output.
 */
ClapTrap::ClapTrap(void) :
	m_name("noname"),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Constructs a ClapTrap object with a specified name.
 *
 * Initializes a ClapTrap instance with the provided name, 10 hit
 * points, 10 energy points, and 0 attack damage. Outputs a
 * construction message to standard output.
 *
 * @param name The string representing the name of the ClapTrap
 *             instance.
 */
ClapTrap::ClapTrap(std::string name) :
	m_name(name),
	m_hitPoints(10),
	m_energyPoints(10),
	m_attackDamage(0)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Constructs a ClapTrap object with the specified attributes.
 *
 * Initializes the ClapTrap with a given name, hit points, energy points, and attack damage.
 * Outputs a message to the standard output indicating the construction of the object.
 *
 * @param name The name of the ClapTrap.
 * @param hitPoints The initial hit points of the ClapTrap.
 * @param energyPoints The initial energy points of the ClapTrap.
 * @param attackDamage The attack damage value of the ClapTrap.
 */
ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) :
	m_name(name),
	m_hitPoints(hitPoints),
	m_energyPoints(energyPoints),
	m_attackDamage(attackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Copy constructor for the ClapTrap class.
 *
 * Creates a new ClapTrap object as a copy of an existing one.
 * Copies the name, hit points, energy points, and attack damage from the source object.
 *
 * @param other The ClapTrap object to copy from.
 */
ClapTrap::ClapTrap(ClapTrap const &other) :
	m_name(other.getName()),
	m_hitPoints(other.getHitPoints()),
	m_energyPoints(other.getEnergyPoints()),
	m_attackDamage(other.getAttackDamage())
{
	std::cout << "copy constructed " << *this << std::endl;
}

/**
 * @brief Destroys the ClapTrap object.
 *
 * Outputs a deconstruction message to standard output containing
 * the ClapTrap's name before the object is destroyed.
 */
ClapTrap::~ClapTrap(void)
{
	std::cout << "deconstructed " << *this << std::endl;
}

/**
 * @brief Assignment operator overload for ClapTrap.
 *
 * Copies the state of another ClapTrap object into this one by assigning
 * the name, hit points, energy points, and attack damage from the source object.
 *
 * @param other The ClapTrap object to copy from.
 * @return Reference to the assigned ClapTrap object (*this).
 */
ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	return (*this);
}

/**
 * @brief Retrieves the name of the ClapTrap.
 *
 * @return A string containing the name of this ClapTrap instance.
 */
std::string	ClapTrap::getName(void) const
{
	return (m_name);
}

/**
 * @brief Retrieves the current hit points of the ClapTrap.
 *
 * @return An unsigned integer representing the current hit points
 *         remaining for this ClapTrap instance.
 */
unsigned int	ClapTrap::getHitPoints(void) const
{
	return (m_hitPoints);
}

/**
 * @brief Retrieves the current energy points of the ClapTrap.
 *
 * @return An unsigned integer representing the current energy points
 *         available for this ClapTrap instance.
 */
unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (m_energyPoints);
}

/**
 * @brief Retrieves the attack damage value of the ClapTrap.
 *
 * @return An unsigned integer representing the amount of damage this
 *         ClapTrap deals when attacking.
 */
unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (m_attackDamage);
}

/**
 * @brief Sets the name of the ClapTrap.
 *
 * @param name The new string name to assign to this ClapTrap instance.
 */
void	ClapTrap::setName(std::string name)
{
	m_name = name;
}

/**
 * @brief Sets the hit points of the ClapTrap.
 *
 * @param amount The new unsigned integer value for the hit points of
 *               this ClapTrap instance.
 */
void	ClapTrap::setHitPoints(unsigned int amount)
{
	m_hitPoints = amount;
}

/**
 * @brief Sets the energy points of the ClapTrap.
 *
 * @param amount The new unsigned integer value for the energy points
 *               of this ClapTrap instance.
 */
void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	m_energyPoints = amount;
}

/**
 * @brief Sets the attack damage of the ClapTrap.
 *
 * @param amount The new unsigned integer value for the attack damage
 *               of this ClapTrap instance.
 */
void	ClapTrap::setAttackDamage(unsigned int amount)
{
	m_attackDamage = amount;
}

/**
 * @brief Performs an attack on a specified target.
 *
 * Initiates an attack action against the named target, consuming one
 * energy point. If successful, outputs an attack message indicating
 * the target and damage dealt. The attack fails if the ClapTrap is
 * dead or has no energy points remaining.
 *
 * @param target A constant reference to a string representing the name
 *               of the target being attacked.
 */
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

/**
 * @brief Applies damage to the ClapTrap.
 *
 * Reduces the ClapTrap's hit points by the specified amount. If the
 * damage exceeds current hit points, hit points are set to zero. This
 * function does nothing if the ClapTrap is already dead. Outputs a
 * message indicating the damage taken and remaining hit points.
 *
 * @param amount An unsigned integer representing the amount of damage
 *               to apply to this ClapTrap instance.
 */
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

/**
 * @brief Repairs the ClapTrap, restoring hit points.
 *
 * Increases the ClapTrap's hit points by the specified amount,
 * consuming one energy point. The repair fails if the ClapTrap is
 * dead or has no energy points remaining. Outputs a message
 * indicating the amount repaired and total hit points.
 *
 * @param amount An unsigned integer representing the number of hit
 *               points to restore to this ClapTrap instance.
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int	healthPoints = getHitPoints();

	if (!takeAction())
		return;
	if (healthPoints + amount < amount)
		healthPoints = UINT_MAX;
	else
		healthPoints += amount;
	setHitPoints(healthPoints);
	std::cout << *this << " got repaired for "
	<< amount << " health points and has "
	<< healthPoints << " health points!" << std::endl;
}

/**
 * @brief Checks if the ClapTrap is dead.
 *
 * Determines whether the ClapTrap has zero hit points remaining. If
 * dead, outputs a message indicating this status.
 *
 * @return true if the ClapTrap has no hit points remaining, false
 *         otherwise.
 */
bool	ClapTrap::dead(void) const
{
	if (getHitPoints() > 0)
		return (false);
	std::cout << *this << " is already dead." << std::endl;
	return (true);
}

/**
 * @brief Checks if the ClapTrap has no energy points remaining.
 *
 * Determines whether the ClapTrap has zero energy points, preventing
 * it from performing actions. If out of energy, outputs a message
 * indicating this status.
 *
 * @return true if the ClapTrap has no energy points remaining, false
 *         otherwise.
 */
bool	ClapTrap::outOfEnergy(void) const
{
	if (getEnergyPoints() > 0)
		return (false);
	std::cout << *this << " is out of energy points!" << std::endl;
	return (true);
}

/**
 * @brief Attempts to perform an action, consuming energy if possible.
 *
 * Checks if the ClapTrap can perform an action by verifying it is not
 * dead and has energy points available. If both conditions are met,
 * consumes one energy point and returns success.
 *
 * @return true if the action can be performed and energy was consumed,
 *         false if the ClapTrap is dead or has no energy points.
 */
bool	ClapTrap::takeAction(void)
{
	if (dead() || outOfEnergy())
		return (false);
	setEnergyPoints(getEnergyPoints() - 1);
	return (true);
}

/**
 * @brief Outputs the ClapTrap to an output stream.
 *
 * Inserts a formatted representation of the ClapTrap (including its
 * name) into the provided output stream. This allows ClapTrap objects
 * to be easily printed using standard stream operations.
 *
 * @param os A reference to the output stream to write to.
 * @param ct A constant reference to the ClapTrap object to output.
 * @return A reference to the output stream after writing.
 */
std::ostream	&operator<<(std::ostream &os, ClapTrap const &ct)
{
	os << "ClapTrap " << ct.getName();
	return (os);
}
