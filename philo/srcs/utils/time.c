/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:07:33 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/13 21:39:28 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	philo_age(t_personnal *philo)
{
	if (philo->general->start_time == -1)
		return (0);
	return (get_time() - philo->general->start_time);
}

void	ft_usleep(int time_in_ms, t_general *general)
{
	long int	start_time;

	if (stop_checker(general) == 1)
		return ;
	start_time = get_time();
	while (get_time() < start_time + time_in_ms)
		usleep(50);
}
