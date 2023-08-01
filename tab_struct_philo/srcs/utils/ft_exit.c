/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:47:33 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/30 17:24:00 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_exit(t_philo *philo, t_philo **philo_tab, char *str)
{
	int i;
	
	ft_putstr(str);
	if (philo)
		ft_freeall(philo);
	if (philo_tab)
	{
		i = -1;
		while (philo_tab[++i])
			ft_freeall(philo_tab[i]);
	}
	exit(0);
}
