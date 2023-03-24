/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:38 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/24 17:47:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float	get_area(Point const& a, Point const& b, Point const& c)
{
	Fixed const& xA = a.getX();
	Fixed const& yA = a.getY();
	Fixed const& xB = b.getX();
	Fixed const& yB = b.getY();
	Fixed const& xC = c.getX();
	Fixed const& yC = c.getY();

	float area = ((xB.toFloat() - xA.toFloat()) * (yC.toFloat() - yA.toFloat())
		- (xC.toFloat() - xA.toFloat()) * (yB.toFloat() - yA.toFloat())) / 2;
	if (area < 0)
		area *= -1;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float abc = get_area(a, b, c);
	float abp = get_area(a, b, point);
	float bcp = get_area(point, b, c);
	float acp = get_area(a, point, c);

	if (abc == 0)
		return (false);
	if (abp == 0 || bcp == 0 || acp == 0)
		return (false);
	if ((abp + bcp + acp) != abc)
		return (false);
	return (true);
}
