/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:23:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/08 21:39:53 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	name = "Zooombie";
	int			n = 10;

	Zombie* h = zombieHorde(n, name);
	for (int i = 0; i < n; i++)
	{
		std::cout << &(h[i]) << " => num " << i + 1 << " : ";
		h[i].announce();
	}

	delete [] h;

	return (0);
}
