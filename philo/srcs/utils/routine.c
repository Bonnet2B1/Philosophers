/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:35:31 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/03 20:05:06 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *arg)
{
	t_personnal_memory	*p;

	p = (t_personnal_memory *)arg;
	pthread_mutex_lock(&p->g->time_mutex);
	if (p->g->start_time == -1)
		p->g->start_time = get_time();
	pthread_mutex_unlock(&p->g->time_mutex);
	// if (p->g->nb_philo == 1)
	// {
	// 	print_message("has taken a fork", p);
	// 	ft_usleep(p->g->ttd);
	// 	return (NULL);
	// }
	
	// test
	pthread_mutex_lock(&p->g->print_mutex);
	printf("Philosopher %d : left fork %p, right fork %p\n", p->id, p->left_fork, p->right_fork);
	pthread_mutex_unlock(&p->g->print_mutex);
	return (NULL);
	// fin du test

	if (p->id % 2 == 0)
		ft_usleep(2);
	while (1)
	{
		philo_eat(p);
		philo_sleep_n_think(p);
	}
	return (NULL);
}

int	begin_routine(t_general_memory *g)
{
	int	i;

	i = -1;
	while (++i < g->nb_philo)
		if (pthread_create(&g->p[i].thread, NULL, (void *)routine, &g->p[i]) != 0)
			return (printf("Error: pthread_create failed\n"), 0);
	return (1);
}
