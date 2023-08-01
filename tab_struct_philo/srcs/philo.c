/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:59:12 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/31 15:31:23 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex_chopsticks;
pthread_mutex_t mutex_meal_counter;

static int *init_chopsticks(int nb_philo)
{
	int	*chopsticks;
	int	i;

	chopsticks = malloc(sizeof(int) * nb_philo);
	if (!chopsticks)
		return (NULL);
	i = -1;
	while (++i < nb_philo)
		chopsticks[i] = 1;
	return (chopsticks);
}

static t_philo **init_philo_tab(int argc, char **argv, int nb_philo)
{
	t_philo	**philo_tab;
	int		i;

	philo_tab = malloc(sizeof(t_philo *) * nb_philo + 1);
	if (!philo_tab)
		return (NULL);
	i = -1;
	while (++i < nb_philo)
	{
		philo_tab[i] = parser(argc, argv);
		philo_tab[i]->philo_id = i;
	}
	// mettre le dernier (nb_philo + 1) à NULL
	return (philo_tab);
}

void print_chopsitcks(t_philo *p)
{
	int i;

	i = -1;
	while (++i < p->nb_philo)
		printf("%d ", p->chopsticks[i]);
	printf("\n");
}

void take_chopsticks(t_philo *p)
{
	if (p->philo_id == p->nb_philo - 1)
	{
		while (!p->chopsticks[p->philo_id] || !p->chopsticks[0])
			usleep(1);
		pthread_mutex_lock(&mutex_chopsticks);
		p->chopsticks[p->philo_id] = 0;
		p->chopsticks[0] = 0;
		printf("%d has taken a fork\n", p->philo_id);
		print_chopsitcks(p);
		printf("%d is eating\n", p->philo_id);
		usleep(p->tte * 1000);
		p->chopsticks[p->philo_id] = 1;
		p->chopsticks[0] = 1;
		printf("%d has put down a fork\n", p->philo_id);
		print_chopsitcks(p);
		pthread_mutex_unlock(&mutex_chopsticks);
	}
	else
	{
		while (!p->chopsticks[p->philo_id] || !p->chopsticks[p->philo_id + 1])
			usleep(1);
		print_chopsitcks(p);
		pthread_mutex_lock(&mutex_chopsticks);
		p->chopsticks[p->philo_id] = 0;
		p->chopsticks[0] = 0;
		printf("%d has taken a fork\n", p->philo_id);
		printf("%d is eating\n", p->philo_id);
		usleep(p->tte * 1000);
		p->chopsticks[p->philo_id] = 1;
		p->chopsticks[0] = 1;
		printf("%d has put down a fork\n", p->philo_id);
		print_chopsitcks(p);
		pthread_mutex_unlock(&mutex_chopsticks);
	}
	p->meal--;
}

void is_eating(t_philo *p)
{
	// prendre les 2 chopsticks)
	take_chopsticks(p);
	// printf("%d is eating\n", p->philo_id);
}

void is_sleeping(t_philo *p)
{
	// printf("%d is sleeping\n", p->philo_id);
	usleep(p->tts * 1000);
}

static void	*life(t_philo *p)
{
	while (p->meal > 0)
	{
		is_eating(p);
		is_sleeping(p);
	}
	return NULL;
}

int	main(int argc, char **argv)
{
	t_philo	*temp;
	t_philo	**p;
	int		*chopsticks;
	int		i;

	temp = parser(argc, argv);
	p = init_philo_tab(argc, argv, temp->nb_philo);
	chopsticks = init_chopsticks(temp->nb_philo);
	if (!chopsticks || !p)
		ft_exit(temp, p, "Error: malloc failed\n");
	ft_freeall(temp);


	pthread_mutex_init(&mutex_chopsticks, NULL);
	pthread_mutex_init(&mutex_meal_counter, NULL);
	i = -1;
	while (++i < (*p)->nb_philo)
	{
		p[i]->chopsticks = chopsticks;
		if (pthread_create((p[i])->philo, NULL, (void *)life, p[i]) != 0)
			ft_exit(NULL, p, "Error: pthread_create failed\n");
		printf("philo[%d] has been created\n", i);
	}

	i = -1;
	while (++i < (*p)->nb_philo)
	{
		if (pthread_join(*(p[i]->philo), NULL) != 0)
    		ft_exit(NULL, p, "Error: pthread_join failed\n");
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex_chopsticks);
	pthread_mutex_destroy(&mutex_meal_counter);
	ft_exit(NULL, NULL, "Programm ended\n");
}
// int main() {
//     struct timeval start_time, end_time;
//     long elapsed_time;

//     // Get the current time (start time)
//     gettimeofday(&start_time, NULL);

//     // Simulate some work
//     for (int i = 0; i < 1000000; i++) {
//         // Do some computations
//     }

//     // Get the current time again (end time)
//     gettimeofday(&end_time, NULL);

//     // Calculate the elapsed time in microseconds
//     elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

//     printf("Elapsed time: %ld microseconds\n", elapsed_time);

//     return 0;
// }