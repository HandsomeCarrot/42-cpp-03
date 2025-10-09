/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:36:26 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/09 16:28:09 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap dt;

	std::cout << std::endl;

	dt.whoAmI();

	std::cout << std::endl;

	std::cout << dt.getHitPoints() << " hit points" << std::endl;
	std::cout << dt.getEnergyPoints() << " energy points" << std::endl;
	std::cout << dt.getAttackDamage() << " attack damage" << std::endl;
	
	std::cout << std::endl;
	
	dt.attack("someone");
	dt.guardGate();
	dt.highFivesGuys();

	std::cout << std::endl;

	return (0);
}
