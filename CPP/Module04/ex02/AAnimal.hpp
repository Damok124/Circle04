/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:02 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/25 17:27:40 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
	public:
						AAnimal();
						AAnimal(AAnimal const& source);
						AAnimal& operator=(AAnimal const& source);
				virtual	~AAnimal();

		std::string		getType() const;

				void	setType(std::string const type);

		virtual void	makeSound() const = 0;

	protected:
		std::string		type;
};

#endif
