/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/02 00:17:11 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(t_personnal_memory *p)
{
	while (1)
	{
		philo_eat(p);
		philo_sleep_n_think(p);
	}
	return (NULL);
}

int	begin_routine(t_general_memory *g)
{
	int i;

	i = -1;
	pthread_mutex_init(&g->print_mutex, NULL);
	while (++i < g->nb_philo)
	{
		if (pthread_create(&g->p[i].thread, NULL, (void *)routine, (void *)&g->p[i]) != 0)
			return (printf("Error: pthread_create failed\n"), 0);
	}
	while (1)
	if (g->stop)
		return (0);
	return (1);
}

void monitoring(t_general_memory *g)
{
	printf("Monitoring start\n");
	while(1)
	{
		if (a_philosopher_is_dead(g) || all_philosophers_ate_enough(g))
		{
			pthread_mutex_lock(&g->print_mutex);
			g->stop = 1;
		}
	}
}

int	begin_monitoring(t_general_memory *g)
{
	if (pthread_create(&g->monitoring_thread, NULL, (void *)monitoring, (void *)&g) != 0)
		return (printf("Error: pthread_create failed\n"), 0);
	return (1);
}

int close_routine(t_general_memory *g)
{
	int i;

	i = -1;
	while (++i < g->nb_philo)
	{
		if (pthread_join(g->p[i].thread, NULL) != 0)
			return (printf("Error: pthread_join failed\n"), 0);
	}
	pthread_mutex_destroy(&g->print_mutex);
	return (1);
}

int	main(int argc, char **argv)
{
	t_general_memory g;

	if (!parser(&g, argc, argv) ||
		!structs_init(&g) ||
		!begin_monitoring(&g) ||
		!begin_routine(&g) ||
		!close_routine(&g))
		return (ft_freeall(&g), 0);
	return (ft_freeall(&g), 0);
}