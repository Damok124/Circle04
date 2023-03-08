/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2023/03/08 16:33:20 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/08 20:10:31 by zharzi           ###   ########.fr       */
=======
/*   Created: 2023/03/08 09:42:36 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/08 11:50:10 by zharzi           ###   ########.fr       */
>>>>>>> 0627db3 (before)
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie *inst = new Zombie;

	inst->setName(name);
	return (inst);
}
