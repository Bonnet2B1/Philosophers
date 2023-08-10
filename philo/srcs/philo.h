/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/10 17:53:00 by edelarbr         ###   ########.fr       */
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

	int							a_philo_is_dead;

	pthread_mutex_t				*forks;

	int							start_time;

	pthread_mutex_t				print_mutex;

	struct s_personnal_memory	*philo;
	pthread_t					*personnal_monitoring;
}								t_general;

typedef struct s_personnal_memory
{
	pthread_t					thread;

	int							id;

	int							meal_counter;

	int							gonna_die_at;

	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;

	int							*left_fork_is_lock;
	int							*right_fork_is_lock;
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
void							ft_usleep(int time_in_ms);

#endif
