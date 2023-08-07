/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:36:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/07 20:07:21 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
le temps qui s'est écoulé depuis le dernier repas
get_time() - general->start_time - last_meal

 get_time				start			l_meal  mtn
	|					|           		|     |
*/

int	a_philosopher_is_dead(t_personnal *philo)
{
	if (philo->last_meal - philo_age(philo) >= philo->general->time_to_sleep)
	{
		print_message("died", philo);
		pthread_mutex_lock(&philo->general->print_mutex);
		return (1);
	}
	return (0);
}

int	all_philosophers_ate_enough(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->nb_philo)
		if (general->philo[i].meal_counter < general->min_meal)
			return (0);
	return (pthread_mutex_lock(&general->print_mutex), 1);
}

void	*monitoring(t_general *general)
{
	int	i;

	while (general->start_time == -1)
		;
	while (1)
	{
		i = -1;
		while (++i < general->nb_philo)
		{
			if (a_philosopher_is_dead(&general->philo[i])
				|| all_philosophers_ate_enough(general))
			{
				general->stop = 1;
				return (NULL);
			}
		}
	}
	return (NULL);
}

int	begin_monitoring(t_general *general)
{
	if (pthread_create(&general->monitoring_thread, NULL, (void *)monitoring,
			general) != 0)
		return (printf("Error: pthread_create failed\n"), 0);
	return (1);
}
