/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:07 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/23 20:30:06 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : virtual public Animal {
	public:
						Cat();
						Cat(Cat const& source);
						Cat& operator=(Cat const& source);
				virtual	~Cat();

		virtual void	makeSound() const;

				void	setBrain(Brain const& source);
		Brain const&	getBrain() const;

				void	checkBrain() const;
				void	setIdea(std::string str, int i);

				void	resetBrain();

	private:
				Brain*	_brain;
};
#endif
