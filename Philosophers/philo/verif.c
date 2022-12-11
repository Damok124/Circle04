/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:34:45 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/11 22:25:30 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

//number_of_philosophers
//time_to_die
//time_to_eat
//time_to_sleep
//[number_of_times_each_philosopher_must_eat]

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi_safe(const char *nptr, int *check)
{
	long int i;
	int k;

	i = 0;
	k = 0;
	if (nptr)
	{
		while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
			nptr++;
		if (*nptr == '-')
			k = -1;
		else if (*nptr == '+' || (*nptr >= '0' && *nptr <= '9'))
			k = 1;
		if (*nptr == '-' || *nptr == '+')
			nptr++;
		while (*nptr && *nptr >= '0' && *nptr <= '9')
		{
			i *= 10;
			i += *nptr - '0';
			if ((k * i) > INT_MAX || (k * i) < INT_MIN)
				*check = 0;
			nptr++;
		}
	}
	return (i * k);
}

////////////////////////////////////////////////////////////////////

int	ft_check_if_pos_int(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv && argv[i])
	{
		if (argv[i][j] == '+')
			j++;
		if (!ft_isdigit(argv[i][j]))
			return (0);
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j])
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

int	ft_check_if_overflow(char **argv)
{
	int	check;
	int	i;

	i = 0;
	check = 1;
	while (argv && argv[i])
	{
		ft_atoi_safe(argv[i], &check);
		if (!check)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(int ac, char **argv)
{
	if (ac != 4 || !ft_check_if_pos_int(argv) || !ft_check_if_overflow(argv))
		return (0);
	return (1);
}
/*
void	ft_routine()
{
	//prends les deux fourchettes
	//mange
	//dort
	//pense;
}
*/
void	ft_philo(int philo, int	lifetime, int eat_time, int	sleep_time)
{
	(void)philo;
	(void)lifetime;
	(void)eat_time;
	(void)sleep_time;
	//nombre de fourchettes = nombre de philo
}

int	main(int ac, char **argv)
{
	int	check;
	int	tab[4];
	int	i;

	i = 0;
	check = 1;
	if (ft_check_args(ac - 1, argv + 1))//ajouter le dernier arg au parsing
	{
		while (i < 4)
		{
			tab[i] = ft_atoi_safe(argv[i + 1], &check);
			i++;
		}
		if (ft_atoi_safe(argv[1], &check) >= 1)
			ft_philo(tab[0], tab[1], tab[2], tab[3]);
		else
			printf("Bring more philosophers!\n");
	}
	else
		printf("Wrong arguments.\n");
	return (0);
}
