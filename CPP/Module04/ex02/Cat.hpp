/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:07 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 18:32:37 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : virtual public AAnimal {
	public:
						Cat();
						Cat(Cat const& source);
						Cat& operator=(Cat const& source);
						~Cat();

		Brain const&	getBrain() const;
		void			setBrain(Brain const& source);
		void			makeSound() const;
		void			setIdea(std::string str, int i);
		void			checkBrain() const;
		void			resetBrain();

	private:
		Brain*			_brain;
};
#endif
