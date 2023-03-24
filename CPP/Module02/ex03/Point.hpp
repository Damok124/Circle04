/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:36 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/24 17:47:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	public:
						Point();
						Point(float const x, float const y);
						Point(Point const& source);
						Point& operator=(Point const& source);
						~Point();
		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;

	private:
		Fixed const		x;
		Fixed const		y;
};

#endif//_______________________________________________________________POINT_HPP
