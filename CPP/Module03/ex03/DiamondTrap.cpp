/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:34 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 18:00:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	Name = "NoName";
	ClapTrap::setName(getName() + "_clap_name");
	FragTrap::setHit(100);
	ScavTrap::setEnergy(50);
	FragTrap::setAttackDamage(30);
	std::cout << "DiamTrap Constructor by default (whithout name) called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	Name = name;
	FragTrap::setHit(100);
	ScavTrap::setEnergy(50);
	FragTrap::setAttackDamage(30);
	std::cout << "DiamTrap Constructor with name " << name << " specified called. Getname said : " << getName() << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& source): ClapTrap(source.getName() + "_clap_name"), ScavTrap(source.getName()), FragTrap(source.getName())
{
	std::string type = "DiamTrap ";
	std::cout << type << "Constructor by copy of " << type << source.getName() << " called" << std::endl;
	*this = source;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& source)
{
	std::string type = "DiamTrap ";
	std::cout << type << "Affectation Operator overloading from " << type << source.getName() << " called" << std::endl;
	if (this != &source)
		setName(source.getName());
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamTrap Destructor of " << getName() << " called" << std::endl;
}

void	DiamondTrap::setName(std::string name)
{
	Name = name;
}

std::string	DiamondTrap::getName(void) const
{
	return (Name);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My true name is " << getName() << " and my ClapName is " << ClapTrap::getName() << std::endl;
}
