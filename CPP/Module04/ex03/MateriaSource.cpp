/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:13 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/06 07:20:31 by zharzi           ###   ########.fr       */
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
	AMateria* tab[4];
	int j = 0;

	for (int i = 0; i < 4; i++)
		tab[i] = NULL;
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] && memory[i] != tab[0] && memory[i] != tab[1] && memory[i] != tab[2] && memory[i] != tab[3])
		{
			tab[j] = memory[i];
			j++;
		}
	}
	for (int i = 0; i < j; i++)
		if (tab[i])
			delete tab[i];
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
