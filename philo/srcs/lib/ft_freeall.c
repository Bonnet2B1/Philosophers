/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:50:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/04 17:37:38 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_freeall(t_general_memory *general)
{
	if (!general)
		return (NULL);
	if (general->forks)
		free(general->forks);
	general->forks = NULL;
	if (general->philo)
		free(general->philo);
	general->philo = NULL;
	return (NULL);
}
