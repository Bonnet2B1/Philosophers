/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:36:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/10 17:49:55 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	m_i_dead(t_personnal *philo)
{
	if (philo_age(philo) >= philo->gonna_die_at)
	{
		pthread_mutex_lock(&philo->general->print_mutex);
		philo->general->a_philo_is_dead = 1;
		printf("%d %d died\n", get_time() - philo->general->start_time,
			philo->id);
		return (1);
	}
	return (0);
}

int	a_philosopher_is_dead(t_general *general)
{
	int	i;

	i = -1;
	while (++i < general->nb_philo)
	{
		if (m_i_dead(&general->philo[i]))
			return (1);
	}
	return (0);
}

int	all_philosophers_ate_enough(t_general *general)
{
	int	i;

	i = -1;
	if (general->min_meal == -1)
		return (0);
	while (++i < general->nb_philo)
		if (general->philo[i].meal_counter < general->min_meal)
			return (0);
	return (1);
}

int	monitoring(t_general *general)
{
	general->start_time = get_time();
	while (1)
		if (a_philosopher_is_dead(general)
			|| all_philosophers_ate_enough(general))
			return (1);
	return (0);
}
