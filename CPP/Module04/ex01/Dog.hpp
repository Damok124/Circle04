/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:07 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 18:28:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : virtual public Animal {
	public:
						Dog();
						Dog(Dog const& source);
						Dog& operator=(Dog const& source);
						~Dog();

		Brain const&	getBrain() const;
		void			setBrain(Brain const& source);
		void			makeSound() const;
		void			checkBrain() const;
		void			setIdea(std::string str, int i);
		void			resetBrain();

	private:
		Brain*			_brain;
};
#endif
