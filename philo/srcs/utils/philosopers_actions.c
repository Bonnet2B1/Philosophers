/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:57:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/06 19:21:12 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_take_forks(t_personnal_memory *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
}

void	philo_eat(t_personnal_memory *philo)
{
	print_message("is eating", philo);
	ft_usleep(philo->general->tte);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->general->operation_mutex);
	philo->last_meal = get_time() - philo->general->start_time;
	philo->meal++;
	pthread_mutex_unlock(&philo->general->operation_mutex);
}

void	philo_sleep_n_think(t_personnal_memory *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->general->tts);
	print_message("is thinking", philo);
}