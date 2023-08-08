/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:26:28 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/08 16:22:41 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	general_memory_init(t_general *general)
{
	int	i;

	pthread_mutex_init(&general->print_mutex, NULL);
	pthread_mutex_init(&general->operation_mutex, NULL);
	pthread_mutex_init(&general->time_mutex, NULL);
	general->forks = malloc(sizeof(pthread_mutex_t) * general->nb_philo);
	if (!general->forks)
		return (printf("Error : Malloc failed\n"), 0);
	i = -1;
	while (++i < general->nb_philo)
		pthread_mutex_init(&general->forks[i], NULL);
	general->stop = 0;
	return (1);
}

int	personnal_memory_init(t_general *general, t_personnal *philo, int i)
{
	philo->id = i + 1;
	philo->general = general;
	philo->meal_counter = 0;
	philo->last_meal = 0;
	if (general->nb_philo == 1)
		philo->left_fork = &general->forks[i];
	else
	{
		philo->left_fork = &general->forks[i];
		philo->right_fork = &general->forks[(i + 1) % general->nb_philo];
	}
	return (1);
}

int	structs_init(t_general *general)
{
	int	i;

	general->start_time = -1;
	if (!general_memory_init(general))
		return (0);
	general->philo = malloc(sizeof(t_personnal) * general->nb_philo);
	if (!general->philo)
		return (printf("Error: malloc failed\n"), 0);
	i = -1;
	while (++i < general->nb_philo)
	{
		if (!personnal_memory_init(general, &general->philo[i], i))
			return (0);
	}
	return (1);
}
