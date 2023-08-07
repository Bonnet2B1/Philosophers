/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/07 18:28:19 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_general_memory general;

	if (!parser(&general, argc, argv) ||
		!structs_init(&general) ||
		!begin_monitoring(&general) ||
		!begin_routine(&general) ||
		!terminate_simulation(&general))
		return (ft_freeall(&general), 0);
	return (0);
}