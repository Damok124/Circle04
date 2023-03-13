/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:54:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 16:14:44 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	print_levels(int level, Harl& inst)
{
	std::string str;
	if (level < 4)
	{
		while (level < 4)
		{
			str = inst.getTitle(level);
			std::cout << "[ " << str << " ]" << std::endl;
			inst.complain(str);
			std::cout << std::endl;
			level++;
		}
	}
	else
		std::cout << "[ I have absolutely no idea of what you are talking about ! ]" << std::endl;
}

int	main(int ac, char **argv)
{
	Harl inst;
	std::string level;
	int	i = 0;

	if (ac == 2)
	{
		level = argv[1];
		for (i = 0; i < 4; i++)
		{
			if (level.compare(inst.getTitle(i)) == 0)
				break ;
		}
		switch (i)
		{
			case 0:
				print_levels(0, inst);
				break ;
			case 1:
				print_levels(1, inst);
				break ;
			case 2:
				print_levels(2, inst);
				break ;
			case 3:
				print_levels(3, inst);
				break ;
			default :
				print_levels(4, inst);
				break ;
		}
	}
	else
		std::cout << "Error. This program need one and only one argument." << std::endl;
	return (0);
}
