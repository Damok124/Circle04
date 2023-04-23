/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/23 20:39:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	testWrong1(WrongAnimal const& animal)
{
	std::cout << animal.getType() << std::endl;
}

void	testWrong2(WrongAnimal const& animal)
{
	animal.makeSound();
}

void	test1(Animal const& animal)
{
	std::cout << animal.getType() << std::endl;
}

void	test2(Animal const& animal)
{
	animal.makeSound();
}

void	test3(void)
{
	{
		Animal unknown;
		test1(unknown);
		test2(unknown);
	}
	std::cout << std::endl;
	{
		Animal alpha;
		Animal clone(alpha);
		test1(clone);
		test2(clone);
	}
	std::cout << std::endl;
	{
		Animal beta;
		Animal fake = beta;
		test1(fake);
		test2(fake);
	}
	std::cout << std::endl;
}

void	test4(void)
{
	{
		Cat unknown;
		test1(unknown);
		test2(unknown);
	}
	std::cout << std::endl;
	{
		Cat alpha;
		Cat clone(alpha);
		test1(clone);
		test2(clone);
	}
	std::cout << std::endl;
	{
		Cat beta;
		Cat fake = beta;
		test1(fake);
		test2(fake);
	}
	std::cout << std::endl;
}

void	test5(void)
{
	{
		Dog unknown;
		test1(unknown);
		test2(unknown);
	}
	std::cout << std::endl;
	{
		Dog alpha;
		Dog clone(alpha);
		test1(clone);
		test2(clone);
	}
	std::cout << std::endl;
	{
		Dog beta;
		Dog fake = beta;
		test1(fake);
		test2(fake);
	}
	std::cout << std::endl;
}

void	test6(void)
{
	{
		WrongAnimal unknown;
		testWrong1(unknown);
		testWrong2(unknown);
	}
	std::cout << std::endl;
	{
		WrongAnimal alpha;
		WrongAnimal clone(alpha);
		testWrong1(clone);
		testWrong2(clone);
	}
	std::cout << std::endl;
	{
		WrongAnimal beta;
		WrongAnimal fake = beta;
		testWrong1(fake);
		testWrong2(fake);
	}
	std::cout << std::endl;
}

void	test7(void)
{
	{
		WrongCat unknown;
		testWrong1(unknown);
		testWrong2(unknown);
	}
	std::cout << std::endl;
	{
		WrongCat alpha;
		WrongCat clone(alpha);
		testWrong1(clone);
		testWrong2(clone);
	}
	std::cout << std::endl;
	{
		WrongCat beta;
		WrongCat fake = beta;
		testWrong1(fake);
		testWrong2(fake);
	}
	std::cout << std::endl;
}

void	test8(void)
{
	{
		Cat unknown;
		unknown.checkBrain();
		unknown.setIdea("Nan", 19);
		unknown.setIdea("mais", 23);
		unknown.setIdea("ALLO", 33);
		unknown.setIdea("quoi !", 99);
		unknown.setIdea("LOL", 100);
		unknown.checkBrain();
	}
	std::cout << std::endl;
	{
		Dog alpha;
		Dog clone(alpha);
		clone.checkBrain();
		clone.setIdea("Nan", 19);
		clone.setIdea("mais", 23);
		clone.setIdea("ALLO", 33);
		clone.setIdea("quoi !", 99);
		clone.setIdea("LOL", 100);
		clone.checkBrain();
		clone.resetBrain();
		clone.checkBrain();
	}
	std::cout << std::endl;
	{
		Cat beta;
		Cat fake = beta;
		test1(fake);
		test2(fake);
	}
	std::cout << std::endl;
}

// int	main(void)
// {
// 	// test3();
// 	// test4();
// 	// test5();
// 	// test6();
// 	// test7();
// 	test8();
// 	return (0);
// }

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
// ...
	return 0;
}

/*
Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont la
moitié est composée d’objets Dog et l’autre moitié d’objets Cat. À la fin de l’exécution
du programme, parcourez ce tableau afin de delete chaque Animal. Vous devez delete
directement les chiens et les chats en tant qu’Animal. Les destructeurs correspondants
doivent être appelés dans le bon ordre.
N’oubliez pas de vérifier que vous n’avez pas de fuites de mémoire.
La copie d’un objet Dog ou d’un objet Cat ne doit pas être superficielle. Par consé-
quent, vous devez vous assurer que vos copies sont bien des copies profondes.
*/
