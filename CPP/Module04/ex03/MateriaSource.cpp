/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:13 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/28 22:20:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
}

MateriaSource::MateriaSource(MateriaSource const& source)
{
	(void)source;///////////////////////////del
}

MateriaSource& MateriaSource::operator=(MateriaSource const& source)
{
	(void)source;///////////////////////////del
	return (*this);
}

MateriaSource::~MateriaSource()
{
}

void	MateriaSource::learnMateria(AMateria* name)//////////////rename it
{
	(void)name;///////////////////////////del
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	(void)type;///////////////////////////del
	return (NULL);//////////////////////////del
}

/*
• learnMateria(AMateria*)
Copie la Materia passée en paramètre et la stocke en mémoire afin de la cloner
plus tard. Tout comme le Character, la MateriaSource peut contenir 4 Materias
maximum. Ces dernières ne sont pas forcément uniques.

• createMateria(std::string const &)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
ment par la MateriaSource et dont le type est le même que celui passé en para-
mètre. Retourne 0 si le type est inconnu.

En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.
*/
