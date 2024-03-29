/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/17 15:15:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
							Fixed();
							Fixed(Fixed const& source);
							Fixed& operator=(Fixed const& source);
							~Fixed();

		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
	private:
		int					_rawBits;
		static int const	_eight;
};

#endif //______________________________________________________________FIXED_HPP
