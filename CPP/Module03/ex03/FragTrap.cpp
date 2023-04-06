/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:30:49 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 00:53:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("NoName")
{
	setHit(100);
	setEnergy(100);
	setAttackDamage(30);
	std::cout << "FragTrap Constructor by default called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	setHit(100);
	setEnergy(100);
	setAttackDamage(30);
	std::cout << "FragTrap Constructor with name specified called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& source) : ClapTrap(source)
{
	std::cout << "FragTrap Constructor by copy called" << std::endl;
	*this = source;
}

FragTrap& FragTrap::operator=(FragTrap const& source)
{
	std::cout << "FragTrap Affectation operator overloading called" << std::endl;
	if (this != &source)
		setName(source.Name);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (getHit() != 0)
	{
		std::cout << Name << " shouts << High Five Guys ! >>" << std::endl;
	}
	else if (getHit() == 0)
		std::cout << "ClapTrap " << getName() << " is totally broken. It cannot keep the gate!" << std::endl;
}

void	FragTrap::setHit(int hit)
{
	Hit = hit;
}

void	FragTrap::setEnergy(int energy)
{
	Energy = energy;
}

void	FragTrap::setAttackDamage(int attack)
{
	AttackDamage = attack;
}

void	FragTrap::attack(const std::string& target)
{
	if (getHit() != 0 && getEnergy() != 0)
	{
		setEnergy(getEnergy() - 1);
		if (getEnergy() < 0)
			setEnergy(0);
		std::cout << "FragTrap " << getName() << " frags " << target <<
			", causing " << getAttackDamage() << " points of damage! Remaining " << getEnergy() << " energy points." << std::endl;
	}
	else if (getHit() == 0)
		std::cout << "FragTrap " << getName() << " have " << getHit() << " Hit points. It can't frag !" << std::endl;
	else if (getEnergy() == 0)
		std::cout << "FragTrap " << getName() << " have " << getEnergy() << " Energy points. It can't frag !" << std::endl;
}
