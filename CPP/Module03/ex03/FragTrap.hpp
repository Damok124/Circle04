/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:27:55 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/01 08:41:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <fstream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
					FragTrap();
					FragTrap(std::string name);
					FragTrap(FragTrap const& source);
					FragTrap& operator=(FragTrap const& source);
					~FragTrap();

		void		highFivesGuys(void);
};

#endif //___________________________________________________________FragTrap_HPP
