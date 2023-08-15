/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/14 23:17:28 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_general_memory
{
	int							nb_philo;
	int							time_to_die;
	int							time_to_eat;
	int							time_to_sleep;
	int							min_meal;

	int							stop;

	pthread_mutex_t				*forks;

	int							start_time;
	int							nb_philo_who_has_finished;

	pthread_mutex_t				print_mutex;
	pthread_mutex_t				stop_mutex;
	pthread_mutex_t				time_mutex;
	pthread_mutex_t				nb_philo_who_has_finished_mutex;

	struct s_personnal_memory	*philo;
	pthread_t					*personnal_monitoring;
}								t_general;

typedef struct s_personnal_memory
{
	pthread_t					thread;
	pthread_t					death_monitoring;

	int							id;

	int							meal_counter;

	int							gonna_die_at;

	pthread_mutex_t				gonna_die_at_mutex;
	pthread_mutex_t				meal_counter_mutex;

	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;

	t_general					*general;
}								t_personnal;

/* lib */
void							ft_putstr(char *str);
void							*ft_freeall(t_general *general);
int								ft_atoi(char *str, int *atoi_error);
int								ft_strlen(char *str);
int								ft_isdigit(int c);

/* utils */
int								parser(t_general *general, int argc,
									char **argv);

int								structs_init(t_general *general);
int								get_time(void);
void							print_message(char *str,
									t_personnal *philo);
/* philosophers_actions */
void							philo_take_forks(t_personnal *philo);
void							philo_eat(t_personnal *philo);
void							philo_sleep_n_think(t_personnal *philo);

int								m_i_dead(t_personnal *philo);
int								a_philosopher_is_dead(t_general *general);
int								monitoring(t_general *general);
int								begin_routine(t_general *general);
int								destroy_simulation(t_general *general);
int								philo_age(t_personnal *philo);
void							ft_usleep(int time_in_ms, t_general *general);
int								stop_checker(t_general *general);

#endif
