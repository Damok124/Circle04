/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:32:29 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/11 19:46:36 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//number_of_philosophers time_to_die time_to_eat time_to_sleep
//[number_of_times_each_philosopher_must_eat]

/*
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
int	ft_check_if_pos_int(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv && argv[i])
	{
		if (argv[i][0] == '+')
			j++;
		while (ft_isalnum(argv[i][j]))
			j++;
		if (argv[i][j])
			return (0);
		i++;
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

int	ft_check_quantity(char **argv, int n)
{
	int	i;

	i = 0;
	while (argv && argv[i])
		i++;
	if (i != n)
		return (0);
	return (1);
}

int	ft_check_args(char **argv)
{
	if (!ft_check_quantity(argv, 4) || !ft_check_if_pos_int(argv) \
		|| !ft_check_if_overflow(argv))
		return (0);
	return (1);
}

void	ft_philo(int philo, int	lifetime, int eat_time, int	sleep_time)
{
	;
}

int	main(int ac, char **argv)
{
	int	check;
	int	tab[4];
	int	i;

	i = 0;
	check = 1;
	if (ft_check_args(argv + 1))
	{
		while (i < 4)
			tab[i] = ft_atoi_safe(argv[i + 1], check);
		ft_philo(tab[0], tab[1], tab[2], tab[3]);
	}
	else
		printf("Wrong number of arguments.\n");
	return (0);
}

*/




int	main(int argc, char **argv, char **env)
{
	struct timeval initial_time;
	struct timeval current_time;

	gettimeofday(&initial_time, NULL);
	usleep(1000000);
	gettimeofday(&current_time, NULL);
	printf("sec : %ld, microsec : %ld\n", current_time.tv_sec - initial_time.tv_sec, current_time.tv_usec - initial_time.tv_usec);
	(void)argc;
	(void)argv;
	(void)env;
	return (0);
}

/*
	memset
	printf
	malloc
	free
	write
	usleep
	gettimeofday
pthread_create
pthread_detach
pthread_join
pthread_mutex_init
pthread_mutex_destroy
pthread_mutex_locK
pthread_mutex_unlock
*/
