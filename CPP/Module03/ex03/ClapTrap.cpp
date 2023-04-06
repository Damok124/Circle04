/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/06 17:46:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("NoName"), Hit(10), Energy(10), AttackDamage(0)
{
	std::cout << "ClapTrap Constructor by default (whithout name) called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): Name(name), Hit(10), Energy(10), AttackDamage(0)
{
	std::cout << "ClapTrap Constructor with name " << name << " specified called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& source)
{
	std::cout << "ClapTrap Constructor by copy of ClapTrap " << source.getName() << " called" << std::endl;
	*this = source;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& source)
{
	std::cout << "ClapTrap Affectation Operator overloading from ClapTrap " << source.getName() << " called" << std::endl;
	if (this != &source)
		setName(source.getName());
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor of " << getName() << " called" << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (Name);
}

int		ClapTrap::getHit(void) const
{
	return (Hit);
}

int		ClapTrap::getEnergy(void) const
{
	return (Energy);
}

int		ClapTrap::getAttackDamage(void) const
{
	return (AttackDamage);
}

void	ClapTrap::setName(std::string name)
{
	Name = name;
}

void	ClapTrap::setHit(int hit)
{
	Hit = hit;
}

void	ClapTrap::setEnergy(int energy)
{
	Energy = energy;
}

void	ClapTrap::setAttackDamage(int attack)
{
	AttackDamage = attack;
}

void	ClapTrap::attack(const std::string& target)
{
	if (getHit() != 0 && getEnergy() != 0)
	{
		setEnergy(getEnergy() - 1);
		if (getEnergy() < 0)
			setEnergy(0);
		std::cout << "ClapTrap " << getName() << " attacks " << target <<
			", causing " << getAttackDamage() << " points of damage! Remaining " << getEnergy() << " energy points." << std::endl;
	}
	else if (getHit() == 0)
		std::cout << "ClapTrap " << getName() << " have " << getHit() << " Hit points. It can't attack !" << std::endl;
	else if (getEnergy() == 0)
		std::cout << "ClapTrap " << getName() << " have " << getEnergy() << " Energy points. It can't attack !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
		setHit(getHit() - amount);
		if (getHit() < 0)
			setHit(0);
		std::cout << "ClapTrap " << getName() << " has taken " << amount << " points of damage! It remains " << getHit() << " Hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getHit() != 0 && getEnergy() != 0)
	{
		setHit(getHit() + amount);
		setEnergy(getEnergy() - 1);
		std::cout << "ClapTrap " << getName() << " repairs itself by " << amount << " points! It remains " << getHit() << " Hit points." << std::endl;
	}
	else if (getHit() == 0)
		std::cout << "ClapTrap " << getName() << " have " << getHit() << " Hit points. It can't heal !" << std::endl;
	else if (getEnergy() == 0)
		std::cout << "ClapTrap " << getName() << " have " << getEnergy() << " Energy points. It can't heal !" << std::endl;
}
