/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:50:22 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/03 18:28:35 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*ft_freeall(t_general_memory *g)
{
	int i;
	if (g)
	{
		i = -1;
		if (g->forks)
			free(g->forks);
		while (++i < g->nb_philo)
		{
			free(&g->p[i]);
			g->p = NULL;
		}
	}
	return (NULL);
}
