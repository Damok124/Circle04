/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 18:23:01 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "Cure.hpp"
# include "ICharacter.hpp"

class Ice : virtual public AMateria {
	public :
					Ice();
					Ice(Ice const& source);
					Ice& operator=(Ice const& source);
					~Ice();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
