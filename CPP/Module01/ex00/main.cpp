/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:23:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/10 08:54:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string n1 = "Jean";
	std::string n2 = "Louis";
	std::string n3 = "Francois";

	Zombie* a = newZombie(n1 + "-" + n2);
	Zombie* b = newZombie(n1 + "-" + n3);
	Zombie* c = newZombie(n2 + "-" + n3);
	a->announce();
	b->announce();
	c->announce();
	randomChump(n1);
	randomChump(n2);
	randomChump(n3);

	delete a;
	delete b;
	delete c;

	return (0);
}
