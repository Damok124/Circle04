/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/22 07:18:09 by zharzi           ###   ########.fr       */
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
