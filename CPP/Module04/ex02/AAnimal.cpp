/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/25 17:27:48 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Ani constructor by DEFAULT called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& source)
{
	std::cout << "Ani constructor by COPY called" << std::endl;
	*this = source;
}

AAnimal& AAnimal::operator=(AAnimal const& source)
{
	std::cout << "Ani assignation OPERATOR called" << std::endl;
	if (this != &source)
		setType(source.getType());
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Ani DESTRUCTOR called" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (type);
}

void	AAnimal::setType(std::string const type)
{
	this->type = type;
}
