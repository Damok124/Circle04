/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Daughter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:51:59 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/27 16:11:18 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAUGHTER_HPP
# define DAUGHTER_HPP
# include <iostream>
# include "Mother.hpp"

class Daughter : public Mother
{
	public:
		Daughter();
		Daughter(int age, char eye_color, bool tattoo);
		~Daughter();

		virtual void	job();

	private:
		bool tattoo;

};

#endif //__________________________________________________________DAUGHTER_HPP
