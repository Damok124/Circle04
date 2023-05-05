/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:19:58 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 15:51:26 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const& source) : AMateria(source)
{
}

Cure& Cure::operator=(Cure const& source)
{
	(void)source;
	return (*this);
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	AMateria *inst = new Cure();
	return (inst);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
