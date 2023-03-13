/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:21:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 17:46:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
}

HumanB::HumanB(std::string name)
{
	setName(name);
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

std::string const&	HumanB::getName(void) const
{
	return (name);
}

void	HumanB::setName(std::string name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (weapon)
		std::cout << this->getName() << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->getName() << " attacks with their two bare and callous hands" << std::endl;
}

