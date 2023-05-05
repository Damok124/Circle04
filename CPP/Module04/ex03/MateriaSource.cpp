/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:13 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 18:20:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const& source) : IMateriaSource()
{
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
	*this = source;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& source)
{
	if (this != &source)
	{
		for (int i = 0; i < 4; i++)
		{
			if (memory[i] != NULL)
				delete memory[i];
			memory[i] = source.memory[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (memory[i])
			delete memory[i];
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] == NULL)
		{
			memory[i] = materia;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] && memory[i]->getType() == type)
			return (memory[i]->clone());
	}
	return (0);
}
