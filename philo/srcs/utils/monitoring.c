/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:36:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/03 20:01:01 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
le temps qui s'est écoulé depuis le dernier repas
get_time() - g->start_time - last_meal

 get_time			  start		   l_meal  mtn
	|					|             |     |
*/

int a_philosopher_is_dead(t_personnal_memory *p)
{
	pthread_mutex_lock(&p->g->time_mutex);
	if (get_time() - p->g->start_time - p->last_meal >= p->g->tts)
	{
		print_message("died", p);
		pthread_mutex_lock(&p->g->print_mutex);
		pthread_mutex_unlock(&p->g->time_mutex);
		return (1);
	}
	pthread_mutex_unlock(&p->g->time_mutex);
	return (0);
}

int all_philosophers_ate_enough(t_general_memory *g)
{
	int i;

	i = -1;
	while (++i < g->nb_philo)
		if (g->p[i].meal < g->min_meal)
			return (0);
	pthread_mutex_lock(&g->print_mutex);
	return (1);
}

void *monitoring(t_general_memory *g)
{
	int i;
	while(g->stop == 0)
	{
		i = -1;
		while (++i < g->nb_philo && g->stop == 0)
		{
			if (a_philosopher_is_dead(&g->p[i]) || all_philosophers_ate_enough(g))
			{
				g->stop = 1;
				return (NULL);
			}
		}
	}
	return (NULL);
}

int	begin_monitoring(t_general_memory *g)
{
	pthread_mutex_init(&g->print_mutex, NULL);
	pthread_mutex_init(&g->fork_mutex, NULL);
	pthread_mutex_init(&g->time_mutex, NULL);
	if (pthread_create(&g->monitoring_thread, NULL, (void *)monitoring, g) != 0)
		return (printf("Error: pthread_create failed\n"), 0);
	return (1);
}
