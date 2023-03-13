/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:54:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/13 15:32:12 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl inst;

	std::cout << "test complain(\"WARNING\") :" << std::endl;
	inst.complain("WARNING");
	std::cout << std::endl << "test complain(\"ERROR\") :" << std::endl;
	inst.complain("ERROR");
	std::cout << std::endl << "test complain(\"ERRO\") :" << std::endl;
	inst.complain("ERRO");
	std::cout << std::endl << "test complain(\"DEBUG\") :" << std::endl;
	inst.complain("DEBUG");
	std::cout << std::endl << "test complain(\"\") :" << std::endl;
	inst.complain("");
	std::cout << std::endl << "test complain(\"INFO\") :" << std::endl;
	inst.complain("INFO");
	std::cout << std::endl << "test complain(\"\\0\") :" << std::endl;
	inst.complain("\0");
	std::cout << std::endl << "test complain(\"WARNING \") :" << std::endl;
	inst.complain("WARNING ");
	std::cout << std::endl << "test complain(\"\\n\") :" << std::endl;
	inst.complain("\n");
	std::cout << std::endl << "test complain(\"\\tERROR\") :" << std::endl;
	inst.complain("\tERROR");
	std::cout << std::endl << "test complain(\"DEBUGINFO\") :" << std::endl;
	inst.complain("DEBUGINFO");
	std::cout << std::endl << "test complain(\"debug\") :" << std::endl;
	inst.complain("debug");
	return (0);
}
