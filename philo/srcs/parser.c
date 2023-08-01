/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:23 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/01 19:44:13 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assignations(t_general_memory *g, int argc, char **argv)
{
	int	atoi_error;

	atoi_error = 0;
	g->nb_philo = ft_atoi(argv[1], &atoi_error);
	if (atoi_error == 1 || g->nb_philo < 1 || g->nb_philo > 100)
		return (printf("Error : Number_of_philosophers invalid argument\n"), 0);
	g->ttd = ft_atoi(argv[2], &atoi_error);
	if (atoi_error == 1)
		return (printf("Error : Time_to_die invalid argument\n"), 0);
	g->tte = ft_atoi(argv[3], &atoi_error);
	if (atoi_error == 1)
		return (printf("Error : Time_to_eat invalid argument\n"), 0);
	g->tts = ft_atoi(argv[4], &atoi_error);
	if (atoi_error == 1)
		return (printf("Error : Time_to_sleep invalid argument\n"), 0);
	if (argc == 6)
	{
		g->min_meal = ft_atoi(argv[5], &atoi_error);
		if (atoi_error == 1)
			return (printf("Error : Number_of_times_each_philosopher_must_eat invalid argument\n"), 0);
	}
	else
		g->min_meal = -1;
	return (1);
}

int	parser(t_general_memory *g, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Error : Wrong number of arguments\n"), 0);
	if (!assignations(g, argc, argv))
		return (0);
	if (g->nb_philo > 100)
		return (printf("Error : Number_of_philosophers too high\n"), 0);
	return (1);
}
