/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:21:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/10 01:09:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{

}

HumanB::HumanB(std::string name)
{
	setName(name);
}

HumanB::~HumanB()
{
	std::cout << "remove this message in destructor\n";
}

std::string const&	HumanB::getName(void) const
{
	return (name);
}

void	HumanB::setName(std::string name)
{
	this->name = name;
}

void			HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->getName() << " attacks with their " << this->weapon->getType() << std::endl;
}

