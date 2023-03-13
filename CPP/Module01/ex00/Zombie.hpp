/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:13:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 16:51:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <new>

class Zombie {
	public:
						Zombie();
						Zombie( std::string name );
						~Zombie();

		std::string		getName( void ) const;

		void			setName(std::string name);

		void			announce( void );

	private:
		std::string		name;
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif
