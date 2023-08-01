/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopers_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:57:43 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/02 01:11:51 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_personnal_memory *p)
{
	while (!p->left_fork && !p->right_fork)
		;
	pthread_mutex_lock(&p->g->fork_mutex);
	*p->left_fork = 0;
	print_message("has taken a fork", p);
	*p->right_fork = 0;
	print_message("has taken a fork", p);
	pthread_mutex_unlock(&p->g->fork_mutex);
	print_message("is eating", p);
	ft_usleep(p->g->tte);
	p->last_meal = get_time();
	pthread_mutex_lock(&p->g->fork_mutex);
	*p->left_fork = 1;
	*p->right_fork = 1;
	pthread_mutex_unlock(&p->g->fork_mutex);
	p->meal++;
}

void	philo_sleep_n_think(t_personnal_memory *p)
{
	print_message("is sleeping", p);
	ft_usleep(p->g->tts);
	print_message("is thinking", p);
}