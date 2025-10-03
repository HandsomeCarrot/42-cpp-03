/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:31:23 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/03 13:28:33 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	// test 1: Basic attack and repair
	ScavTrap st1("st1");
	ScavTrap st2("st2");
	ScavTrap st3("st3");

	std::cout << std::endl;

	st1.attack(st2.getName());
	st2.takeDamage(st1.getAttackDamage());

	st2.beRepaired(5);

	std::cout << std::endl;

	// test 2: Energy consumption
	st1.attack(st2.getName());
	st1.attack(st2.getName());
	st1.attack(st2.getName());

	std::cout << std::endl;

	// test 3: Can't ast when dead
	st2.takeDamage(st2.getHitPoints()); // Should kill st2
	st2.attack(st1.getName());
	st2.beRepaired(10);

	std::cout << std::endl;

	// test 4: Can't act when out of energy
	while (!st3.outOfEnergy())
		st3.beRepaired(1);
	st3.takeDamage(st3.getHitPoints());

	std::cout << std::endl;

	//test 5: Copy dead ct and still can't act
	ScavTrap st4(st2);
	st4.setName("st4");
	st4.beRepaired(1);

	std::cout << std::endl;

	//test 6: assign dead ct and still can't act
	ScavTrap st5;
	st5 = st2;
	st5.setName("st5");
	st5.attack("you");

	std::cout << std::endl;

	//test 7: gate keeper mode
	st1.guardGate();

	std::cout << std::endl;

	return (0);
}
