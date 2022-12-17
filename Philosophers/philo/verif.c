/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:34:45 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/16 20:39:39 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define PHILOSOPHERS 0
#define FORKS 0
#define LIFETIME 1
#define EATING 2
#define SLEEPING 3
#define MEALS 4
#define MUTEX pthread_mutex_t

typedef struct s_context {
	int				life_time;
	int				meal_time;
	int				rest_time;
	int				meals_max;
	int				members;
}					t_context;

typedef struct s_philo {
	pthread_t		philo;
	int				id;
	int				alive;
	struct timeval	start_time;
	MUTEX			*left;
	MUTEX			right;
	MUTEX			*first;
	MUTEX			*last;
	MUTEX			*mut_printf;
	struct s_philo	*next;
}					t_philo;

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

////////////////////////////////////////////////////////////////////

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

void	ft_true_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
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

////////////////////////////////////////////////////////////////////

int	ft_get_time(struct timeval start)
{
	struct timeval	result;
	struct timeval	actual;
	int				time;

	time = 0;
	gettimeofday(&actual, NULL);
	result.tv_sec = actual.tv_sec - start.tv_sec;
	result.tv_usec = actual.tv_usec - start.tv_usec;
	time = (result.tv_sec * 1000) + (result.tv_usec / 1000);
	//calcule de la différence de temps entre tv et start_time
	return (time);
}

void	ft_print_msg(t_philo *philo, char *msg)
{
	int	time;

	pthread_mutex_lock(philo->mut_printf);
	time = ft_get_time(philo->start_time);
	printf("%07i %3i %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->mut_printf);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(100000);
		pthread_mutex_lock(philo->first);
		ft_print_msg(philo, "has taken a fork");
		pthread_mutex_lock(philo->last);
		ft_print_msg(philo, "has taken a fork");
		ft_print_msg(philo, "is eating");
		pthread_mutex_unlock(philo->last);
		pthread_mutex_unlock(philo->first);
	}
	return (NULL);
}

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

void	ft_join_them_all(t_philo *lst)//done
{
	while (lst)
	{
		pthread_join(lst->philo, NULL);
		lst = lst->next;
	}
}

void	ft_unset_philos(t_philo *lst)//done
{
	t_philo	*tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = lst;
		pthread_mutex_destroy(&lst->right);
		lst->left = NULL;
		lst = lst->next;
		ft_true_free((void **)&tmp);
	}
}

t_philo	*ft_init_lst_philo(int size)//done
{
	t_philo	*elem;

	if (size)
	{
		elem = (t_philo *)malloc(sizeof(t_philo));
		if (!elem)
			return (NULL);
		elem->next = ft_init_lst_philo(size -1);
		return (elem);
	}
	return (NULL);
}

void	ft_init_forks(t_philo *lst)//done
{
	while (lst)
	{
		pthread_mutex_init(&lst->right, NULL);
		lst->left = NULL;
		lst = lst->next;
	}
}

void	ft_set_handedness(t_philo *lst)//done
{
	while (lst)
	{
		if (lst->id % 2 == 0)
		{
			lst->first = &lst->right;
			lst->last = lst->left;
		}
		else
		{
			lst->first = lst->left;
			lst->last = &lst->right;
		}
		lst = lst->next;
	}
}

void	ft_init_philos(t_philo *lst, int *values, int ac, MUTEX *mut_printf)
{
	t_philo	*tmp;
	int	i;

	tmp = lst;
	i = 0;
	while (lst)
	{
		i++;
		lst->id	= i;
		lst->alive = 1;
		if (lst->next)
			lst->left = &lst->next->right;
		else if (values[PHILOSOPHERS] > 1)
			lst->left = &tmp->right;
		lst->mut_printf = mut_printf;
		lst = lst->next;
	}
	(void)ac;//pour plus tard
}

void	ft_set_philos(t_philo *philos, int *values, int ac, MUTEX *mut_printf)
{
	ft_init_forks(philos);
	ft_init_philos(philos, values, ac, mut_printf);
	ft_set_handedness(philos);
}

void	ft_put_thread_on_routine(t_philo *lst)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	while (lst)
	{
		lst->start_time = tv;
		pthread_create(&lst->philo, NULL, ft_routine, (void *)lst);
		lst = lst->next;
	}
}

void	ft_philo(t_philo *philos, int *values, int ac)
{
	MUTEX	mut_printf;

	pthread_mutex_init(&mut_printf, NULL);
	ft_set_philos(philos, values, ac, &mut_printf);
	ft_put_thread_on_routine(philos);




	ft_join_them_all(philos);
	pthread_mutex_destroy(&mut_printf);
	ft_unset_philos(philos);
}

/*
int	ft_get_time(struct timeval start_time)
{
	struct timeval	tv;
	int				time;

	time = 0;
	gettimeofday(&tv, NULL);

	//calcule de la différence de temps entre tv et start_time
	return (time);
}
*/

int	main(int ac, char **argv)
{
	//t_context	context;
	t_philo	*philos;
	int	check;
	int	tab[ac - 1];
	int	i;

	i = 0;
	check = 1;
	philos = NULL;
	if (ft_check_args(ac - 1, argv + 1))
	{
		while (i < (ac - 1))
		{
			tab[i] = ft_atoi_safe(argv[i + 1], &check);
			i++;
		}
		philos = ft_init_lst_philo(tab[PHILOSOPHERS]);
		if (philos)
			ft_philo(philos, tab, ac - 1);
		else
			printf("FAILURE\n");
	}
	else
		printf("Wrong arguments.\n");
	return (EXIT_SUCCESS);
}
