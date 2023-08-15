/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:36:47 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/14 22:14:31 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	m_i_dead(t_personnal *philo)
{
	pthread_mutex_lock(&philo->gonna_die_at_mutex);
	if (philo_age(philo) >= philo->gonna_die_at)
	{
		pthread_mutex_unlock(&philo->gonna_die_at_mutex);
		pthread_mutex_lock(&philo->general->stop_mutex);
		philo->general->stop = 1;
		pthread_mutex_unlock(&philo->general->stop_mutex);
		pthread_mutex_lock(&philo->general->print_mutex);
		printf("%d %d died\n", get_time() - philo->general->start_time,
			philo->id);
		return (1);
	}
	pthread_mutex_unlock(&philo->gonna_die_at_mutex);
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
	{
		pthread_mutex_lock(&general->philo[i].meal_counter_mutex);
		if (general->philo[i].meal_counter < general->min_meal)
		{
			pthread_mutex_unlock(&general->philo[i].meal_counter_mutex);
			return (0);
		}
		pthread_mutex_unlock(&general->philo[i].meal_counter_mutex);
	}
	pthread_mutex_lock(&general->stop_mutex);
	general->stop = 1;
	pthread_mutex_unlock(&general->stop_mutex);
	return (1);
}

int	monitoring(t_general *general)
{
	int	i;

	pthread_mutex_lock(&general->time_mutex);
	general->start_time = get_time();
	pthread_mutex_unlock(&general->time_mutex);
	while (1)
		if (a_philosopher_is_dead(general)
			|| all_philosophers_ate_enough(general))
			break ;
	while (1)
	{
		pthread_mutex_lock(&general->nb_philo_who_has_finished_mutex);
		if (general->nb_philo_who_has_finished == general->nb_philo)
		{
			pthread_mutex_unlock(&general->nb_philo_who_has_finished_mutex);
			break ;
		}
		pthread_mutex_unlock(&general->nb_philo_who_has_finished_mutex);
	}
	i = -1;
	while (++i < general->nb_philo)
		if (pthread_join(general->philo[i].thread, NULL) != 0)
			return (printf("Error: pthread_join failed\n"), 0);
	return (0);
}
