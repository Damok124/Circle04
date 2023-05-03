/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:02 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/03 11:19:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	type = "ice";
}

Ice::Ice(Ice const& source) : AMateria(source)
{
	(void)source;///////////////////////////del
	type = "ice";
}

Ice& Ice::operator=(Ice const& source)
{
	(void)source;///////////////////////////del
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
	// (void)target;///////////////////////////del
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
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
