/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:48:02 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/09 01:16:46 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	public:
						WrongAnimal();
						WrongAnimal(WrongAnimal const& source);
						WrongAnimal& operator=(WrongAnimal const& source);
						~WrongAnimal();

		std::string		getType() const;
		void			setType(std::string const type);
		void			makeSound() const;

	protected:
		std::string		type;
};

#endif
