/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:34 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/04 17:43:00 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("NoName")
{
	setHit(100);
	setEnergy(50);
	setAttack(20);
	std::cout << "ScavTrap Constructor by default called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	setHit(100);
	setEnergy(50);
	setAttack(20);
	std::cout << "ScavTrap Constructor with name specified called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& source) : ClapTrap(source)
{
	std::cout << "ScavTrap Constructor by copy called" << std::endl;
	*this = source;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& source)
{
	std::cout << "ScavTrap Affectation operator overloading called" << std::endl;
	if (this != &source)
	{
		ClapTrap::setName(source.Name);
		ClapTrap::setHit(source.Hit);
		ClapTrap::setEnergy(source.Energy);
		ClapTrap::setAttack(source.Attack);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	if (getHit() != 0)
	{
		std::cout << Name << " is now in Gate keeper mode" << std::endl;
	}
	else if (getHit() == 0)
		std::cout << "ClapTrap " << getName() << " is totally broken. It cannot keep the gate!" << std::endl;
}
