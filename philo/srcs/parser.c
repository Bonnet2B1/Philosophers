/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:27:23 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/29 16:43:27 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_philo parser(int argc, char **argv)
{
	p->philo = ft_atoi_mod(argc[1])
	p->ttd = ft_atoi_mod(argv[2]) 
	p->tte = ft_atoi_mod(argv[3]) 
	p->tts = ft_atoi_mod(argv[4]) 
	if (argc == 6)
		p->meal = ft_atoi_mod(argv[5])
	else
		p->meal = 0;
	return (p);
}
