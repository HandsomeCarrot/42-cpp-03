/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:57 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/01 19:06:48 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{

	ClapTrap h = ClapTrap("Hamza");
	h.attack("r");
	h.takeDamage(20);
	h.beRepaired(10);
	return (0);
}
