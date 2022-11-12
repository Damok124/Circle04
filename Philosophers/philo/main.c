/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:32:29 by zharzi            #+#    #+#             */
/*   Updated: 2022/11/12 19:22:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
