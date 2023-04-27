/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/27 18:38:27 by zharzi           ###   ########.fr       */
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
					virtual	~Cure();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
	private :
		std::string			type;
};

#endif

/*
Implémentez les Materias Ice (glace) et Cure (soin) sous forme de classes concrètes.

Utilisez leur noms en minuscules ("ice" pour Ice, "cure" pour Cure) comme types



Bien sûr, leur fonction membre clone() retournera une nouvelle instance de même type
(en clonant une Materia Ice, on obtient une autre Materia Ice).

Pour ce qui est de la fonction membre use(ICharacter&), elle affichera :
• Ice : "* shoots an ice bolt at <name> *"
• Cure : "* heals <name>’s wounds *"

*/
