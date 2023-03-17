/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/17 16:06:56 by zharzi           ###   ########.fr       */
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

/*
• Un constructeur prenant un entier constant en paramètre et qui convertit celui-
ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à 8
comme dans l’exercice 00.//done

• Un constructeur prenant un flottant constant en paramètre et qui convertit
celui-ci en virgule fixe. Le nombre de bits de la partie fractionnaire est initialisé à
8 comme dans l’exercice 00.//done

• Une fonction membre float toFloat( void ) const;
qui convertit la valeur en virgule fixe en nombre à virgule flottante.

• Une fonction membre int toInt( void ) const;
qui convertit la valeur en virgule fixe en nombre entier.
*/
