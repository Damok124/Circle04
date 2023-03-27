/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Daughter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:03:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/27 14:03:24 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Daughter.hpp"

Daughter::Daughter()
{
}

Daughter::Daughter(int age, char eye_color, bool tattoo) : Mother(age, eye_color)
{
	// this->age = age;
	// this->eye_color = eye_color;
	this->tattoo = tattoo;

	std::cout << "Daughter Constructor" << std::endl;
}

Daughter::~Daughter()
{
	std::cout << "Daughter destructor" << std::endl;
}

void	Daughter::job()
{
	std::cout << "Wesh, I'm a stud" << std::endl;
}
