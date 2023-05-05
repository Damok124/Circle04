/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:34:28 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 15:54:23 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string			type;

	public:
							AMateria();
							AMateria(AMateria const& source);
							AMateria& operator=(AMateria const& source);
							AMateria(std::string const & type);
		virtual				~AMateria();

		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
