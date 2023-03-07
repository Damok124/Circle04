/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:13:47 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/06 13:57:03 by zharzi           ###   ########.fr       */
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
					Zombie( std::string name );
		void		announce( void );
		void		setName(std::string name);
		std::string	&getName( void ) const;

	private:
		std::string	name;
};

#endif
