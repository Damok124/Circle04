/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 07:23:53 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/23 20:08:56 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor by DEFAULT called" << std::endl;
}

Brain::Brain(Brain const& source)
{
	std::cout << "Brain constructor by COPY called" << std::endl;
	*this = source;
}

Brain& Brain::operator=(Brain const& source)
{
	std::cout << "Brain assignation OPERATOR called" << std::endl;
	if (this != &source)
	{
		for (int i = 0; i < 100; i++)
			setIdea(source.getIdea(i), i);
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain DESTRUCTOR called" << std::endl;
}

void	Brain::setIdea(std::string const str, int i)
{
	if (i >= 0 && i < 100)
		ideas[i] = str;
	else
		std::cout << "ERROR : WRONG INDEX TO SET AN IDEA. REQUEST IGNORED" << std::endl;
}

std::string	Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (ideas[i]);
	std::cout << "ERROR : WRONG INDEX TO GET AN IDEA. EMPTY STRING RETURNED" << std::endl;
	return (std::string ());
}

void	Brain::showAllIdeas()
{
	for (int i = 0; i < 100; i++)
		std::cout << "idea index " << i << "\t: " << getIdea(i) << std::endl;
}
