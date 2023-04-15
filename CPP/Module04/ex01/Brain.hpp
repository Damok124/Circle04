/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:05:59 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/15 18:53:04 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public :
						Brain();
						Brain(Brain const & source);
						Brain& operator=(Brain const & source);
						~Brain();

		void			setOneIdea(std::string idea, int i);
		std::string		getOneIdea(int i) const;
		std::string*	getIdeas();

	private :
		std::string		ideas[100];
};

#endif
