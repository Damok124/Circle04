/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/27 11:08:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <fstream>

class ClapTrap {
	public:
							ClapTrap();
							ClapTrap(ClapTrap const& source);
							// ClapTrap& operator=(ClapTrap const& source);
							~ClapTrap();

		// bool				operator>(ClapTrap const& source) const;
		// bool				operator<(ClapTrap const& source) const;
		// bool				operator>=(ClapTrap const& source) const;
		// bool				operator<=(ClapTrap const& source) const;
		// bool				operator==(ClapTrap const& source) const;
		// bool				operator!=(ClapTrap const& source) const;

		// ClapTrap				operator+(ClapTrap const& source) const;
		// ClapTrap				operator-(ClapTrap const& source) const;
		// ClapTrap				operator*(ClapTrap const& source) const;
		// ClapTrap				operator/(ClapTrap const& source) const;

		// ClapTrap				operator++(int);
		// ClapTrap&				operator++(void);
		// ClapTrap				operator--(int);
		// ClapTrap& 				operator--(void);

	private:
};

std::ostream& operator<<(std::ostream & out, ClapTrap const& inst);

#endif //______________________________________________________________ClapTrap_HPP
