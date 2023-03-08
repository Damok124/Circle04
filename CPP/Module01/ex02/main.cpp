/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:23:27 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/08 22:17:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Adress of    string is " << &string	<< std::endl;
	std::cout << "Adress of stringPTR is " << stringPTR << std::endl;
	std::cout << "Adress of stringREF is " << &stringREF << std::endl;

	std::cout << "Value of    string is " << string	<< std::endl;
	std::cout << "Value of stringPTR is " << *stringPTR << std::endl;
	std::cout << "Value of stringREF is " << stringREF << std::endl;

	return (0);
}
