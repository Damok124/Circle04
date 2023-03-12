/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 07:54:05 by zharzi            #+#    #+#             */
/*   Updated: 2023/03/12 18:30:11 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl inst;

	inst.complain("ERRO");
	inst.complain("DEBUG");
	inst.complain("");
	inst.complain("INFO");
	inst.complain("\0");
	inst.complain("WARNING");
	inst.complain("\n");
	inst.complain("ERROR");
	inst.complain("DEBUGINFO");
	inst.complain("debug");
	return (0);
}
