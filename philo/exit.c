/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mebourge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:11:59 by mebourge          #+#    #+#             */
/*   Updated: 2023/06/05 15:12:00 by mebourge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	clear_state(t_state *state)
{
	int	i;

	if (state->init_fail == 1)
		return (1);
	if (state->forks_m != NULL)
	{
		i = 0;
		while (i < state->amount)
			pthread_mutex_destroy(&state->forks_m[i++]);
		free(state->forks_m);
	}
	if (state->philos != NULL)
	{
		i = 0;
		while (i < state->amount)
		{
			pthread_mutex_destroy(&state->philos[i].mutex);
			pthread_mutex_destroy(&state->philos[i++].eat_m);
		}
		free(state->philos);
	}
	pthread_mutex_destroy(&state->write_m);
	pthread_mutex_destroy(&state->somebody_dead_m);
	return (1);
}

int	exit_error(char const *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (1);
}
