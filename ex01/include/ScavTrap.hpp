/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:55:38 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/03 12:44:14 by vpoka            ###   ########.fr       */
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

	void	attack(std::string const &target);
};

std::ostream	&operator<<(std::ostream &os, ScavTrap const &st);

#endif
