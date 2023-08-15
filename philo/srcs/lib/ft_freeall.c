/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:50:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/14 21:20:40 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_freeall(t_general *general)
{
	if (general)
	{
		if (general->forks)
			free(general->forks);
		general->forks = NULL;
		if (general->philo)
			free(general->philo);
		general->philo = NULL;
	}
	return (NULL);
}
