/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:49:57 by vpoka             #+#    #+#             */
/*   Updated: 2025/10/02 11:28:49 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap k("koloman");
	ClapTrap h("hamza");

	k.attack(h.getName());
	h.takeDamage(0);
	h.attack(k.getName());
	k.takeDamage(20);
	k.beRepaired(10);
	return (0);
}
