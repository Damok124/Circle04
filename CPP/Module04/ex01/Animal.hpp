/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:02 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/09 19:09:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	public:
						Animal();
						Animal(Animal const& source);
						Animal& operator=(Animal const& source);
						~Animal();

		std::string		getType() const;

				void	setType(std::string const type);

		virtual void	makeSound() const;

	protected:
		std::string		type;
};

#endif
