/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:07:48 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/09 17:44:56 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * @brief Default constructor for FragTrap.
 *
 * Constructs a FragTrap with default name "noname", default FragTrap
 * hit points, default FragTrap energy points, and default FragTrap
 * attack damage. Outputs a construction message to standard output.
 */
FragTrap::FragTrap(void) :
	ClapTrap("noname", DefaultHitPoints, DefaultEnergyPoints, DefaultAttackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Constructs a FragTrap with specified name.
 *
 * Constructs a FragTrap with the provided name, default FragTrap
 * hit points, default FragTrap energy points, and default FragTrap
 * attack damage. Outputs a construction message to standard output.
 *
 * @param name The string identifier for this FragTrap instance.
 */
FragTrap::FragTrap(std::string name) :
	ClapTrap(name, DefaultHitPoints, DefaultEnergyPoints, DefaultAttackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Constructs a FragTrap with full attribute specification.
 *
 * Constructs a FragTrap with the specified name, hit points, energy
 * points, and attack damage. Outputs a construction message to
 * standard output.
 *
 * @param name The string identifier for this FragTrap instance.
 * @param hitPoints The initial hit points value.
 * @param energyPoints The initial energy points value.
 * @param attackDamage The initial attack damage value.
 */
FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) :
	ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

/**
 * @brief Copy constructor for FragTrap.
 *
 * Creates a new FragTrap as a copy of an existing one by calling
 * the base class copy constructor. Outputs a copy construction
 * message to standard output.
 *
 * @param other The FragTrap object to copy from.
 */
FragTrap::FragTrap(FragTrap const &other) :
	ClapTrap(other)
{
	std::cout << "copy constructed " << *this << std::endl;
}

/**
 * @brief Destructor for FragTrap.
 *
 * Outputs a deconstruction message to standard output containing
 * the FragTrap's name before the object is destroyed.
 */
FragTrap::~FragTrap(void)
{
	std::cout << "deconstructed " << *this << std::endl;
}

/**
 * @brief Requests a high-five from other entities.
 *
 * Outputs a message indicating that the FragTrap wants to perform
 * a high-five gesture. This action does not consume energy points
 * and can be performed regardless of the FragTrap's state.
 */
void	FragTrap::highFivesGuys(void)
{
	std::cout << *this << " wants to high-five!" << std::endl;
}

/**
 * @brief Outputs the FragTrap to an output stream.
 *
 * Inserts a formatted representation of the FragTrap (including its
 * name) into the provided output stream. This allows FragTrap objects
 * to be easily printed using standard stream operations.
 *
 * @param os A reference to the output stream to write to.
 * @param st A constant reference to the FragTrap object to output.
 * @return A reference to the output stream after writing.
 */
std::ostream	&operator<<(std::ostream &os, FragTrap const &st)
{
	os << "FragTrap " << st.getName();
	return (os);
}
