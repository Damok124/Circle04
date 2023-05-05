/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:19:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 15:00:55 by zharzi           ###   ########.fr       */
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
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	floor = NULL;
	*this = source;
}

Character& Character::operator=(Character const& source)
{
	if (this != &source)
	{
		this->setName(source.getName());
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];
			inventory[i] = source.inventory[i]->clone();
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
