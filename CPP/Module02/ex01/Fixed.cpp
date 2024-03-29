/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/20 07:48:08 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_eight = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(int const integer)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(integer << _eight);
}

Fixed::Fixed(float const floatting)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(floatting * (1 << _eight)));
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
	return ((float)_rawBits / (1 << _eight));
}

int		Fixed::toInt( void ) const
{
	return (_rawBits >> _eight);
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
	out << inst.toFloat();
	return (out);
}
