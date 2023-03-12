/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:55:51 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/12 22:42:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";
	message[0] = &Harl::debug;
	message[1] = &Harl::info;
	message[2] = &Harl::warning;
	message[3] = &Harl::error;
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "I love my flowerbed." << std::endl;
}

void	Harl::info( void )
{
	std::cout << "Don't walk on my flowerbed." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "Warning ! Get back from my flowerbed right now !" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "You're dead. My poisonous flowerbed killed you." << std::endl;
}

void	Harl::complain( std::string level )
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level.compare(_level[i]) == 0)
		{
			(this->*message[i])();
			break ;
		}
	}
	if (i == 4)
		std::cout << "No matching level of complain." << std::endl;
}
