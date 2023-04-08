/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 17:40:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void	checkUp(ClapTrap& inst)
{
	std::cout << "CHECK UP : " << inst.getName() << " : " << inst.getHit() << " Hit points, "
		<< inst.getEnergy() << " Energy points, "
		<< inst.getAttackDamage() << " AttackDamage" << std::endl;
}

void	testClapTrap(void)
{
	{
		ClapTrap unknown;
		checkUp(unknown);
	}
	std::cout << std::endl;
	{
		ClapTrap axel("Axel");
		checkUp(axel);
	}
	std::cout << std::endl;
	{
		ClapTrap boris("Boris");
		ClapTrap clone(boris);
		checkUp(clone);
	}
	std::cout << std::endl;
	{
		ClapTrap david("David");
		ClapTrap fake = david;
		checkUp(fake);
	}
	std::cout << std::endl;
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
	std::cout << std::endl;
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
	std::cout << std::endl;
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

void	testScavTrap(void)
{
	{
		ScavTrap unknown;
		checkUp(unknown);
	}
	std::cout << std::endl;
	{
		ScavTrap axel("Axel");
		checkUp(axel);
	}
	std::cout << std::endl;
	{
		ScavTrap boris("Boris");
		ScavTrap clone(boris);
		checkUp(clone);
	}
	std::cout << std::endl;
	{
		ScavTrap david("David");
		ScavTrap fake = david;
		checkUp(fake);
	}
	std::cout << std::endl;
	{
		ScavTrap eric("Eric");
		checkUp(eric);
		eric.guardGate();
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
		eric.guardGate();
		checkUp(eric);
	}
	std::cout << std::endl;
	{
		ScavTrap fary("Fary");
		checkUp(fary);
		fary.attack("target");
		checkUp(fary);
		fary.takeDamage(0);
		checkUp(fary);
		fary.beRepaired(5);
		checkUp(fary);
		fary.guardGate();
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
		fary.guardGate();
		checkUp(fary);
	}
	std::cout << std::endl;
	{
		ScavTrap guile("Guile");
		checkUp(guile);
		guile.attack("target");
		checkUp(guile);
		guile.guardGate();
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
		guile.guardGate();
		checkUp(guile);
	}
}

int main( void )
{
	// testClapTrap();
	testScavTrap();
	return (0);
}
