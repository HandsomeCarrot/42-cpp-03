/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:55:38 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/02 18:25:31 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
	ScavTrap(ScavTrap const &other);

	~ScavTrap(void);

	ScavTrap	&operator=(ScavTrap const &other);
};

std::ostream	&operator<<(std::ostream &os, ScavTrap const &st);

#endif
