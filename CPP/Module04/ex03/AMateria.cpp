/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:08:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 14:59:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(AMateria const& source)
{
	(void)source;
}

AMateria& AMateria::operator=(AMateria const& source)
{
	(void)source;
	return (*this);
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria()
{
}

std::string const &	AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
