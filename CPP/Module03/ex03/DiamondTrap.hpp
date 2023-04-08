/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 18:09:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : virtual public ClapTrap, virtual public ScavTrap, virtual public FragTrap {
	public:
						DiamondTrap();
						DiamondTrap(std::string name);
						DiamondTrap(DiamondTrap const& source);
						DiamondTrap& operator=(DiamondTrap const& source);
						~DiamondTrap();

			void		setName(std::string name);
			std::string	getName(void) const;

			void		whoAmI();

			using		ScavTrap::attack;

	private:
		std::string	Name;

};

#endif //________________________________________________________DiamondTrap_HPP
