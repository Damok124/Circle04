/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:05:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/13 18:27:36 by zharzi           ###   ########.fr       */
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
		setType(source.getType());
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain DESTRUCTOR called" << std::endl;
}

void	setIdeas(std::string idea, int i)
{
	if (i >= 0 && i <= 100)
		ideas[i] = idea;
	else
		std::cout << "setIdeas failed" << std::endl;
}

std::string	getIdeas(int i) const
{
	if (i >= 0 && i <= 100)
		return (ideas[i]);
	else
	{
		std::cout << "getIdeas failed" << std::endl;
		return ("");
	}
}
