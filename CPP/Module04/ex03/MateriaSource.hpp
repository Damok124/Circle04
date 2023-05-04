/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:16 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/04 14:38:36 by zharzi           ###   ########.fr       */
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

					void	learnMateria(AMateria*);
				AMateria*	createMateria(std::string const & type);

	private :
				AMateria* memory[4];//Ces dernières ne sont pas forcément uniques.
};

#endif

/*
• createMateria(std::string const & type)
Retourne une nouvelle Materia. Celle-ci est une copie de celle apprise précédem-
ment par la MateriaSource et dont le type est le même que celui passé en para-
mètre. Retourne 0 si le type est inconnu.

En bref, votre MateriaSource doit pouvoir apprendre des "modèles" de Materias
afin de les recréer à volonté. Ainsi, vous serez capable de générer une nouvelle Materia à
partir de son type sous forme de chaîne de caractères.
*/
