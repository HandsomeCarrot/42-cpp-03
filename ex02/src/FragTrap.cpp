/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:07:48 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/03 17:03:44 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) :
	ClapTrap("noname", 100, 100, 30)
{
	std::cout << "constructed " << *this << std::endl;
}

FragTrap::FragTrap(std::string name) :
	ClapTrap(name, 100, 100, 30)
{
	std::cout << "constructed " << *this << std::endl;
}

FragTrap::FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage) :
	ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	std::cout << "constructed " << *this << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) :
	ClapTrap(other)
{
	std::cout << "copy constructed " << *this << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "deconstructed " << *this << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << *this << " wants to high-five!" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, FragTrap const &st)
{
	os << "FragTrap " << st.getName();
	return (os);
}
