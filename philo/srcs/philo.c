/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/30 16:30:43 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*life(t_philo *p)
{
	sleep(1);
    printf("philo[%d] is alive\n", p->philo_id);
    return NULL;
}

int	main(int argc, char **argv)
{
	t_philo	*p;
	int		i;

	i = -1;
	p = parser(argc, argv);
	while (++i < p->nb_philo)
	{
		p->philo_id = i;
		if (pthread_create(&p->philo[i], NULL, (void *)life, p) != 0)
			ft_exit(p, "Error: pthread_create failed\n");
		printf("philo[%d] has been created\n", i);
	}

	i = -1;
	while (++i < p->nb_philo)
	{
		if (pthread_join(p->philo[i], NULL) != 0)
			ft_exit(p, "Error: pthread_join failed\n");
		printf("Thread %d has finished execution\n", i);
	}
	ft_exit(p, "Programm ended\n");
}
