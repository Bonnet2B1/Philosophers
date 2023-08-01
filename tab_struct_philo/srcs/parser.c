/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:23 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/30 19:12:04 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	assignations(t_philo *p, int argc, char **argv)
// {
// 	int	atoi_error;

// 	atoi_error = 0;
// 	p->nb_philo = ft_atoi(argv[1], &atoi_error);
// 	if (atoi_error == 1)
// 		ft_exit(p, NULL, "Error : Number_of_philosophers invalid argument\n");
// 	p->ttd = ft_atoi(argv[2], &atoi_error);
// 	if (atoi_error == 1)
// 		ft_exit(p, NULL, "Error : Time_to_die invalid argument\n");
// 	p->tte = ft_atoi(argv[3], &atoi_error);
// 	if (atoi_error == 1)
// 		ft_exit(p, NULL, "Error : Time_to_eat invalid argument\n");
// 	p->tts = ft_atoi(argv[4], &atoi_error);
// 	if (atoi_error == 1)
// 		ft_exit(p, NULL, "Error : Time_to_sleep invalid argument\n");
// 	if (argc == 6)
// 		p->meal = ft_atoi(argv[5], &atoi_error);
// 	else
// 		p->meal = -1;
// }

// t_philo	*parser(int argc, char **argv)
// {
// 	t_philo	*p;
// 	int		i;

// 	if (argc < 5 || argc > 6)
// 		ft_exit(NULL, NULL, "Error : Wrong number of arguments\n");
// 	p = malloc(sizeof(t_philo));
// 	if (!p)
// 		ft_exit(p, NULL, "Error : Malloc failed\n");
// 	assignations(p, argc, argv);
// 	if (p->nb_philo > 100)
// 		ft_exit(p, NULL, "Error : Number_of_philosophers too high\n");
// 	p->philo = malloc(sizeof(pthread_t) * p->nb_philo);
// 	p->chopsticks = malloc(sizeof(int) * p->nb_philo);
// 	if (!p->philo || !p->chopsticks)
// 		ft_exit(p, NULL, "Error : Malloc failed\n");
// 	i = -1;
// 	while (++i < p->nb_philo)
// 		p->chopsticks[i] = 1;
// 	return (p);
// }

static void	assignations(t_philo *p, int argc, char **argv)
{
	int	atoi_error;

	atoi_error = 0;
	p->nb_philo = ft_atoi(argv[1], &atoi_error);
	if (atoi_error == 1)
		ft_exit(p, NULL, "Error : Number_of_philosophers invalid argument\n");
	p->ttd = ft_atoi(argv[2], &atoi_error);
	if (atoi_error == 1)
		ft_exit(p, NULL, "Error : Time_to_die invalid argument\n");
	p->tte = ft_atoi(argv[3], &atoi_error);
	if (atoi_error == 1)
		ft_exit(p, NULL, "Error : Time_to_eat invalid argument\n");
	p->tts = ft_atoi(argv[4], &atoi_error);
	if (atoi_error == 1)
		ft_exit(p, NULL, "Error : Time_to_sleep invalid argument\n");
	if (argc == 6)
		p->meal = ft_atoi(argv[5], &atoi_error);
	else
		p->meal = -1;
}

t_philo	*parser(int argc, char **argv)
{
	t_philo	*p;

	if (argc < 5 || argc > 6)
		ft_exit(NULL, NULL, "Error : Wrong number of arguments\n");
	p = malloc(sizeof(t_philo));
	if (!p)
		ft_exit(p, NULL, "Error : Malloc failed\n");
	assignations(p, argc, argv);
	if (p->nb_philo > 100)
		ft_exit(p, NULL, "Error : Number_of_philosophers too high\n");
	p->philo = malloc(sizeof(pthread_t));
	if (!p->philo)
		ft_exit(p, NULL, "Error : Malloc failed\n");
	return (p);
}
