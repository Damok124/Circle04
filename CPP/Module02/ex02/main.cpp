/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:52:50 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/24 07:30:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

/* EXPECTED OUTPUT (from the subject) :
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
*/

// void	printComparison(std::string comp_operator, Fixed const& a, Fixed const& b)
// {
// 	std::cout << a << " " << comp_operator << " " << b << std::endl;
// }

// void	printFixed(char c, Fixed const& inst)
// {
// 	std::cout << c << " = " << inst << std::endl;
// }

// int main( void )
// {
// 	char item = 'a';
// 	Fixed a;
// 	Fixed b(23);
// 	Fixed const c(10);
// 	Fixed d(19.89f);
// 	Fixed const e(23.10f);
// 	Fixed f(c);
// 	Fixed const g(b);
// 	Fixed h(e);
// 	Fixed const i(d);
// 	Fixed j = i;
// 	Fixed const k = h;
// 	Fixed l = b;
// 	Fixed const m = c;


// 	std::cout << "Init :" << std::endl;
// 	std::cout << "info : f == c == m == 10" << std::endl;
// 	std::cout << "info : g == b == l == 23" << std::endl;
// 	std::cout << "info : h == e == k == 23.10" << std::endl;
// 	std::cout << "info : i == d == j == 19.89" << std::endl;
// 	printFixed(item++, a);
// 	printFixed(item++, b);
// 	printFixed(item++, c);
// 	printFixed(item++, d);
// 	printFixed(item++, e);
// 	printFixed(item++, f);
// 	printFixed(item++, g);
// 	printFixed(item++, h);
// 	printFixed(item++, i);
// 	printFixed(item++, j);
// 	printFixed(item++, k);
// 	printFixed(item++, l);
// 	printFixed(item++, m);

// 	std::cout << "Test :" << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "--a = " << --a << std::endl;
// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "a-- = " << a-- << std::endl;
// 	std::cout << "a = " << a << std::endl;

// 	Fixed n = b + c;
// 	Fixed o = b / c;
// 	Fixed p = n - o;
// 	Fixed q = o * p;
// 	std::cout << "OPERATOR + : b + c = " << std::endl;
// 	printFixed(item++, n);
// 	std::cout << "OPERATOR / : b / c = " << std::endl;
// 	printFixed(item++, o);
// 	std::cout << "OPERATOR - : n - o = " << std::endl;
// 	printFixed(item++, p);
// 	std::cout << "OPERATOR * : o * p = " << std::endl;
// 	printFixed(item++, q);

// 	item = 'a';
// 	std::cout << "Actual values :" << std::endl;
// 	printFixed(item++, a);
// 	printFixed(item++, b);
// 	printFixed(item++, c);
// 	printFixed(item++, d);
// 	printFixed(item++, e);
// 	printFixed(item++, f);
// 	printFixed(item++, g);
// 	printFixed(item++, h);
// 	printFixed(item++, i);
// 	printFixed(item++, j);
// 	printFixed(item++, k);
// 	printFixed(item++, l);
// 	printFixed(item++, m);
// 	printFixed(item++, n);
// 	printFixed(item++, o);
// 	printFixed(item++, p);
// 	printFixed(item++, q);

// 	item = 'a';
// 	std::cout << "\n1 : true ; 0 : false.\n" << "OPERATOR > : a > b " << std::endl;
// 	printComparison(">", a, b);
// 	std::cout << (a > b) << std::endl;
// 	item += 2;
// 	std::cout << "OPERATOR < : c < d " << std::endl;
// 	printComparison("<", c, d);
// 	std::cout << (c < d) << std::endl;
// 	item += 2;
// 	std::cout << "OPERATOR >= : e >= f " << std::endl;
// 	printComparison(">=", e, f);
// 	std::cout << (e >= f) << std::endl;
// 	item += 2;
// 	std::cout << "OPERATOR <= : g <= h " << std::endl;
// 	printComparison("<=", g, h);
// 	std::cout << (g <= h) << std::endl;
// 	item += 2;

// 	std::cout << "OPERATOR == : i == j " << std::endl;
// 	printComparison("==", i, j);
// 	std::cout << (i == j) << std::endl;
// 	item += 2;
// 	std::cout << "OPERATOR != : k != l " << std::endl;
// 	printComparison("!=", k, l);
// 	std::cout << (k != l) << std::endl;
// 	item += 2;

// 	return 0;
// }
