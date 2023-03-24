/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:13:32 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/24 17:57:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

void	printResult(char c, bool check)
{
	std::cout << "Point " << c << " is ";
	if (!check)
		std::cout << "not ";
	std::cout << "found in the triangle area." << std::endl;
}

int main( void )
{
	Point a(0.0f, 10.0f);
	Point b;
	Point c(10.0f, 0.0f);

	Point d(-89.10f, 96.245f);
	Point e(5.0f, 4.99f);
	Point f(5.0f, 5.0f);
	Point g = a;
	Point h = b;
	Point i = c;
	Point j(0.1f, 9.88f);
	Point k(9.88f, 0.1f);
	Point l(2.0f, 3.0f);
	Point m(8383.0f, 1064.0f);
	printResult('d', bsp(a, b, c, d));
	printResult('e', bsp(a, b, c, e));
	printResult('f', bsp(a, b, c, f));
	printResult('g', bsp(a, b, c, g));
	printResult('h', bsp(a, b, c, h));
	printResult('i', bsp(a, b, c, i));
	printResult('j', bsp(a, b, c, j));
	printResult('k', bsp(a, b, c, k));
	printResult('l', bsp(a, b, c, l));
	printResult('m', bsp(a, b, c, m));

	return (0);
}
