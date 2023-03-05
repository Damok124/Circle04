/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/28 18:22:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

Contact PhoneBook::add_contact(void)
{
	Contact		contact;
	std::string	str;

	do
	{
		std::cout << ">First Name : ";
		std::getline(std::cin, str);
	} while (str.empty());
	contact.set_first_name(str);
	do
	{
		std::cout << ">Last Name : ";
		std::getline(std::cin, str);
	} while (str.empty());
	contact.set_last_name(str);
	do
	{
		std::cout << ">Nickname : ";
		std::getline(std::cin, str);
	} while (str.empty());
	contact.set_nickname(str);
	do
	{
		std::cout << ">Phone Number : ";
		std::getline(std::cin, str);
	} while (str.empty());
	contact.set_phone_number(str);
	do
	{
		std::cout << ">Darkest secret : ";
		std::getline(std::cin, str);
	} while (str.empty());
	contact.set_darkest_secret(str);
	return (contact);
}

void	PhoneBook::print_columns(std::string str)
{
	std::cout << "|";
	if (str.size() > 0)
	{
		if (str.size() > 10)
		{
			std::cout.write(str.c_str(), 9);
			std::cout << ".";
		}
		else
		{
			if (str.size() < 10)
				std::cout << std::setw(10);
			std::cout << str;
		}
	}
}

void	PhoneBook::print_line_contact(int index)
{
	Contact		contact;
	std::string	first;
	std::string	last;
	std::string	nickname;

	contact = this->_contacts[index];
	first = contact.get_first_name();
	last = contact.get_last_name();
	nickname = contact.get_nickname();
	if (first.size() > 0)
	{
		std::cout << "|" << std::setw(10) << index;
		print_columns(first);
		print_columns(last);
		print_columns(nickname);
		std::cout << "|" << std::endl;
	}
	else
	{
		std::cout << "|" << std::setw(11) << "|";
		std::cout << std::setw(11) << "|";
		std::cout << std::setw(11) << "|";
		std::cout << std::setw(11) << "|" << std::endl;
	}
}

void	PhoneBook::print_full_contact(int index)
{
	Contact		contact;
	std::string	first;
	std::string	last;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	contact = this->_contacts[index];
	first = contact.get_first_name();
	last = contact.get_last_name();
	nickname = contact.get_nickname();
	phone_number = contact.get_phone_number();
	darkest_secret = contact.get_darkest_secret();
	std::cout << "First Name : " << first << std::endl;
	std::cout << "Last Name : " << last << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone Number : " << phone_number << std::endl;
	std::cout << "Darkest Secret : " << darkest_secret << std::endl;
}

void PhoneBook::print_phonebook(void)
{
	Contact	contact;
	int	i = 0;

	std::string	str;
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|  index   |first name|last name | nickname |" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	while (i < 8)
	{
		print_line_contact(i);
		i++;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

void PhoneBook::search_contact(void)
{
	std::string	str;
	PhoneBook::print_phonebook();
	do
	{
		std::cout << "Which contact are you looking for? (Write his index from 0 to 7) :" << std::endl;
		std::getline(std::cin, str);
	} while (str.empty());
	while (str != "0" && str != "1" && str != "2" && str != "3" && str != "4" && str != "5" && str != "6" && str != "7")
	{
		std::cout << "Please, enter a valid contact index (from 0 to 7) :" << std::endl;
		std::getline(std::cin, str);
	}
	PhoneBook::print_full_contact(std::stoi(str, nullptr, 10));
}

void PhoneBook::set_contact(Contact contact, int index)
{
	this->_contacts[index] = contact;
}
