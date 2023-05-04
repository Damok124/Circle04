/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:19:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/04 17:40:02 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter(), name("NoName")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	floor = NULL;
}

Character::Character(std::string name) : ICharacter(), name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	floor = NULL;
}

Character::Character(Character const& source) : ICharacter()
{
	*this = source;
}

Character& Character::operator=(Character const& source)
{
	if (this != &source)
	{
		this->setName(source.getName());
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] == NULL)
				inventory[i] = source.inventory[i];//faire deep copy
			else
			{
				delete inventory[i];
				inventory[i] = source.inventory[i];//faire deep copy
			}
		}
		floor = source.floor;
	}
	return (*this);
}

Character::~Character()
{
	t_floor* tmp;
	for (int i = 0; i < 4; i++)
		unequip(i);
	while (floor)
	{
		tmp = floor;
		delete floor->item;
		floor = floor->next;
		delete tmp;
	}
}

std::string const &	Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria* m)
{
	if (m)
	{
		if (inventory[0] != m && inventory[1] != m && inventory[2] != m && inventory[3] != m)
		{
			for (int i = 0; i < 4; i++)
			{
				if (inventory[i] == NULL)
				{
					inventory[i] = m;
					break ;
				}
			}
		}
		else
			std::cout << "cannot equip materia which is already equiped" << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 4)
	{
		addOnFloor(inventory[idx]);
		inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 4)
	{
		if (inventory[idx] != NULL)
			inventory[idx]->use(target);
	}
}

void	Character::setName(std::string const name)
{
	this->name = name;
}

void	Character::addOnFloor(AMateria* elem)
{
	if (elem)
	{
		t_floor* ptr = new t_floor;
		ptr->item = elem;
		ptr->next = NULL;

		t_floor* tmp = floor;
		if (tmp)
		{
			while (tmp && tmp->next)
				tmp = tmp->next;
			tmp->next = ptr;
		}
		else
			floor = ptr;
	}
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
