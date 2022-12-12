/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:34:45 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/12 19:05:54 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define PHILOSOPHERS 0
#define LIFETIME 1
#define EATING 2
#define SLEEPING 3
#define LUNCHES 4

//number_of_philosophers
//time_to_die
//time_to_eat
//time_to_sleep
//[number_of_times_each_philosopher_must_eat]

void	ft_to_del(void)
{
	(void)NULL;
}

void	ft_to_dele(void)
{
	(void)NULL;
}

void	ft_to_delet(void)
{
	(void)NULL;
}

void	ft_to_delete(void)
{
	(void)NULL;
}

void	ft_to_dell(void)
{
	(void)NULL;
}

void	ft_to_delll(void)
{
	(void)NULL;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_safe(const char *nptr, int *check)
{
	long int	i;
	int			k;

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

int	ft_check_arg_positive(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '+')
		i++;
	if (!ft_isdigit(arg[i]))
		return (0);
	while (ft_isdigit(arg[i]))
		i++;
	if (arg[i])
		return (0);
	return (1);
}

int	ft_check_arg_overflow(char *arg)
{
	int	check;

	check = 1;
	ft_atoi_safe(arg, &check);
	if (!check)
		return (0);
	return (1);
}

int	ft_check_args(int ac, char **argv)
{
	int	check;
	int	i;

	check = 1;
	i = 0;
	if (ac < 4 || ac > 5)
		return (0);
	while (argv && argv[i])
	{
		if (!ft_check_arg_positive(argv[i]) || !ft_check_arg_overflow(argv[i]))
			return (0);
		if (ft_atoi_safe(argv[0], &check) < 1)
			return (0);
		i++;
	}
	return (1);
}

void	*ft_routine(void * arg)
{
	//prends les deux fourchettes
	//mange
	//dort
	//pense;
	//meurt si sort de la boucle
	(void)arg;
	printf("Nous sommes dans le thread.\n");
	return (NULL);
}

void	ft_philo(int *values, int ac)
{
	(void)values;
	(void)ac;
	pthread_t	t1;

	printf("Avant la création du thread.\n");
	pthread_create(&t1, NULL, ft_routine, NULL);//le dernier arg devra etre la struct fourre-tout
	pthread_join(t1, NULL);
	printf("Après la création du thread.\n");
}

int	main(int ac, char **argv)
{
	int	check;
	int	tab[ac - 1];
	int	i;

	i = 0;
	check = 1;
	if (ft_check_args(ac - 1, argv + 1))
	{
		while (i < (ac - 1))
		{
			tab[i] = ft_atoi_safe(argv[i + 1], &check);
			i++;
		}
		ft_philo(tab, ac - 1);
	}
	else
		printf("Wrong arguments.\n");
	return (EXIT_SUCCESS);
}
