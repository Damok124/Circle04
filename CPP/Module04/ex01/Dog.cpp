/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/15 20:10:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor by DEFAULT called" << std::endl;
	setType("Dog");
	setBrain();
}

Dog::Dog(Dog const& source) : Animal()
{
	std::cout << "Dog constructor by COPY called" << std::endl;
	*this = source;
}

Dog& Dog::operator=(Dog const& source)
{
	std::cout << "Dog assignation OPERATOR called" << std::endl;
	if (this != &source)
	{
		setType(source.getType());
		setBrain(source.getBrain());
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog DESTRUCTOR called" << std::endl;
	if (_brain)
		delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof !" << std::endl;
}

void	Dog::setBrain(Brain *brain)
{
	if (_brain)
		delete _brain;
	_brain = new Brain;
	if (brain)
	{
		for (int i = 0; i < 100; i++)
			_brain->setOneIdea(brain->getOneIdea(i), i);
	}

}

void	Dog::setBrain()
{
	if (_brain)
		delete _brain;
	_brain = new Brain;
	for (int i = 0; i < 100; i++)
		_brain->setOneIdea(std::string(), i);
}

Brain*	Dog::getBrain() const
{
	return (_brain);
}
