/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:45:58 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/13 23:12:58 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(char *str, t_personnal *philo)
{
	if (stop_checker(philo->general) == 1)
		return ;
	printf("%d %d %s\n", philo_age(philo), philo->id,
		str);
}
