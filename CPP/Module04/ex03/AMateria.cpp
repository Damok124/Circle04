/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:08:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/26 21:57:14 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(AMateria& source)
{
	*this = source
}

AMateria& AMateria::operator=(AMateria const& source)
{
	if (this != &source)

}

AMateria::AMateria(std::string const & type)
{
}

AMateria::~AMateria()
{
}

std::string const &	AMateria::getType() const
{
}

void	AMateria::use(ICharacter& target)
{
}

