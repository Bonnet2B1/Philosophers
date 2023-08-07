/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/07 19:26:44 by edelarbr         ###   ########.fr       */
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

	pthread_t					monitoring_thread;

	int							stop;

	pthread_mutex_t				*forks;
	int							*forks_int;

	int							start_time;

	pthread_mutex_t				print_mutex;
	pthread_mutex_t				operation_mutex;

	struct s_personnal_memory	*philo;
}								t_general_memory;

typedef struct s_personnal_memory
{
	pthread_t					thread;

	int							id;

	int							meal;

	int							last_meal;

	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;

	t_general_memory			*general;
}								t_personnal_memory;

int								parser(t_general_memory *general, int argc,
									char **argv);

/* lib */
void							ft_putstr(char *str);
void							*ft_freeall(t_general_memory *general);
int								ft_atoi(char *str, int *atoi_error);
int								ft_strlen(char *str);
int								ft_isdigit(int c);

/* utils*/
int								a_philosopher_is_dead(
									t_personnal_memory *philo);
int								all_philosophers_ate_enough(
									t_general_memory *general);
int								structs_init(t_general_memory *general);
int								get_time(void);
void							print_message(char *str,
									t_personnal_memory *philo);
int								ft_usleep(long int time_in_ms);
void							philo_take_forks(t_personnal_memory *philo);
void							philo_eat(t_personnal_memory *philo);
void							philo_sleep_n_think(t_personnal_memory *philo);
void							m_i_dead(t_personnal_memory *philo);
int								begin_monitoring(t_general_memory *general);
int								begin_routine(t_general_memory *general);
int								terminate_simulation(t_general_memory *general);
int								philo_age(t_personnal_memory *philo);

#endif
