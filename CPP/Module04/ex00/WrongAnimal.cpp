/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/09 01:16:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Ani constructor by DEFAULT called" << std::endl;
}

Animal::Animal(Animal const& source)
{
	std::cout << "Ani constructor by COPY called" << std::endl;
	*this = source;
}

Animal& Animal::operator=(Animal const& source)
{
	std::cout << "Ani assignation OPERATOR called" << std::endl;
	if (this != &source)
		setType(source.getType());
	return *this;
}

Animal::~Animal()
{
	std::cout << "Ani DESTRUCTOR called" << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::setType(std::string const type)
{
	this->type = type;
}

void	Animal::makeSound() const
{
	if (getType() == "Dog")
		std::cout << "Woof ! Woof !" << std::endl;
	else if (getType() == "Cat")
		std::cout << "Meowwwwww ..." << std::endl;
}
