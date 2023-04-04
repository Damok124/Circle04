/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/04 18:28:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
					ScavTrap();
					ScavTrap(std::string name);
					ScavTrap(ScavTrap const& source);
					ScavTrap& operator=(ScavTrap const& source);
					~ScavTrap();

			void	guardGate();

			void	setName(std::string name);
			void	setHit(void);
			void	setEnergy(void);
			void	setAttack(void);
};

#endif //___________________________________________________________ScavTrap_HPP
