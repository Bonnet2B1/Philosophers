/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:23 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/04 17:37:38 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assignations(t_general_memory *general, int argc, char **argv)
{
	int	atoi_error;

	atoi_error = 0;
	general->nb_philo = ft_atoi(argv[1], &atoi_error);
	if (atoi_error == 1 || general->nb_philo < 1 || general->nb_philo > 100)
		return (printf("Error : Number_of_philosophers invalid argument\n"), 0);
	general->ttd = ft_atoi(argv[2], &atoi_error);
	if (atoi_error == 1)
		return (printf("Error : Time_to_die invalid argument\n"), 0);
	general->tte = ft_atoi(argv[3], &atoi_error);
	if (atoi_error == 1)
		return (printf("Error : Time_to_eat invalid argument\n"), 0);
	general->tts = ft_atoi(argv[4], &atoi_error);
	if (atoi_error == 1)
		return (printf("Error : Time_to_sleep invalid argument\n"), 0);
	if (argc == 6)
	{
		general->min_meal = ft_atoi(argv[5], &atoi_error);
		if (atoi_error == 1)
			return (printf("Error : Number_of_times_each_philosopher_must_eat invalid argument\n"), 0);
	}
	else
		general->min_meal = -1;
	return (1);
}

int	parser(t_general_memory *general, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Error : Wrong number of arguments\n"), 0);
	if (!assignations(general, argc, argv))
		return (0);
	if (general->nb_philo > 100)
		return (printf("Error : Number_of_philosophers too high\n"), 0);
	return (1);
}
