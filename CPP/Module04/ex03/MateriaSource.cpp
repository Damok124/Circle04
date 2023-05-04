/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:13 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/04 17:53:48 by zharzi           ###   ########.fr       */
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
	*this = source;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& source)
{
	if (this != &source)
	{
		for (int i = 0; i < 4; i++)
			memory[i] = source.memory[i];//faire copie profonde
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
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
	(void)type;///////////////////////////del
	return (NULL);//////////////////////////del
}

/*

• createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
ment par la MateriaSource et dont le type est le même que celui passé en para-
mètre. Retourne 0 si le type est inconnu.

En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.
*/
