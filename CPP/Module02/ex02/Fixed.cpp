/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/23 16:03:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_eight = 8;

Fixed::Fixed()
{
	setRawBits(0);
}

Fixed::Fixed(int const integer)
{
	setRawBits(integer << _eight);
}

Fixed::Fixed(float const floatting)
{
	setRawBits(roundf(floatting * (1 << _eight)));
}

Fixed::Fixed(Fixed const& source)
{
	*this = source;
	return ;
}

Fixed& Fixed::operator=(Fixed const& source)
{
	if (this != &source)
		_rawBits = source.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
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

bool Fixed::operator>(Fixed const& source) const
{
	return (getRawBits() > source.getRawBits());
}

bool Fixed::operator<(Fixed const& source) const
{
	return (getRawBits() < source.getRawBits());
}

bool Fixed::operator>=(Fixed const& source) const
{
	return (getRawBits() >= source.getRawBits());
}

bool Fixed::operator<=(Fixed const& source) const
{
	return (getRawBits() <= source.getRawBits());
}

bool Fixed::operator==(Fixed const& source) const
{
	return (getRawBits() == source.getRawBits());
}

bool Fixed::operator!=(Fixed const& source) const
{
	return (getRawBits() != source.getRawBits());
}

Fixed Fixed::operator+(Fixed const& source) const
{
	Fixed inst;
	inst._rawBits = getRawBits() + source.getRawBits();
	return (inst);
}

Fixed Fixed::operator-(Fixed const& source) const
{
	Fixed inst;
	inst._rawBits = getRawBits() - source.getRawBits();
	return (inst);
}

Fixed Fixed::operator*(Fixed const& source) const
{
	Fixed inst(toFloat() * source.toFloat());
	return (inst);
}

Fixed Fixed::operator/(Fixed const& source) const
{
	Fixed inst;
	if (source.getRawBits() != 0)
	{
		inst.setRawBits((toFloat() / source.toFloat()) * (1 << _eight));
		return (inst);
	}
	std::cout << "Division by 0 is forbidden" << std::endl;
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a >= b)
		return (a);
	return (b);
}

Fixed const&	Fixed::min(Fixed const&a, Fixed const&b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

