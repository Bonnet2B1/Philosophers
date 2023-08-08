/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/08 18:09:49 by edelarbr         ###   ########.fr       */
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
	pthread_mutex_t				time_mutex;

	struct s_personnal_memory	*philo;
}								t_general;

typedef struct s_personnal_memory
{
	pthread_t					thread;

	int							id;

	int							meal_counter;

	int							last_meal;

	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;

	t_general					*general;
}								t_personnal;

int								parser(t_general *general, int argc,
									char **argv);

/* lib */
void							ft_putstr(char *str);
void							*ft_freeall(t_general *general);
int								ft_atoi(char *str, int *atoi_error);
int								ft_strlen(char *str);
int								ft_isdigit(int c);

/* utils*/
int								a_philosopher_is_dead(
									t_personnal *philo);
int								all_philosophers_ate_enough(
									t_general *general);
int								structs_init(t_general *general);
int								get_time(void);
void							print_message(char *str,
									t_personnal *philo);
void							philo_take_forks(t_personnal *philo);
void							philo_eat(t_personnal *philo);
void							philo_sleep_n_think(t_personnal *philo);
void							m_i_dead(t_personnal *philo);
int								begin_monitoring(t_general *general);
int								begin_routine(t_general *general);
int								terminate_simulation(t_general *general);
int								philo_age(t_personnal *philo);

#endif
