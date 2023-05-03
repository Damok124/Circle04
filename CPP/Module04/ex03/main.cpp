/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/03 07:20:18 by zharzi           ###   ########.fr       */
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
	AMateria* ice = new Ice();
	ICharacter* me = new Character("Code reviewer");
	me->equip(ice);
	ICharacter* one(me);
	delete me;
	delete one;
	delete ice;
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
