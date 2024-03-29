/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 07:18:41 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/23 19:18:57 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	public:
					Brain();
					Brain(Brain const& source);
					Brain& operator=(Brain const& source);
					~Brain();

		void		setIdea(std::string const str, int i);
		std::string	getIdea(int i) const;

		void		showAllIdeas();
	private:
		std::string ideas[100];
};

#endif
