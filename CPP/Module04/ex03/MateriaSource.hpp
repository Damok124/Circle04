/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 18:22:41 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
					MateriaSource();
					MateriaSource(MateriaSource const& source);
					MateriaSource& operator=(MateriaSource const& source);
					~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);

	private :
		AMateria*	memory[4];
};

#endif
