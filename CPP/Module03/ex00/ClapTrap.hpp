/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:54:24 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/28 17:13:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <fstream>

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
		int			getAttack(void) const;

		void		setName(std::string name);
		void		setHit(int hit);
		void		setEnergy(int energy);
		void		setAttack(int attack);

	private:
		std::string	Name;
		int			Hit;
		int			Energy;
		int			Attack;
};

std::ostream& operator<<(std::ostream & out, ClapTrap const& inst);/////////////

#endif //___________________________________________________________ClapTrap_HPP
