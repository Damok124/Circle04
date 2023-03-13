/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:54:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/12 22:54:06 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	print_levels(int level, Harl& inst, std::string* lvl)
{
	if (level < 4)
	{
		while (level < 4)
		{
			std::cout << "[ " << lvl[level] << " ]" << std::endl;
			inst.complain(lvl[level]);
			std::cout << std::endl;
			level++;
		}
	}
	else
		std::cout << "[ I have absolutely no idea of what you are talking about ! ]" << std::endl;
}

int	main(int ac, char **argv)
{
	std::string lvl[4];
	lvl[0] = "DEBUG";
	lvl[1] = "INFO";
	lvl[2] = "WARNING";
	lvl[3] = "ERROR";
	int	i = 0;
	std::string level;
	Harl inst;

	if (ac == 2)
	{
		level = argv[1];
		for (i = 0; i < 4; i++)
		{
			if (level.compare(lvl[i]) == 0)
				break ;
		}
		switch (i)
		{
			case 0:
				print_levels(0, inst, lvl);
				break ;
			case 1:
				print_levels(1, inst, lvl);
				break ;
			case 2:
				print_levels(2, inst, lvl);
				break ;
			case 3:
				print_levels(3, inst, lvl);
				break ;
			default :
				print_levels(4, inst, lvl);
				break ;
		}
	}
	else
		std::cout << "Error. This program need one and only one argument." << std::endl;
	return (0);
}
