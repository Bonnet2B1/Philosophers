/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/02 00:58:00 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void m_i_dead(t_personnal_memory *p)
{
	if (p->last_meal >= p->g->ttd)
	{
		p->dead = 1;
		print_message("died", p);
	}
}

int	a_philosopher_is_dead(t_general_memory *g)
{
	int	i;

	i = -1;
	while (++i < g->nb_philo)
		if (g->p[i].dead == 1)
			return (1);
	return (0);
}
