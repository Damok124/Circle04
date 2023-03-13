/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:55:51 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 16:14:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	setTitle(0, "DEBUG");
	setTitle(1, "INFO");
	setTitle(2, "WARNING");
	setTitle(3, "ERROR");
	_mode[0] = &Harl::debug;
	_mode[1] = &Harl::info;
	_mode[2] = &Harl::warning;
	_mode[3] = &Harl::error;
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

std::string const	Harl::getTitle( int index ) const
{
	return (_title[index]);
}

void	Harl::setTitle( int index, std::string title )
{
	_title[index] = title;
}

void	Harl::complain( std::string level )
{
	int	i;

	for (i = 0; i < 4; i++)
	{
		if (level.compare(getTitle(i)) == 0)
		{
			(this->*_mode[i])();
			break ;
		}
	}
	if (i == 4)
		std::cout << "No matching level of complain." << std::endl;
}
