/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/22 07:47:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void	testWrong1(const WrongAnimal& animal)
{
	std::cout << animal.getType() << std::endl;
}

void	testWrong2(const WrongAnimal& animal)
{
	animal.makeSound();
}

void	test1(const Animal& animal)
{
	std::cout << animal.getType() << std::endl;
}

void	test2(const Animal& animal)
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

// int	main(void)
// {
// 	test3();
// 	test4();
// 	test5();
// 	test6();
// 	test7();
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
