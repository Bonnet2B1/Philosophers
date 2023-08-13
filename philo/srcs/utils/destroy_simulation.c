/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:43:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/13 22:46:20 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// - destroy tout les mutex
//	- forks (voir init_struct)
//	- stop_mutex
//	- gonna_die_at_mutex

int	destroy_simulation(t_general *general)
{
	int	i;

	pthread_mutex_destroy(&general->print_mutex);
	i = -1;
	while (++i < general->nb_philo)
		pthread_mutex_destroy(&general->philo[i].gonna_die_at_mutex);
	general = ft_freeall(general);
	return (1);
}
