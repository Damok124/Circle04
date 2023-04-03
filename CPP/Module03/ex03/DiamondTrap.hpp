/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/03 17:23:17 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
					DiamondTrap();
					DiamondTrap(std::string name);
					DiamondTrap(DiamondTrap const& source);
					DiamondTrap& operator=(DiamondTrap const& source);
					~DiamondTrap();

			// void	whoAmI();//Cette fonction membre affichera à la fois son nom et le nom de son sous-objet ClapTrap.

	// private:
		// std::string	Name;//??? -Name, son nom, qui sera passé en paramètre d’un constructeur
		// ClapTrap::Name;//??? -Claptrap::name (paramètre du constructeur suivi du suffixe "_clap_name")

		// Hit points (FragTrap)
		// Energy points (ScavTrap)
		// Attack damage (FragTrap)
		// attack() (Scavtrap)
};

/*
Bien sûr, le sous-objet Claptrap du DiamondTrap ne sera créé qu’une seule et unique
fois. Oui, il existe un moyen de faire cela.
Encore une fois, enrichissez vos tests.
*/

#endif //________________________________________________________DiamondTrap_HPP
