/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:34:45 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/16 10:48:10 by zharzi           ###   ########.fr       */
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
	pthread_mutex_t	*left;
	pthread_mutex_t	right;
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

void	*ft_routine(void *arg)
{
	(void)arg;

	return (NULL);
}

/*
void	*ft_routine(void *arg)
{
	pthread_mutex_lock((pthread_mutex_t *)arg);
	printf("lol%ld\n", pthread_self());
	pthread_mutex_unlock((pthread_mutex_t *)arg);
	(void)arg;

	return (NULL);
}
*/

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

// typedef struct s_context {
// 	int				life_time;
// 	int				meal_time;
// 	int				rest_time;
// 	int				meals_max;
// 	int				members;
// 	t_philo			*philos;
// }					t_context;

// typedef struct s_philo {
// 	pthread_t		philo;
// 	int				id;
// 	int				alive;
// 	pthread_mutex_t	*left;
// 	pthread_mutex_t	right;
// 	t_context		context;
// }					t_philo;

// t_context ft_init_context(int ac, char *argv)
// {
// 	t_context	context;
// 	int			check;

// 	check = 1;
// 	context.life_time = ft_atoi_safe(argv[1], &check);
// 	context.meal_time = ft_atoi_safe(argv[2], &check);
// 	context.rest_time = ft_atoi_safe(argv[3], &check);
// 	if (ac == 5)
// 		context.meals_max = ft_atoi_safe(argv[4], &check);
// 	else
// 		context.meals_max = -1;
// 	//reste à initialiser les philos
// }
/*
t_philo	ft_set_philo(int *tab, int ac, int i, t_philo *prev)
{
	t_philo			philo;

	philo.id = i;
	philo.alive = 1;
	pthread_mutex_init(&philo.right, NULL);
	philo.right = &prev->left;
	// printf("left %d, %p\n", i, &philo.left);
	// printf("right%d, %p\n", i, philo.right);
	///incomplet
	(void)tab;//valeurs
	(void)ac;//voir si nombre de repas
	return (philo);
}
*/
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

void	ft_init_philos(t_philo *lst, int *values, int ac)//to complete
{
	t_philo	*first;
	int	i;

	first = lst;
	i = 0;
	while (lst)
	{
		i++;
		lst->id	= i;
		lst->alive = 1;
		if (lst->next)
			lst->left = &lst->next->right;
		else if (values[PHILOSOPHERS] > 1)
			lst->left = &first->right;
		lst = lst->next;
	}
	(void)ac;//pour plus tard
}

void	ft_set_philos(t_philo *philos, int *values, int ac)
{
	ft_init_forks(philos);
	ft_init_philos(philos, values, ac);
}

void	ft_philo(t_philo *philos, int *values, int ac)
{
	ft_set_philos(philos, values, ac);
	ft_unset_philos(philos);


	/*
	i = -1;
	pthread_mutex_init(&forks, NULL);
	while (++i < values[PHILOSOPHERS])
	{
		pthread_create(&philosophers[i], NULL, ft_routine, &forks);
	}
	i = values[FORKS];
	while (--i >= 0)
		pthread_join(philosophers[i], NULL);
	i = values[FORKS];
	pthread_mutex_destroy(&forks);
	*/
}

/*
void	*ft_routine(void *arg)
{
	pthread_mutex_lock((pthread_mutex_t *)arg);
	printf("lol%ld\n", pthread_self());
	pthread_mutex_unlock((pthread_mutex_t *)arg);
	(void)arg;

	return (NULL);
}

void	ft_philo(int *values, int ac)
{
	int	i;
	pthread_mutex_t	forks;
	pthread_t		philosophers[values[PHILOSOPHERS]];
	(void)values;
	(void)ac;

	i = -1;
	pthread_mutex_init(&forks, NULL);
	while (++i < values[PHILOSOPHERS])
	{
		pthread_create(&philosophers[i], NULL, ft_routine, &forks);
	}
	i = values[FORKS];
	while (--i >= 0)
		pthread_join(philosophers[i], NULL);
	i = values[FORKS];
	pthread_mutex_destroy(&forks);
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

/*
// Chaque thread comptera TIMES_TO_COUNT fois
#define TIMES_TO_COUNT 21000

#define NC	"\e[0m"
#define YELLOW	"\e[33m"
#define BYELLOW	"\e[1;33m"
#define RED	"\e[31m"
#define GREEN	"\e[32m"

// Structure pour contenir le compte ainsi que le mutex qui
// protegera l'accès à cette variable.
typedef	struct s_counter
{
	pthread_mutex_t	count_mutex;
	unsigned int	count;
} t_counter;

void	*thread_routine(void *data)
{
	// Chaque thread commence ici
	pthread_t	tid;
	t_counter	*counter; // pointeur vers la structure dans le main
	unsigned int	i;

	tid = pthread_self();
	counter = (t_counter *)data;
	// On imprime le compte avant que ce thread commence
	// a itérer. Pour lire la valeur de count, on verrouille le
	// mutex.
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [%ld]: compte au depart = %u.%s\n", YELLOW, tid, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	i = 0;
	while (i < TIMES_TO_COUNT)
	{
		// On itere TIMES_TO_COUNT fois
		// On verouille le mutex le temps
		// d'incrementer le compte
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
		i++;
	}
	// On imprime le compte final au moment ou ce thread
	// a termine son propre compte en verouillant le mutex
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [%ld]: Compte final = %u.%s\n", BYELLOW, tid, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	return (NULL); // Thread termine ici.
}

int	main(void)
{
	pthread_t	tid1;
	pthread_t	tid2;
	t_counter	counter;

	counter.count = 0;
	pthread_mutex_init(&counter.count_mutex, NULL);
	printf("Main: Le compte attendu est de %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);
	pthread_create(&tid1, NULL, thread_routine, &counter);
	printf("Main: Creation du premier thread [%ld]\n", tid1);
	pthread_create(&tid2, NULL, thread_routine, &counter);
	printf("Main: Creation du second thread [%ld]\n", tid2);

	pthread_join(tid1, NULL);
	printf("Main: Union du premier thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Union du second thread [%ld]\n", tid2);




	if (counter.count != (2 * TIMES_TO_COUNT))
		printf("%sMain: ERREUR ! Le compte est de %u%s\n",
					RED, counter.count, NC);
	else
		printf("%sMain: OK. Le compte est de %u%s\n",
					GREEN, counter.count, NC);

	pthread_mutex_destroy(&counter.count_mutex);
	return (0);
}
*/
