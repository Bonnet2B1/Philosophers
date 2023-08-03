/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/03 18:55:32 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void m_i_dead(t_personnal_memory *p)
{
	pthread_mutex_lock(&p->g->print_mutex);
	if (!(p->last_meal- p->g->start_time >= p->g->ttd))
		pthread_mutex_unlock(&p->g->print_mutex);
}
