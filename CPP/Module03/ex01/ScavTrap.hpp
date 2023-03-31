/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/30 15:18:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <fstream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
					ScavTrap();
					ScavTrap(std::string name);
					ScavTrap(ScavTrap const& source);
					ScavTrap& operator=(ScavTrap const& source);
					~ScavTrap();

			void	guardGate();

		// void		attack(const std::string& target);
		// void		takeDamage(unsigned int amount);
		// void		beRepaired(unsigned int amount);

		// std::string	getName(void) const;
		// int			getHit(void) const;
		// int			getEnergy(void) const;
		// int			getAttack(void) const;

		// void		setName(std::string name);
		// void		setHit(int hit);
		// void		setEnergy(int energy);
		// void		setAttack(int attack);

	// private:
	// 	std::string	Name;
	// 	int			Hit;
	// 	int			Energy;
	// 	int			Attack;
};

#endif //___________________________________________________________ScavTrap_HPP
