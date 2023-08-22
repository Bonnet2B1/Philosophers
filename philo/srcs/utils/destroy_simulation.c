/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:43:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/17 16:44:39 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_simulation(t_general *general)
{
	int	i;

	pthread_mutex_destroy(&general->print_mutex);
	pthread_mutex_destroy(&general->stop_mutex);
	pthread_mutex_destroy(&general->time_mutex);
	pthread_mutex_destroy(&general->nb_philo_who_has_finished_mutex);
	i = -1;
	while (++i < general->nb_philo)
	{
		pthread_mutex_destroy(&general->forks[i]);
		pthread_mutex_destroy(&general->philo[i].gonna_die_at_mutex);
		pthread_mutex_destroy(&general->philo[i].meal_counter_mutex);
	}
	general = ft_freeall(general);
	return (1);
}
