/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:35:06 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/01 19:43:42 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int all_philosophers_ate_enough(t_general_memory *g)
{
	int i;

	i = -1;
	if (g->min_meal == -1)
		return (0);
	while (++i < g->nb_philo)
		if (g->p[i].meal < g->min_meal)
			return (0);
	return (1);
}