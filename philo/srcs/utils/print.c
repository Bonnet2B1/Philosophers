/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:45:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/07 20:07:21 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(char *str, t_personnal *philo)
{
	pthread_mutex_lock(&philo->general->print_mutex);
	printf("%d %d %s\n", get_time() - philo->general->start_time, philo->id,
		str);
	pthread_mutex_unlock(&philo->general->print_mutex);
}
