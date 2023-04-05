/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/05 18:24:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
					ScavTrap();
					ScavTrap(std::string name);
					ScavTrap(ScavTrap const& source);
					ScavTrap& operator=(ScavTrap const& source);
					~ScavTrap();

			void	guardGate();

			void	setHit(int hit);
			void	setEnergy(int energy);
			void	setAttack(int attack);
};

#endif //___________________________________________________________ScavTrap_HPP
