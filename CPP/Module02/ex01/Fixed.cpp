/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/17 16:54:05 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_eight = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(int const integer)
{
	setRawBits(integer);
}

Fixed::Fixed(float const floatting)
{
	toInt(floatting);
}


Fixed::Fixed(Fixed const& source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
	return ;
}

Fixed& Fixed::operator=(Fixed const& source)
{
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &source)
		_rawBits = source.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	return (0);
}

int		Fixed::toInt( void ) const
{
	return (0);
}

int	Fixed::getRawBits( void ) const
{
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}

std::ostream& operator<<(std::ostream & out, Fixed const& inst)
{
	out << inst.getRawBits();
	return (out);
}
