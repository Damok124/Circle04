/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 23:19:55 by zharzi            #+#    #+#             */
/*   Updated: 2023/05/05 15:55:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

struct s_floor {
	AMateria*		item;
	struct s_floor*	next;
} typedef t_floor;

class Character : public ICharacter
{
	public:
							Character();
							Character(std::string name);
							Character(Character const& source);
							Character& operator=(Character const& source);
							~Character();

		void				setName(std::string const name);
		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		void				addOnFloor(AMateria* elem);

	private :
		std::string			name;
		AMateria*			inventory[4];
		t_floor*			floor;
};

#endif

