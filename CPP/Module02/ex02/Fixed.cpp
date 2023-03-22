/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/22 07:52:44 by zharzi           ###   ########.fr       */
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
	std::cout << "test " << integer << std::endl;
	std::cout << "test " << _rawBits << std::endl;
}

Fixed::Fixed(float const floatting)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(floatting * (1 << _eight)));
	std::cout << "test " << floatting << std::endl;
	std::cout << "test " << _rawBits << std::endl;
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

bool Fixed::operator>(Fixed const& source)
{
	return (getRawBits() > source.getRawBits());
}

bool Fixed::operator<(Fixed const& source)
{
	return (getRawBits() < source.getRawBits());
}

bool Fixed::operator>=(Fixed const& source)
{
	return (getRawBits() >= source.getRawBits());
}

bool Fixed::operator<=(Fixed const& source)
{
	return (getRawBits() <= source.getRawBits());
}

bool Fixed::operator==(Fixed const& source)
{
	return (getRawBits() == source.getRawBits());
}

bool Fixed::operator!=(Fixed const& source)
{
	return (getRawBits() != source.getRawBits());
}

Fixed Fixed::operator+(Fixed const& source)
{
	Fixed inst;
	inst._rawBits = getRawBits() + source.getRawBits();
	return (inst);
}

Fixed Fixed::operator-(Fixed const& source)
{
	Fixed inst;
	inst._rawBits = getRawBits() - source.getRawBits();
	return (inst);
}

Fixed Fixed::operator*(Fixed const& source)
{
	Fixed inst;
	inst.setRawBits(getRawBits() * source.getRawBits());
	return (inst);
}

Fixed Fixed::operator/(Fixed const& source)
{
	Fixed inst;
	if (source.getRawBits() != 0)
	{
		inst.setRawBits(getRawBits() / source.getRawBits());
		return (inst);
	}
	std::cout << "Error : you tried to divide by 0" << std::endl;
	inst.setRawBits(0);
	return (inst);
}

Fixed& Fixed::operator++(void)
{
	setRawBits(getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	setRawBits(getRawBits() + 1);
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	setRawBits(getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	setRawBits(getRawBits() - 1);
	return (tmp);
}

Fixed&	min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

Fixed const&	min(Fixed const&a, Fixed const&b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

Fixed const&	max(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

