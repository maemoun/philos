/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:52:37 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/24 13:21:41 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_creat_philos(t_table *lst)
// {
// 	int i;

// 	i = 0;
// 	lst->philos = malloc(sizeof(t_philo) * lst->nb_philos);
// 	if (!lst->philos)
// 	{
// 		ft_print_error("Error\n");
// 		return ;
// 	}
// 	lst->philo = malloc(sizeof(pthread_t) * lst->nb_philos);
// 	if (!lst->philo)
// 	{
// 		ft_print_error("Error\n");
// 		return ;
// 	}
// 	while (i < lst->nb_philos)
// 	{
// 		lst->philos[i].index = i + 1;
// 		lst->philos[i].meal_count = 0;
// 		lst->philos[i].last_meal = 0;
// 		lst->philos[i].left_fork = &lst->forks[i];
// 		lst->philos[i].right_fork = &lst->forks[(i + 1) % lst->nb_philos];
// 		lst->philos[i].table = lst;
// 		i++;
// 	}
// }

void	ft_creat_philos(t_table *lst)
{
	int	i;

	i = 0;
	lst->philos = malloc(sizeof(t_philo) * lst->nb_philos);
	if (!lst->philos)
	{
		ft_print_error("Error\n");
		return ;
	}
	lst->forks = malloc(sizeof(pthread_mutex_t) * lst->nb_philos);
	if (!lst->forks)
	{
		ft_print_error("Error\n");
		free(lst->philos);
		return ;
	}
	// Initialize forks (mutexes)
	while (i < lst->nb_philos)
	{
		if (pthread_mutex_init(&lst->forks[i], NULL) != 0)
		{
			ft_print_error("Error: Fork mutex init failed\n");
			return ;
		}
		i++;
	}
	// Set philosopher data
	i = 0;
	while (i < lst->nb_philos)
	{
		lst->philos[i].index = i + 1;
		lst->philos[i].meal_count = 0;
		lst->philos[i].last_meal = 0;
		lst->philos[i].left_fork = &lst->forks[i];
		lst->philos[i].right_fork = &lst->forks[(i + 1) % lst->nb_philos];
		// lst->philos[i].table = lst;
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
		// ft_forks_to_philos(&lst);
		ft_creat_philos(&lst);
	}
	else
	{
		ft_print_error("Error\n");
		return (1);
	}
}
