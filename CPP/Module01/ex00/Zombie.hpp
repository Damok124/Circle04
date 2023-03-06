/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:13:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/06 08:05:16 by zharzi           ###   ########.fr       */
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
		~Zombie();
		void		announce( void );
		Zombie*		newZombie( std::string name );
		void		randomChump( std::string name );
	private:
		std::string	name;
};

#endif
