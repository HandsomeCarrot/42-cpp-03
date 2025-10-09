/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:55:21 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/09 17:43:07 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * @brief Default constructor for ScavTrap.
 *
 * Constructs a ScavTrap with default name "noname", default ScavTrap
 * hit points, default ScavTrap energy points, and default ScavTrap
 * attack damage. Outputs a construction message to standard output.
 */
ScavTrap::ScavTrap(void) :
	ClapTrap("noname", DefaultHitPoints, DefaultEnergyPoints, DefaultAttackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Constructs a ScavTrap with specified name.
 *
 * Constructs a ScavTrap with the provided name, default ScavTrap
 * hit points, default ScavTrap energy points, and default ScavTrap
 * attack damage. Outputs a construction message to standard output.
 *
 * @param name The string identifier for this ScavTrap instance.
 */
ScavTrap::ScavTrap(std::string name) :
	ClapTrap(name, DefaultHitPoints, DefaultEnergyPoints, DefaultAttackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Constructs a ScavTrap with full attribute specification.
 *
 * Constructs a ScavTrap with the specified name, hit points, energy
 * points, and attack damage. Outputs a construction message to
 * standard output.
 *
 * @param name The string identifier for this ScavTrap instance.
 * @param hitPoints The initial hit points value.
 * @param energyPoints The initial energy points value.
 * @param attackDamage The initial attack damage value.
 */
ScavTrap::ScavTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) :
	ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Copy constructor for ScavTrap.
 *
 * Creates a new ScavTrap as a copy of an existing one by calling
 * the base class copy constructor. Outputs a copy construction
 * message to standard output.
 *
 * @param other The ScavTrap object to copy from.
 */
ScavTrap::ScavTrap(ScavTrap const &other) :
	ClapTrap(other)
{
	std::cout << "copy constructed " << *this << std::endl;
}

/**
 * @brief Destructor for ScavTrap.
 *
 * Outputs a deconstruction message to standard output containing
 * the ScavTrap's name before the object is destroyed.
 */
ScavTrap::~ScavTrap(void)
{
	std::cout << "deconstructed " << *this << std::endl;
}

/**
 * @brief Performs an attack on a specified target.
 *
 * Initiates an attack action against the named target, consuming one
 * energy point. If successful, outputs an attack message indicating
 * the target and damage dealt. The attack fails if the ScavTrap is
 * dead or has no energy points remaining.
 *
 * @param target A constant reference to a string representing the name
 *               of the target being attacked.
 */
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

/**
 * @brief Activates gate keeper mode for the ScavTrap.
 *
 * Puts the ScavTrap into a special defensive state where it guards
 * a gate. Outputs a message indicating the mode change to standard
 * output. This action does not consume energy points.
 */
void	ScavTrap::guardGate(void)
{
	std::cout << *this << " is now in gate keeper mode" << std::endl;
}

/**
 * @brief Outputs the ScavTrap to an output stream.
 *
 * Inserts a formatted representation of the ScavTrap (including its
 * name) into the provided output stream. This allows ScavTrap objects
 * to be easily printed using standard stream operations.
 *
 * @param os A reference to the output stream to write to.
 * @param st A constant reference to the ScavTrap object to output.
 * @return A reference to the output stream after writing.
 */
std::ostream	&operator<<(std::ostream &os, ScavTrap const &st)
{
	os << "ScavTrap " << st.getName();
	return (os);
}
