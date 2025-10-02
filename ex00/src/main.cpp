/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:57 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/02 21:20:20 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// test 1: Basic attack and repair
	ClapTrap robot1("Robot1");
	ClapTrap robot2("Robot2");
	ClapTrap robot3("Robot3");

	std::cout << std::endl;

	robot1.attack(robot2.getName());
	robot2.takeDamage(robot1.getAttackDamage());

	robot2.beRepaired(5);

	std::cout << std::endl;

	// test 2: Energy consumption
	robot1.attack(robot2.getName());
	robot1.attack(robot2.getName());
	robot1.attack(robot2.getName());

	std::cout << std::endl;

	// test 3: Can't act when dead
	robot2.takeDamage(20); // Should kill robot2
	robot2.attack(robot1.getName());
	robot2.beRepaired(10);

	std::cout << std::endl;

	// test 4: Can't act when out of energy
	for (size_t i = 0; i < 6; i++)
	{
		robot3.attack("no one");
		robot3.beRepaired(1);
	}
	robot3.takeDamage(15);

	std::cout << std::endl;

	return (0);
}
