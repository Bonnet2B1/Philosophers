/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/08/02 01:10:49 by edelarbr         ###   ########.fr       */
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
	// arguments
	int							nb_philo;
	int							ttd;
	int							tte;
	int							tts;
	int							min_meal;
	// monitoring thread
	pthread_t					monitoring_thread;
	// signal for stopping threads
	int							stop;
	// forks on the table
	int							*forks;
	// reference time
	int							start_time;
	// mutexs
	pthread_mutex_t				print_mutex;
	pthread_mutex_t				right_fork_mutex;
	pthread_mutex_t				left_fork_mutex;
	pthread_mutex_t				mutex;
	// link to all philosopher personnal memory
	struct s_personnal_memory	*p;
}								t_general_memory;

typedef struct s_personnal_memory
{
	// philosopher thread
	pthread_t					thread;
	// philosopher id
	int							id;
	// philosopher dead flag
	int							dead;
	// philosopher meal counter
	int							meal;
	// philosopher last meal time
	int							last_meal;
	// forks
	int							*left_fork;
	int							*right_fork;
	// link to general memory
	t_general_memory			*g;
}								t_personnal_memory;

int								parser(t_general_memory *g, int argc,
									char **argv);

/* lib */
void							ft_putstr(char *str);
void							ft_freeall(t_general_memory *g);
int								ft_atoi(char *str, int *atoi_error);
int								ft_strlen(char *str);
int								ft_isdigit(int c);

/* utils*/
int								a_philosopher_is_dead(t_general_memory *g);
int								all_philosophers_ate_enough(t_general_memory *g);
int								structs_init(t_general_memory *g);
int								get_time(void);
void							print_message(char *str, t_personnal_memory *p);
int								ft_usleep(long int time_in_ms);
void							philo_eat(t_personnal_memory *p);
void							philo_sleep_n_think(t_personnal_memory *p);
void							m_i_dead(t_personnal_memory *p);

#endif