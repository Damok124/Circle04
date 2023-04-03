/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 08:41:37 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/01 08:42:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <fstream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
					ScavTrap();
					ScavTrap(std::string name);
					ScavTrap(ScavTrap const& source);
					ScavTrap& operator=(ScavTrap const& source);
					~ScavTrap();

			void	guardGate();
};

#endif //___________________________________________________________ScavTrap_HPP
