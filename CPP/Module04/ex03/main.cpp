/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/03 16:51:07 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

void	test1()
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	ICharacter* me = new Character();
	ice->use(*me);
	cure->use(*me);
	delete me;
	delete ice;
	delete cure;
}

void	test2()
{
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	ICharacter* me = new Character("Code reviewer");
	ice->use(*me);
	cure->use(*me);
	delete me;
	delete ice;
	delete cure;
}

void	test3()
{
	AMateria* ice1 = new Ice();
	AMateria* ice2 = new Ice();
	AMateria* ice3 = new Ice();
	AMateria* ice4 = new Ice();
	AMateria* cure1 = new Cure();
	ICharacter* me = new Character("Code reviewer");
	me->equip(ice1);
	me->equip(ice2);
	me->equip(ice3);
	me->equip(ice4);
	ICharacter* one(me);
	std::cout << "inventory full of ice materia" << std::endl;
	one->use(-150, *me);
	one->use(0, *me);
	one->use(1, *me);
	one->use(2, *me);
	one->use(3, *me);
	one->use(3567488941, *me);
	me->unequip(2);
	std::cout << "inventory[2] now empty" << std::endl;
	one->use(0, *me);
	one->use(1, *me);
	one->use(2, *me);
	one->use(3, *me);
	me->equip(cure1);
	std::cout << "inventory now full of ice and only one cure materia" << std::endl;
	one->use(0, *me);
	one->use(1, *me);
	one->use(2, *me);
	one->use(3, *me);
	me->unequip(-98987);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(412399785);
	delete one;
}


int main( void )
{
	// test1();
	// test2();
	test3();
	return (0);
}

// int main()
// {
// 	IMateriaSource* src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter* me = new Character("me");

// 	AMateria* tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter* bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);
// 	delete bob;
// 	delete me;
// 	delete src;
// 	return 0;
// }

/*
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
*/
