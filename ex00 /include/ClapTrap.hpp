/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:37 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 18:43:15 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
private:

	std::string	m_name;

	unsigned int	m_hitPoints;
	unsigned int	m_energyPoints;
	unsigned int	m_attackDamage;

	void	setHitPoints(unsigned int amount) const;
	void	setEnergyPoints(unsigned int amount) const;
	void	setAttackDamage(unsigned int amount) const;

public:

	ClapTrap(void);
	ClapTrap(std::string name);

	~ClapTrap(void);

	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	void	setName(std::string &name) const;

	ClapTrap	&operator=(ClapTrap const &other);

	void	attack(std::string const &target) const;
	void	takeDamage(unsigned int amount) const;
	void	beRepaired(unsigned int amount) const;

	bool	dead(void);
	bool	outOfMana(void);
	bool	canTakeAction(void);
};

std::ostream	&operator<<(std::ostream &os, ClapTrap const &ct);

#endif
