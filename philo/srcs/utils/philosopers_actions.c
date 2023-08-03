/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:57:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/03 19:35:32 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_take_forks(t_personnal_memory *p)
{
	pthread_mutex_lock(&p->g->fork_mutex);
	*p->left_fork = 0;
	print_message("has taken a fork", p);
	*p->right_fork = 0;
	print_message("has taken a fork", p);
	pthread_mutex_unlock(&p->g->fork_mutex);
}

void	philo_put_down_forks(t_personnal_memory *p)
{
	pthread_mutex_lock(&p->g->fork_mutex);
	*p->left_fork = 1;
	*p->right_fork = 1;
	pthread_mutex_unlock(&p->g->fork_mutex);
}

void	philo_eat(t_personnal_memory *p)
{
	while (*p->left_fork == 0 || *p->right_fork == 0)
		;
	philo_take_forks(p);
	print_message("is eating", p);
	ft_usleep(p->g->tte);
	p->last_meal = get_time() - p->g->start_time;
	p->meal++;
	philo_put_down_forks(p);
}

void	philo_sleep_n_think(t_personnal_memory *p)
{
	print_message("is sleeping", p);
	ft_usleep(p->g->tts);
	print_message("is thinking", p);
}