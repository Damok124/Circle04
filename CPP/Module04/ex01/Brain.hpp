/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:05:59 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/11 20:33:58 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Brain {
	public :
					Brain();
					Brain(Brain const & source);
					Brain& operator=(Brain const & source);
					~Brain();

		void		setIdeas(std::string idea, int i);
		std::string	getIdeas(int i) const;

	private :
		std::string	ideas[100];
}
