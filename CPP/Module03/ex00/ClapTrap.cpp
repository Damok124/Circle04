/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/27 11:08:33 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(ClapTrap const& source)
{
	*this = source;
	return ;
}

// ClapTrap& ClapTrap::operator=(ClapTrap const& source)
// {
// 	return (source);
// }

ClapTrap::~ClapTrap()
{
}

// std::ostream& operator<<(std::ostream & out, ClapTrap const& inst)
// {
// 	out << inst.toFloat();
// 	return (out);
// }

// bool ClapTrap::operator>(ClapTrap const& source) const
// {
// 	return (getRawBits() > source.getRawBits());
// }

// bool ClapTrap::operator<(ClapTrap const& source) const
// {
// 	return (getRawBits() < source.getRawBits());
// }

// bool ClapTrap::operator>=(ClapTrap const& source) const
// {
// 	return (getRawBits() >= source.getRawBits());
// }

// bool ClapTrap::operator<=(ClapTrap const& source) const
// {
// 	return (getRawBits() <= source.getRawBits());
// }

// bool ClapTrap::operator==(ClapTrap const& source) const
// {
// 	return (getRawBits() == source.getRawBits());
// }

// bool ClapTrap::operator!=(ClapTrap const& source) const
// {
// 	return (getRawBits() != source.getRawBits());
// }

// ClapTrap ClapTrap::operator+(ClapTrap const& source) const
// {
// 	ClapTrap inst;
// 	inst._rawBits = getRawBits() + source.getRawBits();
// 	return (inst);
// }

// ClapTrap ClapTrap::operator-(ClapTrap const& source) const
// {
// 	ClapTrap inst;
// 	inst._rawBits = getRawBits() - source.getRawBits();
// 	return (inst);
// }

// ClapTrap ClapTrap::operator*(ClapTrap const& source) const
// {
// 	ClapTrap inst(toFloat() * source.toFloat());
// 	return (inst);
// }

// ClapTrap ClapTrap::operator/(ClapTrap const& source) const
// {
// 	ClapTrap inst;
// 	if (source.getRawBits() != 0)
// 	{
// 		inst.setRawBits((toFloat() / source.toFloat()) * (1 << _eight));
// 		return (inst);
// 	}
// 	std::cout << "Division by 0 is forbidden" << std::endl;
// 	inst.setRawBits(0);
// 	return (inst);
// }

// ClapTrap& ClapTrap::operator++(void)
// {
// 	setRawBits(getRawBits() + 1);
// 	return (*this);
// }

// ClapTrap ClapTrap::operator++(int)
// {
// 	ClapTrap tmp(*this);
// 	setRawBits(getRawBits() + 1);
// 	return (tmp);
// }

// ClapTrap& ClapTrap::operator--(void)
// {
// 	setRawBits(getRawBits() - 1);
// 	return (*this);
// }

// ClapTrap ClapTrap::operator--(int)
// {
// 	ClapTrap tmp(*this);
// 	setRawBits(getRawBits() - 1);
// 	return (tmp);
// }

