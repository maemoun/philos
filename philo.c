/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:37 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/23 18:15:59 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_philos(t_philo **philos, t_table *lst)
{
	int i;

	i = 0;
	lst->philo = malloc(sizeof(pthread_t) * lst->nb_philos);
	while (i < lst->nb_philos)
	{
		lst->philos[i].index = i + 1;
		printf("%d\n", lst->philos[i].index);
		lst->philos[i].left_fork = &lst->forks[i];
		lst->philos[i].right_fork = &lst->forks[(i + 1) % lst->nb_philos];
		i++;
	}
}

int main(int ac, char **av)
{
	t_table lst;
	t_philo	*philos;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_nbrs(ac, av, &lst) == -1)
		{
			ft_print_error("Error\n");
			return (1);
		}
		ft_forks_to_philos(&lst);
		creat_philos(&philos, &lst);
	}
	else
	{
		ft_print_error("Error\n");
		return (1);
	}
}
