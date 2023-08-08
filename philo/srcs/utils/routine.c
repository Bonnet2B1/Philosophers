/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:24:38 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/08 18:15:20 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_personnal	*philo;

	philo = (t_personnal *)arg;
	if (philo->general->nb_philo == 1)
	{
		print_message("takes a fork", philo);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		usleep(((philo->general->time_to_eat / 10) * 1000));
	while (1)
	{
		philo_take_forks(philo);
		philo_eat(philo);
		philo_sleep_n_think(philo);
	}
	return (NULL);
}

int	begin_routine(t_general *general)
{
	int	i;

	i = -1;
	general->start_time = get_time();
	while (++i < general->nb_philo)
		if (pthread_create(&general->philo[i].thread, NULL, routine,
				&general->philo[i]) != 0)
			return (printf("Error: pthread_create failed\n"), 0);
	return (1);
}
