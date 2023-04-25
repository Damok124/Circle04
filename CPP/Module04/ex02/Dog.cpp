/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/25 17:30:32 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog constructor by DEFAULT called" << std::endl;
	setType("Dog");
	_brain = new Brain();
}

Dog::Dog(Dog const& source) : AAnimal()
{
	std::cout << "Dog constructor by COPY called" << std::endl;
	_brain = new Brain();
	*this = source;
}

Dog& Dog::operator=(Dog const& source)
{
	std::cout << "Dog assignation OPERATOR called" << std::endl;
	if (this != &source)
	{
		setType(source.getType());
		setBrain(*source._brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog DESTRUCTOR called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof !" << std::endl;
}

void	Dog::setBrain(Brain const& source)
{
	for (int i = 0; i < 100; i++)
		_brain->setIdea(source.getIdea(i), i);
}

Brain const&	Dog::getBrain() const
{
	return (*_brain);
}

void	Dog::checkBrain() const
{
	_brain->showAllIdeas();
}

void	Dog::setIdea(std::string str, int i)
{
	_brain->setIdea(str, i);
}

void	Dog::resetBrain()
{
	delete _brain;
	_brain = new Brain();
}
