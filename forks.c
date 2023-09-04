/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:12:02 by mebourge          #+#    #+#             */
/*   Updated: 2023/09/04 15:04:51 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philo *philo)
{
	if (philo->position % 2 == 0)
	{
		pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
		display_message(philo, TYPE_FORK);
		pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
		display_message(philo, TYPE_FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->state->forks_m[philo->rfork]);
		display_message(philo, TYPE_FORK);
		pthread_mutex_lock(&philo->state->forks_m[philo->lfork]);
		display_message(philo, TYPE_FORK);
	}
}

void	clean_forks(t_philo *philo)
{
	display_message(philo, TYPE_SLEEP);
	pthread_mutex_unlock(&philo->state->forks_m[philo->lfork]);
	pthread_mutex_unlock(&philo->state->forks_m[philo->rfork]);
	ft_sleep(philo->state->time_to_sleep);
}
