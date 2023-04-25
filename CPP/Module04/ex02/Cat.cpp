/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/25 17:28:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	std::cout << "Cat constructor by DEFAULT called" << std::endl;
	setType("Cat");
	_brain = new Brain();
}

Cat::Cat(Cat const& source) : AAnimal()
{
	std::cout << "Cat constructor by COPY called" << std::endl;
	_brain = new Brain();
	*this = source;
}

Cat& Cat::operator=(Cat const& source)
{
	std::cout << "Cat assignation OPERATOR called" << std::endl;
	if (this != &source)
	{
		setType(source.getType());
		setBrain(*source._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat DESTRUCTOR called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meowwww..." << std::endl;
}

void	Cat::setBrain(Brain const& source)
{
	for (int i = 0; i < 100; i++)
		_brain->setIdea(source.getIdea(i), i);
}

Brain const&	Cat::getBrain() const
{
	return (*_brain);
}

void	Cat::checkBrain() const
{
	_brain->showAllIdeas();
}

void	Cat::setIdea(std::string str, int i)
{
	_brain->setIdea(str, i);
}

void	Cat::resetBrain()
{
	delete _brain;
	_brain = new Brain();
}
