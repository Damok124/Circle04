/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:21:56 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/10 01:09:43 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"
// # include <string>


class HumanB {
	public:
						HumanB();
						HumanB(std::string name);
						~HumanB();

		std::string const&	getName(void) const;

		void			setName(std::string name);
		void			setWeapon(Weapon& weapon);

		void			attack();

	private:
		std::string		name;
		Weapon*			weapon;
};

#endif
