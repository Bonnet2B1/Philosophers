/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:24:38 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/10 17:37:36 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_personnal	*philo;

	philo = (t_personnal *)arg;
	while (philo->general->start_time == -1)
		;
	if (philo->general->nb_philo == 1)
	{
		print_message("has taken a fork", philo);
		ft_usleep(philo->general->time_to_die);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		ft_usleep(philo->general->time_to_eat / 10);
	while (philo->general->a_philo_is_dead == 0)
	{
		philo_take_forks(philo);
		philo_eat(philo);
		if (philo->general->min_meal != -1
			&& philo->meal_counter >= philo->general->min_meal)
			return (NULL);
		philo_sleep_n_think(philo);
	}
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
