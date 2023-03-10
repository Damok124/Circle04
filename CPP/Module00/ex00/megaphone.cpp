/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/10 13:49:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **argv)
{
	std::string str;
	int	i = 0;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		while (argv && argv[++i])
			str += argv[i];
		i = -1;
		while (str[++i])
			if (std::islower(str[i]))
				str[i] = std::toupper(str[i]);
		std::cout << str << std::endl;
	}
	return (0);
}
