/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/16 13:03:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_eight = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(Fixed const& source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
	return ;
}

Fixed Fixed::operator=(Fixed const& source)
{
	std::cout << "Copy assignement operator called" << std::endl;
	Fixed inst;
	inst._rawBits = source._rawBits;
	return (inst);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}
