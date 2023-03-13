/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:22:03 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 16:54:31 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {
	public:
							Weapon();
							Weapon(std::string type);
							~Weapon();

		const std::string&	getType() const;

		void				setType(std::string new_type);

	private:
		std::string			type;
};

#endif
