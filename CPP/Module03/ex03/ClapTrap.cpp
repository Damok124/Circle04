/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/05 17:22:52 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("NoName"), Hit(10), Energy(10), Attack(0)
{
	std::cout << "ClapTrap Constructor by default called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): Name(name), Hit(10), Energy(10), Attack(0)
{
	std::cout << "ClapTrap Constructor with name specified called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& source)
{
	std::cout << "ClapTrap Constructor by copy called" << std::endl;
	*this = source;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& source)
{
	std::cout << "ClapTrap Affectation operator overloading called" << std::endl;
	if (this != &source)
		setName(source.Name);
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
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

int		ClapTrap::getAttack(void) const
{
	return (Attack);
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

void	ClapTrap::setAttack(int attack)
{
	Attack = attack;
}

void	ClapTrap::attack(const std::string& target)
{
	if (getHit() != 0 && getEnergy() != 0)
	{
		std::cout << "ClapTrap " << getName() << " attacks " << target <<
			", causing " << getAttack() << " points of damage!" << std::endl;
		setEnergy(getEnergy() - 1);
	}
	else if (getHit() == 0)
		std::cout << "ClapTrap " << getName() << " is totally broken. It can't move!" << std::endl;
	else if (getEnergy() == 0)
		std::cout << "ClapTrap " << getName() << " have no more energy, it can't move! " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
		setHit(getHit() - amount);
		if (getHit() < 0)
			setHit(0);
		std::cout << "ClapTrap " << getName() << " has taken " << amount <<
			" points of damage! It's very effective!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getHit() != 0 && getEnergy() != 0)
	{
		setHit(getHit() + amount);
		setEnergy(getEnergy() - 1);
		std::cout << "ClapTrap " << getName() << " repairs itself! Healed with "
			<< amount << " points!" << std::endl;
	}
	else if (getHit() == 0)
		std::cout << "ClapTrap " << getName() << " is totally broken. It can't move!" << std::endl;
	else if (getEnergy() == 0)
		std::cout << "ClapTrap " << getName() << " have no more energy, it can't move! " << std::endl;
}
