/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:34:45 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/17 21:20:50 by zharzi           ###   ########.fr       */
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

typedef struct s_context {
	int				members;
	int				life_time;
	int				meal_time;
	int				rest_time;
	int				meals_max;
}					t_context;

typedef struct s_philo {
	pthread_t		philo;
	int				id;
	pthread_mutex_t	life;//////////
	int				alive;
	int				meals;///////////
	int				deadline;///////////
	struct timeval	start_time;
	pthread_mutex_t	*left;
	pthread_mutex_t	right;
	pthread_mutex_t	*first;
	pthread_mutex_t	*last;
	pthread_mutex_t	*mut_printf;
	t_context		*context;////////////nouveau
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



////////////////////////////////////////////////////////////////////

int	ft_get_time(struct timeval start)//done
{
	struct timeval	result;
	struct timeval	actual;
	int				time;

	time = 0;
	gettimeofday(&actual, NULL);
	result.tv_sec = actual.tv_sec - start.tv_sec;
	result.tv_usec = actual.tv_usec - start.tv_usec;
	time = (result.tv_sec * 1000) + (result.tv_usec / 1000);
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
	while (1)//liberation des forks quand le philo dort
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
		pthread_mutex_destroy(&lst->life);
		lst->left = NULL;
		lst->first = NULL;
		lst->last = NULL;
		lst = lst->next;
		ft_true_free((void **)&tmp);
	}
}


void	ft_init_mutexes(t_philo *lst)//done
{
	while (lst)
	{
		pthread_mutex_init(&lst->life, NULL);
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

void	ft_init_philos(t_philo *lst, t_context *context, pthread_mutex_t *mut_printf)
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
		else if (context->members > 1)
			lst->left = &tmp->right;
		lst->mut_printf = mut_printf;
		lst->context = context;
		lst->meals = 0;
		lst->deadline = context->life_time;
		lst = lst->next;
	}
}

void	ft_set_philos(t_philo *philos, t_context *context, pthread_mutex_t *mut_printf)
{
	ft_init_mutexes(philos);
	ft_init_philos(philos, context, mut_printf);
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

void	*ft_soul_taking(void *arg)//pas mal
{
	t_philo	*philo;
	t_philo	*tmp;
	int		taken;

	philo = (t_philo *)arg;
	tmp = philo;
	taken = 0;
	while (philo && taken != philo->context->members)
	{
		pthread_mutex_lock(&philo->life);
		if (philo->alive && (taken/* \
			|| (!taken && philo->deadline <= ft_get_time(philo->start_time))*/))
		{
			philo->alive--;
			taken++;
		}
		pthread_mutex_unlock(&philo->life);
		if (philo->next)
			philo = philo->next;
		else
			philo = tmp;
	}
	return (NULL);
}

void	ft_philo(t_philo *philos, t_context *context)
{
	pthread_t		azrael;
	pthread_mutex_t	mut_printf;

	pthread_mutex_init(&mut_printf, NULL);
	ft_set_philos(philos, context, &mut_printf);
	pthread_create(&azrael, NULL, ft_soul_taking, philos);
	ft_put_thread_on_routine(philos);




	ft_join_them_all(philos);
	pthread_join(azrael, NULL);
	pthread_mutex_destroy(&mut_printf);
	ft_unset_philos(philos);
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

t_context	ft_init_context(char **argv, int ac)//done
{
	t_context	context;
	int			check;

	check = 1;
	context.members = ft_atoi_safe(argv[0], &check);
	context.life_time = ft_atoi_safe(argv[1], &check);
	context.meal_time = ft_atoi_safe(argv[2], &check);
	context.rest_time = ft_atoi_safe(argv[3], &check);
	if (ac == 5)
		context.meals_max = ft_atoi_safe(argv[4], &check);
	else
		context.meals_max = -1;
	return (context);
}

int	main(int ac, char **argv)
{
	t_context	context;
	t_philo		*philos;

	philos = NULL;
	if (ft_check_args(ac - 1, argv + 1))
	{
		context = ft_init_context(argv + 1, ac -1);
		philos = ft_init_lst_philo(context.members);
		if (philos)
			ft_philo(philos, &context);
		else
			printf("FAILURE\n");
	}
	else
		printf("Wrong arguments.\n");
	return (EXIT_SUCCESS);
}
