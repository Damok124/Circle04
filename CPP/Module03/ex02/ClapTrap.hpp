/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 16:05:27 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	public:
						ClapTrap();
						ClapTrap(std::string name);
						ClapTrap(ClapTrap const& source);
						ClapTrap& operator=(ClapTrap const& source);
						~ClapTrap();

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHit(void) const;
		unsigned int	getEnergy(void) const;
		unsigned int	getAttackDamage(void) const;

		void			setName(std::string name);
		void			setHit(unsigned int hit);
		void			setEnergy(unsigned int energy);
		void			setAttackDamage(unsigned int attack);

	protected:
		std::string		Name;
		unsigned int	Hit;
		unsigned int	Energy;
		unsigned int	AttackDamage;
};

#endif //___________________________________________________________ClapTrap_HPP
