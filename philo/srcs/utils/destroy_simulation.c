/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:43:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/10 17:50:44 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_simulation(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->nb_philo)
		if (pthread_join(general->philo[i].thread, NULL) != 0)
			return (printf("Error: pthread_join failed\n"), 0);
	pthread_mutex_destroy(&general->print_mutex);
	general = ft_freeall(general);
	return (1);
}
