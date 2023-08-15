/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:24:38 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/15 21:23:44 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	befor_start(t_personnal *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->general->time_mutex);
		if (philo->general->start_time != -1)
		{
			pthread_mutex_unlock(&philo->general->time_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->general->time_mutex);
		usleep(100);
	}
	if (philo->general->nb_philo == 1)
	{
		print_message("has taken a fork", philo);
		ft_usleep(philo->general->time_to_die, philo->general);
		return (0);
	}
	if (philo->id % 2 != 0)
		ft_usleep(philo->general->time_to_eat / 2, philo->general);
	return (1);
}

void	*routine(void *arg)
{
	t_personnal	*philo;

	philo = (t_personnal *)arg;
	if (befor_start(philo) != 0)
	{
		while (stop_checker(philo->general) == 0)
		{
			philo_take_forks(philo);
			philo_eat(philo);
			philo_sleep_n_think(philo);
		}
	}
	pthread_mutex_lock(&philo->general->nb_philo_who_has_finished_mutex);
	philo->general->nb_philo_who_has_finished++;
	pthread_mutex_unlock(&philo->general->nb_philo_who_has_finished_mutex);
	return (NULL);
}

int	begin_routine(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->nb_philo)
		if (pthread_create(&general->philo[i].thread, NULL, routine,
				&general->philo[i]) != 0)
			return (printf("Error: pthread_create failed\n"), 0);
	return (1);
}
