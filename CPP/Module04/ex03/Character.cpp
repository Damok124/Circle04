/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:19:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/03 07:20:22 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// std::string	name;
// AMateria*	inventory[4];

Character::Character() : ICharacter(), name("NoName")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string name) : ICharacter(), name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(Character const& source) : ICharacter()
{
	// (void)source;///////////////////////////del
	*this = source;
}

Character& Character::operator=(Character const& source)
{
	// (void)source;///////////////////////////del
	if (this != &source)
	{
		this->setName(source.getName());
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] == NULL)
				inventory[i] = source.inventory[i];
			else
			{
				delete inventory[i];
				inventory[i] = source.inventory[i];
			}
		}
	}
	return (*this);
}

Character::~Character()
{
}

std::string const &	Character::getName() const
{
	return (name);//////////////////////////////del
}

void	Character::equip(AMateria* m)
{
	(void)m;///////////////////////////del
	inventory[1] = m;//////////////////del
}

void	Character::unequip(int idx)
{
	(void)idx;///////////////////////////del
}

void	Character::use(int idx, ICharacter& target)
{
	(void)idx;///////////////////////////del
	(void)target;///////////////////////////del
}

void	Character::setName(std::string const name)
{
	this->name = name;
}

/*
Le Character a un inventaire de 4 items, soit 4 Materias maximum. À la construction,
l’inventaire est vide. Les Materias sont équipées au premier emplacement vide trouvé, soit
dans l’ordre suivant : de l’emplacement 0 au 3. Dans le cas où on essaie d’ajouter une
Materia à un inventaire plein, ou d’utiliser/retirer une Materia qui n’existe pas, ne faites
rien (cela n’autorise pas les bugs pour autant).

La fonction membre unequip() ne doit PAS delete la Materia !<<----------comment?
Occupez-vous des Materias laissées au sol par votre personnage comme
vous le sentez. Vous pouvez enregistrer l’adresse avant d’appeler
unequip(), ou autre, du moment que vous n’avez pas de fuites de mémoire.


La fonction membre use(int, ICharacter&) utilisera la Materia de l’emplacement[idx],
et passera la cible en paramètre à la fonction AMateria::use.

L’inventaire de votre personnage devra pouvoir contenir n’importe
quel type d’objet AMateria.

Votre Character doit comporter un constructeur prenant son nom en paramètre.

Toute copie (avec le constructeur par recopie ou l’opérateur d’affectation) d’un Charac-
ter doit être profonde. Ainsi, lors d’une copie, les Materias du Character doivent être
delete avant que les nouvelles ne les remplacent dans l’inventaire.

Bien évidemment, les Materias doivent aussi être supprimées à la destruction d’un Character.
*/
