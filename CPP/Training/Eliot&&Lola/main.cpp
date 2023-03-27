/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:04:00 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/27 14:00:45 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Mother.hpp"
#include "Daughter.hpp"

int main(void)
{
	Mother Sylvie(45, 'B');
	Mother* Lilou = new Daughter(15, 'M', false);

	Daughter Cecile(20, 'B', true);

	std::cout << Lilou->getAge() << std::endl;

	Sylvie.job();
	Lilou->job();

	Sylvie.argue(Cecile);

	delete Lilou;
	std::cout << "End" << std::endl;
	return (0);
}
