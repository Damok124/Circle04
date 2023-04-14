/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:05:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/14 20:41:12 by zharzi           ###   ########.fr       */
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
		for (i = 0; i <= 100; i++)
			setOneIdea(source.getOneIdea(i), i);
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain DESTRUCTOR called" << std::endl;
}

void	Brain::setOneIdea(std::string idea, int i)
{
	if (i >= 0 && i <= 100)
		ideas[i] = idea;
	else
		std::cout << "setIdeas failed" << std::endl;
}

std::string	Brain::getOneIdeas(int i) const
{
	if (i >= 0 && i <= 100)
		return (ideas[i]);
	else
		return std::string();
}

std::string	Brain::getIdeas() const
{
	return ideas;
}