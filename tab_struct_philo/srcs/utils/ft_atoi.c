/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelarbr <edelarbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:25:07 by edelarbr          #+#    #+#             */
/*   Updated: 2023/07/30 15:34:25 by edelarbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *str, int *atoi_error)
{
	int		i;
	long	nbr;

	nbr = 0;
	if (!str || !str[0] || (str[0] == '0' && str[1] != '\0')
		|| ft_strlen(str) > 10)
		return (*atoi_error = 1);
	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (*atoi_error = 1);
		nbr = nbr * 10 + str[i] - '0';
	}
	if (nbr < 0 || nbr > 2147483647)
		return (*atoi_error = 1);
	return (nbr);
}
