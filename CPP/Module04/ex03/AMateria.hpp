/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:34:28 by zharzi            #+#    #+#             */
/*   Updated: 2023/04/28 18:26:58 by zharzi           ###   ########.fr       */
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
							virtual ~AMateria();

		std::string const &	getType() const; //Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif

/*
Implémentez les Materias Ice (glace) et Cure (soin) sous forme de classes concrètes.
Utilisez leur noms en minuscules ("ice" pour Ice, "cure" pour Cure) comme types. Bien
sûr, leur fonction membre clone() retournera une nouvelle instance de même type (en
clonant une Materia Ice, on obtient une autre Materia Ice).
Pour ce qui est de la fonction membre use(ICharacter&), elle affichera :
• Ice : "* shoots an ice bolt at <name> *"
• Cure : "* heals <name>’s wounds *"
<name> est le nom du Character (personnage) passé en paramètre. N’affichez pas les
chevrons (< et >).
Quand on assigne une Materia à une autre, copier son type n’a pas
grand intérêt.
*/
