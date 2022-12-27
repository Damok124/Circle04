/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zharzi <zharzi@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:02:22 by zharzi            #+#    #+#             */
/*   Updated: 2022/12/24 00:13:47 by zharzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_eating(t_philo *philo)
{
	int	forks;

	forks = 0;
	ft_grab_right(philo, &forks);
	if (philo->context.members > 1)
		ft_grab_left(philo, &forks);
	else
		ft_usleep(philo, philo->context.life_time \
			- ft_get_chrono(philo->start_time));
	if (!ft_is_full_or_dead(philo) && philo->context.members > 1)
	{
		pthread_mutex_lock(&philo->life);
		philo->deadline = (long int)ft_get_chrono(philo->start_time) \
			+ (long int)philo->context.life_time + 1;
		pthread_mutex_unlock(&philo->life);
		ft_print_msg(philo, "is eating");
		ft_usleep(philo, philo->context.meal_time);
		pthread_mutex_lock(&philo->life);
		philo->meals++;
		pthread_mutex_unlock(&philo->life);
	}
	return (forks);
}
