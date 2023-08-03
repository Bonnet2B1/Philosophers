/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_simulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:43:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/03 20:01:13 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int terminate_simulation(t_general_memory *g)
{
	int i;

	while (g->stop == 0)
		;
	i = -1;
	while (++i < g->nb_philo)
		if (pthread_join(g->p[i].thread, NULL) != 0)
			return (printf("Error: pthread_join failed\n"), 0);
	if (pthread_join(g->monitoring_thread, NULL) != 0)
		return (printf("Error: pthread_join failed\n"), 0);
	pthread_mutex_destroy(&g->print_mutex);
	pthread_mutex_destroy(&g->fork_mutex);
	pthread_mutex_destroy(&g->print_mutex);
	g = ft_freeall(g);
	return (1);
}