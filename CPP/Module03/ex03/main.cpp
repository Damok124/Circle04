/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 00:56:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	testClapTrap(void)
{
	// ClapTrap unknown;
	// ClapTrap clovis("Clovis");
	// ClapTrap chloe("Chloe");
	// ClapTrap fake_clovis(clovis);
	// unknown = chloe;
}

void	testFragTrap(void)
{

}

void	testScavTrap(void)
{

}

void	testDiamondTrap(void)
{
	DiamondTrap unknown;
	DiamondTrap boris("Boris");
	DiamondTrap fakeboris(boris);
	unknown = boris;
	fakeboris.attack("Alix");
	fakeboris.takeDamage(5);
	fakeboris.takeDamage(5);
	fakeboris.beRepaired(5);
	fakeboris.takeDamage(5);
	fakeboris.beRepaired(5);
	boris.attack("Ben");
	boris.beRepaired(1000000);
	boris.beRepaired(0);
	boris.beRepaired(1);
	boris.beRepaired(-1);
	boris.beRepaired(4294967295);
	boris.beRepaired(10);
	boris.beRepaired(10);
	boris.beRepaired(10);
	boris.beRepaired(10);
	boris.beRepaired(10);
	boris.beRepaired(10);
	boris.beRepaired(10);
	unknown.attack("Carl");
	unknown.attack("Dany");
	unknown.attack("Emma");
	unknown.attack("Fidel");
	unknown.attack("Gustavo");
	unknown.attack("Helene");
	unknown.attack("Ianis");
	unknown.attack("Jose");
	unknown.attack("Kennedy");
	unknown.beRepaired(15);
	unknown.attack("Leonardo");
	unknown.attack("Mael");
	unknown.attack("Nestor");
	fakeboris.takeDamage(5000);
	fakeboris.beRepaired(5);
	boris.highFivesGuys();
	fakeboris.highFivesGuys();
	unknown.highFivesGuys();
	boris.whoAmI();
	fakeboris.whoAmI();
	unknown.whoAmI();
}

int main( void )
{
	testClapTrap();
	testFragTrap();
	testScavTrap();
	testDiamondTrap();
	return (0);
}
