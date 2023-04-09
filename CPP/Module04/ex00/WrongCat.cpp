/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/09 01:17:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor by DEFAULT called" << std::endl;
	setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const& source) : WrongAnimal()
{
	std::cout << "WrongCat constructor by COPY called" << std::endl;
	*this = source;
}

WrongCat& WrongCat::operator=(WrongCat const& source)
{
	std::cout << "WrongCat assignation OPERATOR called" << std::endl;
	if (this != &source)
		setType(source.getType());
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat DESTRUCTOR called" << std::endl;
}
