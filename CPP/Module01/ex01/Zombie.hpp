/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:13:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/08 21:40:30 by zharzi           ###   ########.fr       */
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

Zombie* zombieHorde( int N, std::string name );

#endif
