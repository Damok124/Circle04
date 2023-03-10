/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:22:03 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/10 01:09:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
// # include <string>


class Weapon {
	public:
						Weapon();
						Weapon(std::string type);
						~Weapon();

		const std::string&	getType() const;

		void			setType(std::string new_type);

	private:
		std::string		type;
};

#endif
