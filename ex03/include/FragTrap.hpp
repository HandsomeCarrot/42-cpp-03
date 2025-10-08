/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:06:48 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/08 17:27:07 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:

	unsigned int static const	DefaultHitPoints = 100;
	unsigned int static const	DefaultEnergyPoints = 100;
	unsigned int static const	DefaultAttackDamage = 30;

public:

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
	FragTrap(FragTrap const &other);

	~FragTrap(void);

	void	highFivesGuys(void);
};

std::ostream	&operator<<(std::ostream &os, FragTrap const &st);

#endif
