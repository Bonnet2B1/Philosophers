/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/30 19:01:39 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int			nb_philo;
	int			ttd;
	int			tte;
	int			tts;
	size_t		meal;
	pthread_t	*philo;
	int			philo_id;
	int			*chopsticks;
}				t_philo;

t_philo			*parser(int argc, char **argv);

/* utils */
void			ft_putstr(char *str);
void			ft_freeall(t_philo *p);
void			ft_exit(t_philo *philo, t_philo **philo_tab, char *str);
int				ft_atoi(char *str, int *atoi_error);
int				ft_strlen(char *str);
int				ft_isdigit(int c);

#endif