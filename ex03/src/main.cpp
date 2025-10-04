/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:36:26 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/04 13:50:12 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap dt;

	std::cout << dt.getHitPoints() << " hit points" << std::endl;
	std::cout << dt.getEnergyPoints() << " energy points" << std::endl;
	std::cout << dt.getAttackDamage() << " attack damage" << std::endl;

	std::cout << std::endl;

	FragTrap	ft;

	std::cout << ft.getHitPoints() << " hit points" << std::endl;
	std::cout << ft.getEnergyPoints() << " energy points" << std::endl;
	std::cout << ft.getAttackDamage() << " attack damage" << std::endl;

	std::cout << std::endl;

	ScavTrap	st;

	std::cout << st.getHitPoints() << " hit points" << std::endl;
	std::cout << st.getEnergyPoints() << " energy points" << std::endl;
	std::cout << st.getAttackDamage() << " attack damage" << std::endl;

	std::cout << std::endl;

	ClapTrap	ct;

	std::cout << ct.getHitPoints() << " hit points" << std::endl;
	std::cout << ct.getEnergyPoints() << " energy points" << std::endl;
	std::cout << ct.getAttackDamage() << " attack damage" << std::endl;

	std::cout << std::endl;

	return (0);
}
