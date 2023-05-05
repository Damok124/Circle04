/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:07 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 18:27:46 by zharzi           ###   ########.fr       */
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
						~Cat();

		void			makeSound() const;

		Brain const&	getBrain() const;
		void			setBrain(Brain const& source);
		void			checkBrain() const;
		void			setIdea(std::string str, int i);
		void			resetBrain();

	private:
		Brain*			_brain;
};
#endif
