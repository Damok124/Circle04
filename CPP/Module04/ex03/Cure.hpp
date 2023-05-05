/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 15:55:34 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : virtual public AMateria {
	public :
					Cure();
					Cure(Cure const& source);
					Cure& operator=(Cure const& source);
					~Cure();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
