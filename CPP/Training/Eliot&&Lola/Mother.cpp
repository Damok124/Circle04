/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mother.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:00:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/27 14:03:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mother.hpp"

Mother::Mother()
{
}

Mother::Mother(int age, char eye_color) : age(age), eye_color(eye_color)
{
	std::cout << "Mother Constructor" << std::endl;
}

Mother::~Mother()
{
	std::cout << "Mother destructor" << std::endl;
}

int Mother::getAge(void) const
{
	return (age);
}

char Mother::getEyeColor(void) const
{
	return (eye_color);
}

void	Mother::argue(Daughter& girl)
{
	(void) girl;
	std::cout << "You must do your homework, give me your phone" << std::endl;
}

void	Mother::job()
{
	std::cout << "Hello, I am a lawyer" << std::endl;
}
