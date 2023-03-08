/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:23:27 by zharzi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/08 18:59:23 by zharzi           ###   ########.fr       */
=======
/*   Updated: 2023/03/08 11:50:07 by zharzi           ###   ########.fr       */
>>>>>>> 0627db3 (before)
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string n1 = "Jean";
	std::string n2 = "Louis";
	std::string n3 = "Francois";
<<<<<<< HEAD
=======

	std::string name;

	newZombie(n1);
	newZombie(n2);
	newZombie(n3);

>>>>>>> 0627db3 (before)

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
