/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:45:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/01 20:06:10 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(char *str, t_personnal_memory *p)
{
	if (!p->dead)
	{
		pthread_mutex_lock(&p->g->print_mutex);
		printf("%d %d %s\n", get_time() - p->g->start_time, p->id, str);
		pthread_mutex_unlock(&p->g->print_mutex);
	}
}