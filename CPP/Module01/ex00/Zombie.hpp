/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:13:47 by zharzi            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/08 18:57:57 by zharzi           ###   ########.fr       */
=======
/*   Updated: 2023/03/08 11:49:51 by zharzi           ###   ########.fr       */
>>>>>>> 0627db3 (before)
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
<<<<<<< HEAD
						Zombie( std::string name );
						~Zombie();

		std::string	getName( void ) const;
=======
						~Zombie();
						Zombie( std::string name );

		std::string&	getName( void ) const;
>>>>>>> 0627db3 (before)

		void			setName(std::string name);

		void			announce( void );

	private:
		std::string	name;
};

<<<<<<< HEAD
void	randomChump( std::string name );
Zombie*	newZombie( std::string name );
=======
Zombie*	newZombie( std::string name );
void	randomChump( std::string name );
>>>>>>> 0627db3 (before)

#endif
