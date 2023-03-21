/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/21 10:22:55 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream>
# include <cmath>

class Fixed {
	public:
							Fixed();
							Fixed(int const integer);
							Fixed(float const floatting);
							Fixed(Fixed const& source);
							Fixed& operator=(Fixed const& source);
							~Fixed();
// Add public member functions to your class to overload the following operators:
// • The 6 comparison operators: >, <, >=, <=, == and !=.
// • The 4 arithmetic operators: +, -, *, and /.
// • The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
// post-decrement) operators, that will increase or decrease the fixed-point value from
// the smallest representable ε such as 1 + ε > 1.
		bool				operator>(Fixed const& source);
		bool				operator<(Fixed const& source);
		bool				operator>=(Fixed const& source);
		bool				operator<=(Fixed const& source);
		bool				operator==(Fixed const& source);
		bool				operator!=(Fixed const& source);

		Fixed				operator+(Fixed const& source);
		Fixed				operator-(Fixed const& source);
		Fixed				operator*(Fixed const& source);
		Fixed				operator/(Fixed const& source);

		Fixed				operator++(int);
		Fixed&				operator++(void);
		Fixed				operator--(int);
		Fixed& 				operator--(void);
// Add these four public overloaded member functions to your class:
// • A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
// • A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.

// • A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
// • A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.
		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static Fixed&		min(Fixed const&a, Fixed const&b);
		static Fixed&		max(Fixed const& a, Fixed const& b);



		int					getRawBits( void ) const;
		void				setRawBits( int const raw );

		float				toFloat( void ) const;
		int					toInt( void ) const;
	private:
		int					_rawBits;
		static int const	_eight;
};

std::ostream& operator<<(std::ostream & out, Fixed const& inst);

#endif //______________________________________________________________FIXED_HPP
