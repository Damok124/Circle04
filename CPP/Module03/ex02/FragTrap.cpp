/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:30:49 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/01 08:48:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("NoName")
{
	Hit = 100;
	Energy = 100;
	Attack = 30;
	std::cout << "FragTrap Constructor by default called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	Hit = 100;
	Energy = 100;
	Attack = 30;
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
	{
		Name = source.Name;
		Hit = source.Hit;
		Energy = source.Energy;
		Attack = source.Attack;
	}
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
