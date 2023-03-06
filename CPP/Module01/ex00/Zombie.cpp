/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:19:28 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/06 08:05:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	;
}

Zombie::~Zombie()
{
	std::cout << name << " died in an horrible way" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie( std::string name )
{
	// Crée un zombie, lui donne un nom et le retourne afin qu’il puisse
	// être utilisé en dehors de la portée de la fonction.
	Zombie *inst = new Zombie;

	inst->name = name;
	return (inst);
}

void Zombie::randomChump( std::string name )
{
	// Crée un zombie, lui donne un nom et le fait se présenter.
	Zombie inst;

	inst.name = name;
	inst.announce();
}
