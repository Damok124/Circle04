/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/05 19:42:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap unknown;
	DiamondTrap boris("Boris");
	DiamondTrap fakeboris(boris);
	// unknown = boris;//NoName becomes Boris when this line is active
	fakeboris.attack("Alix");//fakeboris remains 9/10 energy points
	fakeboris.takeDamage(5);//fakeboris remains 5/10 HP
	fakeboris.takeDamage(5);//fakeboris remains 0/10 HP
	fakeboris.beRepaired(5);//fakeboris can't repair because of 0 HP remaining
	fakeboris.takeDamage(5);//fakeboris still at 0 HP, but can be overkilled someway
	fakeboris.beRepaired(5);//fakeboris still can't repair because of 0 HP remaining
	boris.attack("Ben");//Boris remains 9/10 energy points
	boris.beRepaired(1000000);//Boris remains 8/10 energy points
	boris.beRepaired(0);//Boris remains 7/10 energy points
	boris.beRepaired(1);//Boris remains 6/10 energy points
	boris.beRepaired(-1);//Boris remains 5/10 energy points
	boris.beRepaired(4294967295);//Boris remains 4/10 energy points
	boris.beRepaired(10);//Boris remains 3/10 energy points
	boris.beRepaired(10);//Boris remains 2/10 energy points
	boris.beRepaired(10);//Boris remains 1/10 energy points
	boris.beRepaired(10);//Boris remains 0/10 energy points
	boris.beRepaired(10);//Boris can't repair because of 0 energy point remaining
	boris.beRepaired(10);//Boris still can't repair because of 0 energy point remaining
	boris.beRepaired(10);//Boris still can't repair because of 0 energy point remaining
	unknown.attack("Carl");//NoName remains 9/10 energy points
	unknown.attack("Dany");//NoName remains 8/10 energy points
	unknown.attack("Emma");//NoName remains 7/10 energy points
	unknown.attack("Fidel");//NoName remains 6/10 energy points
	unknown.attack("Gustavo");//NoName remains 5/10 energy points
	unknown.attack("Helene");//NoName remains 4/10 energy points
	unknown.attack("Ianis");//NoName remains 3/10 energy points
	unknown.attack("Jose");//NoName remains 2/10 energy points
	unknown.attack("Kennedy");//NoName remains 1/10 energy points
	unknown.beRepaired(15);//NoName remains 0/10 energy points
	unknown.attack("Leonardo");//NoName can't attack because 0f 0 energy point
	unknown.attack("Mael");//NoName still can't attack because 0f 0 energy point
	unknown.attack("Nestor");//NoName still can't attack because 0f 0 energy point
	fakeboris.takeDamage(5000);//fakeboris remains 0/10 HP
	fakeboris.beRepaired(5);//fakeboris can't repair because of 0 HP remaining
	boris.highFivesGuys();
	fakeboris.highFivesGuys();
	unknown.highFivesGuys();
	boris.whoAmI();
	fakeboris.whoAmI();
	unknown.whoAmI();
	return (0);
}
