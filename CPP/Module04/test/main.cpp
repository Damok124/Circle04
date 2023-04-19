/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/17 03:31:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// À la construction, les classes Dog et Cat créeront leur Brain avec new Brain();
// À la destruction, les classes Dog et Cat devront delete leur Brain.
// Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont la
// moitié est composée d’objets Dog et l’autre moitié d’objets Cat. À la fin de l’exécution
// du programme, parcourez ce tableau afin de delete chaque Animal. Vous devez delete
// directement les chiens et les chats en tant qu’Animal. Les destructeurs correspondants
// doivent être appelés dans le bon ordre.
// N’oubliez pas de vérifier que vous n’avez pas de fuites de mémoire.
// La copie d’un objet Dog ou d’un objet Cat ne doit pas être superficielle. Par consé-
// quent, vous devez vous assurer que vos copies sont bien des copies profondes.

// void testWrong1(const WrongAnimal *animal)
// {
// 	std::cout << animal->getType() << std::endl;
// }

// void testWrong2(const WrongAnimal *animal)
// {
// 	animal->makeSound();
// }

void test1(const Animal *animal)
{
	std::cout << animal->getType() << std::endl;
}

void test2(const Animal *animal)
{
	animal->makeSound();
}

void	test3(void)
{
	{
		Animal unknown;
		test1(&unknown);
		test2(&unknown);
	}
	std::cout << std::endl;
	{
		Animal alpha;
		Animal clone(alpha);
		test1(&clone);
		test2(&clone);
	}
	std::cout << std::endl;
	{
		Animal beta;
		Animal fake = beta;
		test1(&fake);
		test2(&fake);
	}
	std::cout << std::endl;
}

void	test4(void)
{
	{
		Cat unknown;
		test1(&unknown);
		test2(&unknown);
	}
	std::cout << std::endl;
	{
		Cat alpha;
		Cat clone(alpha);
		test1(&clone);
		test2(&clone);
	}
	std::cout << std::endl;
	{
		Cat beta;
		Cat fake = beta;
		test1(&fake);
		test2(&fake);
	}
	std::cout << std::endl;
}

void	test5(void)
{
	{
		Dog unknown;
		test1(&unknown);
		test2(&unknown);
	}
	std::cout << std::endl;
	{
		Dog alpha;
		Dog clone(alpha);
		test1(&clone);
		test2(&clone);
	}
	std::cout << std::endl;
	{
		Dog beta;
		Dog fake = beta;
		test1(&fake);
		test2(&fake);
	}
	std::cout << std::endl;
}

void	test6(void)
{
	{
		WrongAnimal unknown;
		testWrong1(&unknown);
		testWrong2(&unknown);
	}
	std::cout << std::endl;
	{
		WrongAnimal alpha;
		WrongAnimal clone(alpha);
		testWrong1(&clone);
		testWrong2(&clone);
	}
	std::cout << std::endl;
	{
		WrongAnimal beta;
		WrongAnimal fake = beta;
		testWrong1(&fake);
		testWrong2(&fake);
	}
	std::cout << std::endl;
}

void	test7(void)
{
	{
		WrongCat unknown;
		testWrong1(&unknown);
		testWrong2(&unknown);
	}
	std::cout << std::endl;
	{
		WrongCat alpha;
		WrongCat clone(alpha);
		testWrong1(&clone);
		testWrong2(&clone);
	}
	std::cout << std::endl;
	{
		WrongCat beta;
		WrongCat fake = beta;
		testWrong1(&fake);
		testWrong2(&fake);
	}
	std::cout << "End of test 7" << std::endl;
}

int main(void)
{
	// test3();
	test4();
	// test5();
	// test6();
	// test7();
	return (0);
}

// int main(void)
// {
// 	std::string str = "a";
// 	Brain cortex;

// 	for (int i = 0; i < 100 ; i++)
// 	{
// 		cortex.setOneIdea(str, i);
// 		str[0] = str[0] + 1;
// 	}
// 	for (int i = 0; i < 100 ; i++)
// 		std::cout << i << " : " + cortex.getOneIdea(i) << std::endl;
// 	return (0);
// }
