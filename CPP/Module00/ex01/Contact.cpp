/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:59:01 by zharzi            #+#    #+#             */
/*   Updated: 2023/02/28 18:18:21 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::set_first_name(std::string str)
{
	_first_name = str;
}

void Contact::set_last_name(std::string str)
{
	_last_name = str;
}

void Contact::set_nickname(std::string str)
{
	_nickname = str;
}

void Contact::set_phone_number(std::string str)
{
	_phone_number = str;
}

void Contact::set_darkest_secret(std::string str)
{
	_darkest_secret = str;
}


std::string Contact::get_first_name()
{
	return (_first_name);
}

std::string Contact::get_last_name()
{
	return (_last_name);
}

std::string Contact::get_nickname()
{
	return (_nickname);
}

std::string Contact::get_phone_number()
{
	return (_phone_number);
}

std::string Contact::get_darkest_secret()
{
	return (_darkest_secret);
}
