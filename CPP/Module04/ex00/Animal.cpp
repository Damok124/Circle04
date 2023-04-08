/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/08 15:19:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout <<  << std::endl;
}

Animal::Animal(Animal const& animal)
{
	std::cout <<  << std::endl;
}

Animal& Animal::operator=(Animal const& animal)
{
	std::cout <<  << std::endl;
}

Animal::~Animal()
{
	std::cout <<  << std::endl;
}

std::string	Animal::getType() const
{

}

void	Animal::setType(std::string type)
{

}
