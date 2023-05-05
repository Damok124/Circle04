/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:02 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 15:51:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const& source) : AMateria(source)
{
}

Ice& Ice::operator=(Ice const& source)
{
	(void)source;
	return (*this);
}

Ice::~Ice()
{
}

AMateria*	Ice::clone() const
{
	AMateria *inst = new Ice();
	return (inst);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
