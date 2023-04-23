/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/23 12:08:03 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor by DEFAULT called" << std::endl;
	setType("Cat");
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
		setType(source.getType());
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

void	Cat::setBrain(Brain const& source)
{
	for (int i = 0; i < 100; i++)
		_brain->setIdea(source.getIdea(i), i);
}

Brain const&	Cat::getBrain() const
{
	return (*_brain);
}
