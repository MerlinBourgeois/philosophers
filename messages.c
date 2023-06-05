/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:12:13 by mebourge          #+#    #+#             */
/*   Updated: 2023/06/05 15:12:14 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char	*get_message(int type)
{
	if (type == TYPE_EAT)
		return ("\e[33m is eating\n");
	else if (type == TYPE_SLEEP)
		return ("\e[34m is sleeping\n");
	else if (type == TYPE_FORK)
		return ("\e[32m has taken a fork\n");
	else if (type == TYPE_THINK)
		return ("\e[35m is thinking\n");
	else if (type == TYPE_OVER)
		return ("\e[31m must eat count reached\n");
	return ("\e[31m died\n");
}

void	display_message(t_philo *philo, int type)
{
	static int	done = 0;

	pthread_mutex_lock(&philo->state->write_m);
	if (!done)
	{
		write(1, "\e[00m", 6);
		ft_putnbr_fd(get_time() - philo->state->start, 1);
		write(1, "\t\e[01m", 7);
		if (type != TYPE_OVER)
			ft_putnbr_fd(philo->position + 1, 1);
		if (type >= TYPE_DIED)
			done = 1;
		write(1, "\t", 1);
		write(1, get_message(type), ft_strlen(get_message(type)));
	}
	pthread_mutex_unlock(&philo->state->write_m);
}
