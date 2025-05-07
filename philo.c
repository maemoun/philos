/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:37 by maeskhai          #+#    #+#             */
/*   Updated: 2025/05/05 15:44:49 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_creat_philos(t_table *lst)
{
	int i;

	i = 0;
	lst->philos = malloc(sizeof(t_philo) * lst->nb_philos);
	if (!lst->philos)
	{
		ft_print_error("Error\n");
		return ;
	}
	while (i < lst->nb_philos)
	{
		lst->philos[i].index = i + 1;
		lst->philos[i].meal_count = 0;
		lst->philos[i].left_fork = &lst->forks[i];
		lst->philos[i].right_fork = &lst->forks[(i + 1) % lst->nb_philos];
		lst->philos[i].table = lst;
		i++;
	}
}

int main(int ac, char **av)
{
	t_table lst;

	if (ac == 5 || ac == 6)
	{
		if (ft_check_nbrs(ac, av, &lst) == -1)
		{
			ft_print_error("Error\n");
			return (1);
		}
		ft_forks_to_philos(&lst);
		ft_creat_philos(&lst);
	}
	else
	{
		ft_print_error("Error\n");
		return (1);
	}
}
