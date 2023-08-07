/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:20:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/07 19:27:23 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	m_i_dead(t_personnal_memory *philo)
{
	pthread_mutex_lock(&philo->general->print_mutex);
	if (!(philo->last_meal
			- philo->general->start_time >= philo->general->time_to_die))
		pthread_mutex_unlock(&philo->general->print_mutex);
}
