/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:30:49 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 17:56:25 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	setHit(100);
	setEnergy(100);
	setAttackDamage(30);
	std::cout << "FragTrap Constructor by default (whithout name) called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	setHit(100);
	setEnergy(100);
	setAttackDamage(30);
	std::cout << "FragTrap Constructor with name " << name << " specified called. Getname said : " << getName() << std::endl;
}

FragTrap::FragTrap(FragTrap const& source) : ClapTrap(source)
{
	std::string type = "FragTrap ";
	std::cout << type << "Constructor by copy of " << type << source.getName() << " called" << std::endl;
	*this = source;
}

FragTrap& FragTrap::operator=(FragTrap const& source)
{
	std::string type = "FragTrap ";
	std::cout << type << "Affectation Operator overloading from " << type << source.getName() << " called" << std::endl;
	if (this != &source)
		setName(source.getName());
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor of " << getName() << " called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (getHit() != 0)
		std::cout << "FragTrap " << getName() << " shouts << High Five Guys ! >>" << std::endl;
	else if (getHit() == 0)
		std::cout << "FragTrap " << getName() << " have " << getHit() << " Hit points. It cannot High Figh anyone !" << std::endl;
}

void	FragTrap::setHit(unsigned int hit)
{
	Hit = hit;
}

void	FragTrap::setEnergy(unsigned int energy)
{
	Energy = energy;
}

void	FragTrap::setAttackDamage(unsigned int attack)
{
	AttackDamage = attack;
}
