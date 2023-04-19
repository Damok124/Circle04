/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/16 20:05:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor by DEFAULT called" << std::endl;
	setType("Cat");
	// _brain = new Brain;
	setBrain();
}

Cat::Cat(Cat const& source) : Animal()
{
	std::cout << "Cat constructor by COPY called" << std::endl;
	*this = source;
}

Cat& Cat::operator=(Cat const& source)
{
	std::cout << "Cat assignation OPERATOR called" << std::endl;
	if (this != &source)
	{
		setType(source.getType());
		setBrain(source.getBrain());
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat DESTRUCTOR called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meowwww..." << std::endl;
}

void	Cat::setBrain(Brain *brain)
{
	if (brain)
	{
		if (_brain)
			delete _brain;
		_brain = new Brain;
		for (int i = 0; i < 100; i++)
			_brain->setOneIdea(brain->getOneIdea(i), i);
	}
	else
		setBrain();
}

void	Cat::setBrain()
{
	if (_brain)
		delete _brain;
	_brain = new Brain;
	for (int i = 0; i < 100; i++)
		_brain->setOneIdea(std::string(), i);
}

Brain*	Cat::getBrain() const
{
	return (_brain);
}
