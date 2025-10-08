/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:37 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/08 17:24:47 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>
# include <climits>

class ClapTrap
{
private:

	std::string	m_name;

	unsigned int	m_hitPoints; 
	unsigned int	m_energyPoints;
	unsigned int	m_attackDamage;

protected:

	unsigned int static const DefaultHitPoints = 10;
	unsigned int static const DefaultEnergyPoints = 10;
	unsigned int static const DefaultAttackDamage = 0;

	void	setHitPoints(unsigned int amount);
	void	setEnergyPoints(unsigned int amount);
	void	setAttackDamage(unsigned int amount);

public:

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
	ClapTrap(ClapTrap const &other);

	~ClapTrap(void);

	ClapTrap	&operator=(ClapTrap const &other);

	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	void	setName(std::string name);

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	bool	dead(void) const;
	bool	outOfEnergy(void) const;

	bool	takeAction(void);
};

std::ostream	&operator<<(std::ostream &os, ClapTrap const &ct);

#endif
