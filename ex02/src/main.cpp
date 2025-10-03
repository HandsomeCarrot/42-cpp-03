/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:36:26 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/03 16:55:50 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "===ClapTrap===" << std::endl;
	ClapTrap ct("ct");
	ct.takeDamage(ct.getHitPoints());

	std::cout << std::endl;

	std::cout << "===ScavTrap===" << std::endl;
	ScavTrap st("st");
	st.guardGate();

	std::cout << std::endl;

	std::cout << "===FragTrap===" << std::endl;
	FragTrap ft("ft");
	ft.highFivesGuys();

	std::cout << std::endl;
	std::cout << "===Deconstruct===" << std::endl;

	return (0);
}
