/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:26:28 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/02 01:06:30 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	general_memory_init(t_general_memory *g)
{
	int	i;

	g->forks = malloc(sizeof(int) * g->nb_philo);
	if (!g->forks)
		return (printf("Error : Malloc failed\n"), 0);
	i = -1;
	while (++i < g->nb_philo)
		g->forks[i] = 1;
	g->start_time = get_time();
	g->stop = 0;
	return (1);
}

int	personnal_memory_init(t_general_memory *g, t_personnal_memory *p, int i)
{
	p->id = i;
	p->g = g;
	p->dead = 0;
	p->meal = 0;
	if (p->id <= g->nb_philo)
	{
		p->left_fork = &g->forks[p->id];
		p->right_fork = &g->forks[p->id + 1];
	}
	else
	{
		p->left_fork = &g->forks[p->id];
		p->right_fork = &g->forks[0];
	}
	return (1);
}

int	structs_init(t_general_memory *g)
{
	int i;

	i = -1;
	if (!general_memory_init(g))
		return (0);
	g->p = malloc(sizeof(t_personnal_memory) * g->nb_philo);
	if (!g->p)
		return (printf("Error: malloc failed\n"), 0);
	while (++i < g->nb_philo)
	{
		if (!personnal_memory_init(g, &g->p[i], i))
			return (0);
	}
	return (1);
}