/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:57:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/14 01:11:51 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_take_forks(t_personnal *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
}

void	philo_eat(t_personnal *philo)
{
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->gonna_die_at_mutex);
	philo->gonna_die_at = philo_age(philo) + philo->general->time_to_die;
	pthread_mutex_unlock(&philo->gonna_die_at_mutex);
	ft_usleep(philo->general->time_to_eat, philo->general);
	pthread_mutex_lock(&philo->gonna_die_at_mutex);
	philo->gonna_die_at = philo_age(philo) + philo->general->time_to_die
		- philo->general->time_to_eat;
	pthread_mutex_unlock(&philo->gonna_die_at_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->meal_counter++;
}

void	philo_sleep_n_think(t_personnal *philo)
{
	print_message("is sleeping", philo);
	ft_usleep(philo->general->time_to_sleep, philo->general);
	print_message("is thinking", philo);
}
