/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:08:39 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/22 17:05:15 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **argv, char **env)
{
	char	*test;

	test = getenv("PATH");
	printf("%s", test);
	(void)ac;
	(void)argv;
	(void)env;
	return (0);
}
