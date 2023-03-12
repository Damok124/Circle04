/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:23:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/10 01:09:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");//creation arme humain A
		HumanA bob("Bob", club);// creation humain, donne nom, donne arme
		bob.attack();//attaque
		club.setType("some other type of club");//les valeurs dans club sont modifées
		bob.attack();//attaque
	}
	{
		Weapon club = Weapon("crude spiked club");//creation arme
		HumanB jim("Jim");//creation de l'humain par le nom seul//////////human B
		jim.setWeapon(club);//attribution a l'humain son arme
		jim.attack();//attaque
		club.setType("some other type of club");//la valeur type est modifiée
		jim.attack();//attaque
	}
return (0);
}

/*
Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a const reference to type.
• A setType() member function that sets type using the new one passed as parameter.

Now, create two classes: HumanA and HumanB. They both have a Weapon and a
name. They also have a member function attack() that displays (of course, without the
angle brackets):
<name> attacks with their <weapon type>
HumanA and HumanB are almost the same except for these two tiny details:
• While HumanA takes the Weapon in its constructor, HumanB doesn’t.
• HumanB may not always have a Weapon, whereas HumanA will always be armed.
*/
