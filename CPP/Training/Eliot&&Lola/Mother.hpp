/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mother.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:48:42 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/27 16:09:51 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTHER_HPP
# define MOTHER_HPP
#include <iostream>

class Daughter;

class Mother
{
	public:
		Mother();
		Mother(int age, char eye_color);
		virtual ~Mother();

		int getAge(void) const;
		char getEyeColor(void) const;

		virtual void	job();

		void	argue(Daughter& girl);

	protected:
		int		age;
		char	eye_color;
};

#endif //_________________________________________________________MOTHER.HPP
