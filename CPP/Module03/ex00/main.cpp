/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 17:04:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

void	checkUp(ClapTrap& inst)
{
	std::cout << "CHECK UP : " << inst.getName() << " : " << inst.getHit() << " Hit points, "
		<< inst.getEnergy() << " Energy points, "
		<< inst.getAttackDamage() << " AttackDamage" << std::endl << std::endl;
}

void	testClapTrap(void)
{
	{
		ClapTrap unknown;
		checkUp(unknown);
	}
	{
		ClapTrap axel("Axel");
		checkUp(axel);
	}
	{
		ClapTrap boris("Boris");
		ClapTrap clone(boris);
		checkUp(clone);
	}
	{
		ClapTrap david("David");
		ClapTrap fake = david;
		checkUp(fake);
	}
	{
		ClapTrap eric("Eric");
		checkUp(eric);
		eric.attack("target");
		checkUp(eric);
		eric.takeDamage(0);
		checkUp(eric);
		eric.beRepaired(5);
		checkUp(eric);
		while (eric.getHit() != 0 && eric.getEnergy() != 0)
		{
			eric.attack("target");
			checkUp(eric);
		}
		eric.attack("target");
		checkUp(eric);
		eric.takeDamage(0);
		checkUp(eric);
		eric.beRepaired(-1);
		checkUp(eric);
	}
	{
		ClapTrap fary("Fary");
		checkUp(fary);
		fary.attack("target");
		checkUp(fary);
		fary.takeDamage(0);
		checkUp(fary);
		fary.beRepaired(5);
		checkUp(fary);
		while (fary.getHit() != 0 && fary.getEnergy() != 0)
		{
			fary.takeDamage(1);
			checkUp(fary);
		}
		fary.attack("target");
		checkUp(fary);
		fary.takeDamage(0);
		checkUp(fary);
		fary.beRepaired(-1);
		checkUp(fary);
	}
	{
		ClapTrap guile("Guile");
		checkUp(guile);
		guile.attack("target");
		checkUp(guile);
		guile.takeDamage(0);
		checkUp(guile);
		guile.beRepaired(5);
		checkUp(guile);
		while (guile.getEnergy() != 0)
		{
			guile.beRepaired(1000000000);
			checkUp(guile);
		}
		guile.attack("target");
		checkUp(guile);
		guile.takeDamage(0);
		checkUp(guile);
		guile.beRepaired(-1);
		checkUp(guile);
	}
}

int main( void )
{
	testClapTrap();
	return (0);
}
