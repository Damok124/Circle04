/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:34 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 17:02:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	setHit(100);
	setEnergy(50);
	setAttackDamage(20);
	std::cout << "ScavTrap Constructor by default (whithout name) called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	setHit(100);
	setEnergy(50);
	setAttackDamage(20);
	std::cout << "ScavTrap Constructor with name " << name << " specified called. Getname said : " << getName() << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& source) : ClapTrap(source)
{
	std::string type = "ScavTrap ";
	std::cout << type << "Constructor by copy of " << type << source.getName() << " called" << std::endl;
	*this = source;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& source)
{
	std::string type = "ScavTrap ";
	std::cout << type << "Affectation Operator overloading from " << type << source.getName() << " called" << std::endl;
	if (this != &source)
		setName(source.getName());
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor of " << getName() << " called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (getHit() != 0)
		std::cout << Name << " is now in Gate keeper mode" << std::endl;
	else if (getHit() == 0)
		std::cout << "ClapTrap " << getName() << " have " << getHit() << " Hit points. It can't keep the gate !" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getHit() != 0 && getEnergy() != 0)
	{
		if (getEnergy() - 1 < getEnergy())
			setEnergy(getEnergy() - 1);
		else
			setEnergy(0);
		std::cout << "ScavTrap " << getName() << " scavenges " << target <<
			", causing " << getAttackDamage() << " points of damage! Remaining " << getEnergy() << " energy points." << std::endl;
	}
	else if (getHit() == 0)
		std::cout << "ScavTrap " << getName() << " have " << getHit() << " Hit points. It can't scavenge !" << std::endl;
	else if (getEnergy() == 0)
		std::cout << "ScavTrap " << getName() << " have " << getEnergy() << " Energy points. It can't scavenge !" << std::endl;
}

void	ScavTrap::setHit(unsigned int hit)
{
	Hit = hit;
}

void	ScavTrap::setEnergy(unsigned int energy)
{
	Energy = energy;
}

void	ScavTrap::setAttackDamage(unsigned int attack)
{
	AttackDamage = attack;
}
