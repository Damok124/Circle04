/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/25 18:38:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << ">PhoneBook : ";
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			std::cout << "into ADD" << std::endl;
			phonebook.add_contact();
		}
		else if (str == "SEARCH")
		{
			std::cout << "into SEARCH" << std::endl;

		}
	}

	return (0);
}
