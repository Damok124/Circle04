/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/09 19:37:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Ani constructor by DEFAULT called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& source)
{
	std::cout << "Ani constructor by COPY called" << std::endl;
	*this = source;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& source)
{
	std::cout << "Ani assignation OPERATOR called" << std::endl;
	if (this != &source)
		setType(source.getType());
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Ani DESTRUCTOR called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (type);
}

void	WrongAnimal::setType(std::string const type)
{
	this->type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "* some animal noises *" << std::endl;
}
