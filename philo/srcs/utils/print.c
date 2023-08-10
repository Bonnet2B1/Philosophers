/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:45:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/10 17:44:23 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(char *str, t_personnal *philo)
{
	if (philo->general->a_philo_is_dead == 1)
		return ;
	pthread_mutex_lock(&philo->general->print_mutex);
	printf("%d %d %s\n", get_time() - philo->general->start_time, philo->id,
		str);
	pthread_mutex_unlock(&philo->general->print_mutex);
}
