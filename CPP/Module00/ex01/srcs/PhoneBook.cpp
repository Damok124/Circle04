/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/25 18:52:29 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact(void)
{
	std::string	str;

	while (std::is_empty(str))
	{
		std::cout << ">First Name : ";
		std::getline(std::cin, str);
	}
	std::cout << ">Last Name : ";
	std::getline(std::cin, str);
	std::cout << ">Nickname : ";
	std::getline(std::cin, str);
	std::cout << ">Phone Number : ";
	std::getline(std::cin, str);
	std::cout << ">Darkest secret : ";
	std::getline(std::cin, str);

}
