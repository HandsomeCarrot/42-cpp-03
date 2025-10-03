/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:57 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/03 13:23:58 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// test 1: Basic attack and repair
	ClapTrap ct1("ct1");
	ClapTrap ct2("ct2");
	ClapTrap ct3("ct3");

	std::cout << std::endl;

	ct1.attack(ct2.getName());
	ct2.takeDamage(ct1.getAttackDamage());

	ct2.beRepaired(5);

	std::cout << std::endl;

	// test 2: Energy consumption
	ct1.attack(ct2.getName());
	ct1.attack(ct2.getName());
	ct1.attack(ct2.getName());

	std::cout << std::endl;

	// test 3: Can't act when dead
	ct2.takeDamage(ct2.getHitPoints());
	ct2.attack(ct1.getName());
	ct2.beRepaired(10);

	std::cout << std::endl;

	// test 4: Can't act when out of energy
	while (!ct3.outOfEnergy())
		ct3.beRepaired(1);
	ct3.takeDamage(ct3.getHitPoints());

	std::cout << std::endl;

	//test 5: Copy dead ct and still can't act
	ClapTrap ct4(ct2);
	ct4.setName("ct4");
	ct4.beRepaired(1);

	std::cout << std::endl;

	//test 6: assign dead ct and still can't act
	ClapTrap ct5;
	ct5 = ct2;
	ct5.setName("ct5");
	ct5.attack("you");

	std::cout << std::endl;

	return (0);
}
