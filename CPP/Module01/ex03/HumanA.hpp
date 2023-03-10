/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:21:51 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/10 18:44:38 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {
	public:
						HumanA();
						HumanA(std::string name, Weapon& weapon);
						~HumanA();

		std::string		getName(void) const;

		void			setName(std::string name);

		void			attack();

	private:
		std::string		name;
		Weapon&			weapon;
};

#endif
