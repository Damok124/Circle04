/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:34 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/05 20:23:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("NoName_clap_name"), ScavTrap("NoName"), FragTrap("NoName")
{
	FragTrap::setHit(100);
	ScavTrap::setEnergy(50);
	FragTrap::setAttack(30);
	std::cout << "DiamondTrap Constructor by default called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	FragTrap::setHit(100);
	ScavTrap::setEnergy(50);
	FragTrap::setAttack(30);
	std::cout << "DiamondTrap Constructor with name called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& source): ClapTrap("NoName_clap_name"), ScavTrap("NoName"), FragTrap("NoName")
{
	std::cout << "DiamondTrap Constructor by copy called" << std::endl;
	*this = source;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& source)
{
	std::cout << "DiamondTrap Affectation operator overloading called" << std::endl;
	if (this != &source)
		DiamondTrap::setName(source.Name);
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void	DiamondTrap::setName(std::string name)
{
	Name = name;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My true name is " << getName() << " but my ClapName is " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (Name);
}
