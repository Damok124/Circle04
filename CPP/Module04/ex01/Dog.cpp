/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/23 12:08:10 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor by DEFAULT called" << std::endl;
	setType("Dog");
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
		setType(source.getType());
	return *this;
}

Dog::~Dog()
{
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
