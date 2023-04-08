/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:27:55 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/07 17:47:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
					FragTrap();
					FragTrap(std::string name);
					FragTrap(FragTrap const& source);
					FragTrap& operator=(FragTrap const& source);
					~FragTrap();

			void	highFivesGuys(void);

			void	setHit(unsigned int hit);
			void	setEnergy(unsigned int energy);
			void	setAttackDamage(unsigned int attack);
};

#endif //___________________________________________________________FragTrap_HPP
