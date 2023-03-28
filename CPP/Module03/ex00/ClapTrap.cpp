/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/28 17:13:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("NoName"), Hit(10), Energy(10), Attack(0)
{
	std::cout << "Constructor by default called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): Name(name), Hit(10), Energy(10), Attack(0)
{
	std::cout << "Constructor with name specified called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& source)
{
	std::cout << "Constructor by copy called" << std::endl;
	*this = source;
	return ;/////////////////////////////////////////////////////////
}

ClapTrap& ClapTrap::operator=(ClapTrap const& source)
{
	std::cout << "Affectation operator overloading called" << std::endl;
	if (this != &source)
	{
		Name = source.Name;
		Hit = source.Hit;
		Energy = source.Energy;
		Attack = source.Attack;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
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
{// Quand ClapTrap attaque, sa cible perd <attack damage> hit points.
// Les actions attaquer et rÃ©parer coÃ»tent chacune 1 point dâ€™Ã©nergie.

	if (getHit() != 0 && getEnergy() != 0)
	{
		(void)target;
		std::cout << "ClapTrap <name> attacks <target>, causing <damage> points of damage!" << std::endl;
	}
}
// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ClapTrap canâ€™t do anything if it has no hit points
// or energy points left.
void	ClapTrap::takeDamage(unsigned int amount)
{


	if (getHit() != 0 && getEnergy() != 0)
	{
		(void)amount;
		std::cout << "takeDamage" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getHit() != 0 && getEnergy() != 0)
	{
		setHit(getHit() + amount);
		setEnergy(getEnergy() - 1);
		std::cout << "beRepaired" << std::endl;
	}
}

// Implement and turn in your own tests to ensure your code works as expected.
