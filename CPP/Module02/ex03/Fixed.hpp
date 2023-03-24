/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/24 07:28:02 by zharzi           ###   ########.fr       */
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

		bool				operator>(Fixed const& source) const;
		bool				operator<(Fixed const& source) const;
		bool				operator>=(Fixed const& source) const;
		bool				operator<=(Fixed const& source) const;
		bool				operator==(Fixed const& source) const;
		bool				operator!=(Fixed const& source) const;

		Fixed				operator+(Fixed const& source) const;
		Fixed				operator-(Fixed const& source) const;
		Fixed				operator*(Fixed const& source) const;
		Fixed				operator/(Fixed const& source) const;

		Fixed				operator++(int);
		Fixed&				operator++(void);
		Fixed				operator--(int);
		Fixed& 				operator--(void);

		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed const&	max(Fixed const& a, Fixed const& b);

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
