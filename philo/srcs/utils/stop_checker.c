/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:25:52 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/13 16:32:05 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	stop_checker(t_general *general)
{
	pthread_mutex_lock(&general->stop_mutex);
	if (general->stop == 1)
		return (pthread_mutex_unlock(&general->stop_mutex), 1);
	else
		return (pthread_mutex_unlock(&general->stop_mutex), 0);
}
