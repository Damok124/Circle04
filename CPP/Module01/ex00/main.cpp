/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:23:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/06 13:57:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie*	newZombie( std::string name )
{
	Zombie *inst = new Zombie;

	inst->name = name;
	return (inst);
}

void	randomChump( std::string name )
{
	Zombie inst;

	inst.name = name;
	inst.announce();
}


int	main(void)
{
	std::string name = "Jean";


	// • Zombie* newZombie( std::string name );
	// Crée un zombie, lui donne un nom et le retourne afin qu’il puisse
	// être utilisé en dehors de la portée de la fonction.
	//
	// • void randomChump( std::string name );
	// Crée un zombie, lui donne un nom et le fait se présenter.


	return (0);
}
