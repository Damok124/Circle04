/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:55:49 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 16:55:20 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl {
	public:

							Harl();
							~Harl();

		void				complain( std::string level );

		std::string const	getTitle( int index ) const;
		void 				setTitle( int index, std::string title );

	private:

		void				debug( void );
		void				info( void );
		void				warning( void );
		void				error( void );

		void				(Harl::*_mode[4])(void);
		std::string			_title[4];
};
