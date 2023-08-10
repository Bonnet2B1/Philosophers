/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/10 17:46:35 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_general	general;

	if (!parser(&general, argc, argv)
		|| !structs_init(&general)
		|| !begin_routine(&general)
		|| !monitoring(&general)
		|| !destroy_simulation(&general))
		return (ft_freeall(&general), 0);
	return (ft_freeall(&general), 1);
}
