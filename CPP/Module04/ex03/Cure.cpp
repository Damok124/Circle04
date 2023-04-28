/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:19:58 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/28 22:22:59 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria()
{
}

Cure::Cure(Cure const& source) : AMateria(source)
{
	(void)source;///////////////////////////del
}

Cure& Cure::operator=(Cure const& source)
{
	(void)source;///////////////////////////del
	return (*this);
}

Cure::~Cure()
{
}

AMateria*	Cure::clone() const
{
	return (NULL);//////////////////////////del
}

void	Cure::use(ICharacter& target)
{
	(void)target;///////////////////////////del
}


/*
Implémentez les Materias Ice (glace) et Cure (soin) sous forme de classes concrètes.

Utilisez leur noms en minuscules ("ice" pour Ice, "cure" pour Cure) comme types



Bien sûr, leur fonction membre clone() retournera une nouvelle instance de même type
(en clonant une Materia Ice, on obtient une autre Materia Ice).

Pour ce qui est de la fonction membre use(ICharacter&), elle affichera :
• Ice : "* shoots an ice bolt at <name> *"
• Cure : "* heals <name>’s wounds *"

*/
