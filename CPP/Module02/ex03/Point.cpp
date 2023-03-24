/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:34 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/24 15:42:26 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
}

Point::Point(float const x, float const y): x(x), y(y)
{
}

Point::Point(Point const& source): x(source.getX()), y(source.getY())
{
}

Fixed const&	Point::getX(void) const
{
	return (x);
}

Fixed const&	Point::getY(void) const
{
	return (y);
}

Point& Point::operator=(Point const& source)
{
	return (*this);
}

Point::~Point()
{
}
