/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:20:04 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/28 09:53:09 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : virtual public AMateria {
	public :
							Ice();
							Ice(Ice const& source);
							Ice& operator=(Ice const& source);
					virtual	~Ice();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
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
