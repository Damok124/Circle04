/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/01 18:22:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
// # include <fstream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
// # include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap {
	public:
					DiamondTrap();
					DiamondTrap(std::string name);
					DiamondTrap(DiamondTrap const& source);
					DiamondTrap& operator=(DiamondTrap const& source);
					~DiamondTrap();

			// void	guardGate();
};

#endif //________________________________________________________DiamondTrap_HPP
