/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 18:42:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
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

void	test1(AAnimal const& animal)
{
	std::cout << animal.getType() << std::endl;
}

void	test2(AAnimal const& animal)
{
	animal.makeSound();
}

void	test3(void)
{
	{
		AAnimal* unknown = new Cat();
		test1(*unknown);
		test2(*unknown);
		delete unknown;
	}
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
		std::cout << "clone checkBrain :" << std::endl;
		clone.checkBrain();
		alpha = clone;
		std::cout << "alpha checkBrain :" << std::endl;
		alpha.checkBrain();
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

int	main(void)
{
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return (0);
}
