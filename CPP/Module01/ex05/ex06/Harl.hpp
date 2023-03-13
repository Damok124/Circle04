/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:55:49 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/12 22:42:16 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
	public:
				Harl();
				~Harl();
		void	complain( std::string level );
	private:
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );
		std::string	_level[4];
		void		(Harl::*message[4])(void);
};
