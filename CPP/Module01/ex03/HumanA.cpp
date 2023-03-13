/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:21:48 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 17:49:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}

std::string	HumanA::getName(void) const
{
	return (name);
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}

void	HumanA::attack()
{
	std::cout << getName() << " attacks with their " << weapon.getType() << std::endl;
}
