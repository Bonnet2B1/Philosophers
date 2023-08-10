/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:23 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/09 21:42:30 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	assignations(t_general *general, int argc, char **argv)
{
	int	atoi_error;

	atoi_error = 0;
	general->nb_philo = ft_atoi(argv[1], &atoi_error);
	if (atoi_error == 1 || general->nb_philo < 1)
		return (printf("Error : Number_of_philosophers invalid argument\n"), 0);
	general->time_to_die = ft_atoi(argv[2], &atoi_error);
	if (atoi_error == 1 || general->time_to_die < 1)
		return (printf("Error : Time_to_die invalid argument\n"), 0);
	general->time_to_eat = ft_atoi(argv[3], &atoi_error);
	if (atoi_error == 1 || general->time_to_eat < 1)
		return (printf("Error : Time_to_eat invalid argument\n"), 0);
	general->time_to_sleep = ft_atoi(argv[4], &atoi_error);
	if (atoi_error == 1 || general->time_to_sleep < 1)
		return (printf("Error : Time_to_sleep invalid argument\n"), 0);
	if (argc == 6)
	{
		general->min_meal = ft_atoi(argv[5], &atoi_error);
		if (atoi_error == 1 || general->min_meal < 1)
			return (printf("Error : Last argument is invalid\n"), 0);
	}
	else
		general->min_meal = -1;
	return (1);
}

int	parser(t_general *general, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Error : Wrong number of arguments\n"), 0);
	if (!assignations(general, argc, argv))
		return (0);
	return (1);
}
