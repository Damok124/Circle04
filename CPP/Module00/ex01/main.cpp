/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:24:15 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/28 16:47:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	str;
	int			index = 0;

	while (str != "EXIT")
	{
		std::cout << ">PhoneBook : ";
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			phonebook.set_contact(phonebook.add_contact(), index);
			index++;
			index = index % 8;
		}
		else if (str == "SEARCH")
			phonebook.search_contact();
	}

	return (0);
}
