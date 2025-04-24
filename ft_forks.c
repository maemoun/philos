/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:14:44 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/24 12:05:21 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_forks_to_philos(t_table *lst)
{
	int i;

	i = 0;
	lst->forks = malloc(sizeof(pthread_mutex_t) * lst->nb_philos);
	if (!lst->forks)
	{
		ft_print_error("Error\n");
		free(lst->philos);
		return ;
	}
	while (i < lst->nb_philos)
	{
		if (pthread_mutex_init(&lst->forks[i], NULL) != 0)
		{
			ft_print_error("Error\n");
			return ;
		}
		i++;
	}
}
