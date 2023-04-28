/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:08:30 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/28 18:27:06 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(AMateria const& source)
{
	(void)source;///////////////////////////del
}

AMateria& AMateria::operator=(AMateria const& source)
{
	(void)source;///////////////////////////del
	return (*this);
}

AMateria::AMateria(std::string const & type)
{
	(void)type;///////////////////////////del
}

AMateria::~AMateria()
{
}

std::string const &	AMateria::getType() const
{
	return (type);//////////////////////////////del
}

void	AMateria::use(ICharacter& target)
{
	(void)target;///////////////////////////del
}


/*
Implémentez les Materias Ice (glace) et Cure (soin) sous forme de classes concrètes.
Utilisez leur noms en minuscules ("ice" pour Ice, "cure" pour Cure) comme types. Bien
sûr, leur fonction membre clone() retournera une nouvelle instance de même type (en
clonant une Materia Ice, on obtient une autre Materia Ice).
Pour ce qui est de la fonction membre use(ICharacter&), elle affichera :
• Ice : "* shoots an ice bolt at <name> *"
• Cure : "* heals <name>’s wounds *"
<name> est le nom du Character (personnage) passé en paramètre. N’affichez pas les
chevrons (< et >).
Quand on assigne une Materia à une autre, copier son type n’a pas
grand intérêt.
*/
