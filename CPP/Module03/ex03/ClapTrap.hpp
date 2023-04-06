/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/06 17:07:59 by zharzi           ###   ########.fr       */
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

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHit(void) const;
		int			getEnergy(void) const;
		int			getAttackDamage(void) const;

		void		setName(std::string name);
		void		setHit(int hit);
		void		setEnergy(int energy);
		void		setAttackDamage(int attack);

	protected:
		std::string	Name;
		int			Hit;
		int			Energy;
		int			AttackDamage;
};

#endif //___________________________________________________________ClapTrap_HPP