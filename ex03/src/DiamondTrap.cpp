/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:10:04 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/09 17:45:58 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * @brief Constructs a DiamondTrap with specified name.
 *
 * Constructs a DiamondTrap that inherits from both ScavTrap and
 * FragTrap. The DiamondTrap uses a combination of attributes from
 * both parent classes: FragTrap's hit points and attack damage,
 * and ScavTrap's energy points. The ClapTrap base name is set to
 * the provided name with "_clap_name" suffix.
 *
 * @param name The string identifier for this DiamondTrap instance.
 *             Defaults to "noname" if not provided.
 */
DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	m_name(name)
{
	this->setHitPoints(FragTrap::DefaultHitPoints);
	this->setEnergyPoints(ScavTrap::DefaultEnergyPoints);
	this->setAttackDamage(FragTrap::DefaultAttackDamage);
	std::cout << *this << " constructed" << std::endl;
}

/**
 * @brief Destructor for DiamondTrap.
 *
 * Outputs a deconstruction message to standard output containing
 * the DiamondTrap's name before the object is destroyed.
 */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << *this << " deconstructed" << std::endl;
}

/**
 * @brief Retrieves the name of the DiamondTrap.
 *
 * Returns the DiamondTrap's specific name, which is different from
 * the ClapTrap base name that has "_clap_name" suffix.
 *
 * @return The string name of this DiamondTrap instance.
 */
std::string	DiamondTrap::getName(void) const
{
	return (this->m_name);
}

/**
 * @brief Displays identity information for the DiamondTrap.
 *
 * Outputs a message showing both the DiamondTrap's name and its
 * ClapTrap base name, demonstrating the diamond inheritance
 * relationship and name resolution.
 */
void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << *this << " and " << (ClapTrap &)*this << std::endl;
}

/**
 * @brief Outputs the DiamondTrap to an output stream.
 *
 * Inserts a formatted representation of the DiamondTrap (including its
 * name) into the provided output stream. This allows DiamondTrap objects
 * to be easily printed using standard stream operations.
 *
 * @param os A reference to the output stream to write to.
 * @param dt A constant reference to the DiamondTrap object to output.
 * @return A reference to the output stream after writing.
 */
std::ostream	&operator<<(std::ostream &os, DiamondTrap const &dt)
{
	os << "DiamondTrap " << dt.getName();
	return (os);
}
