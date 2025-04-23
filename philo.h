/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:51:56 by maeskhai          #+#    #+#             */
/*   Updated: 2025/04/23 18:14:38 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_philo
{
	int				index;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}   t_philo;



typedef struct s_table
{
	int nb_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nb_of_meals;
	pthread_mutex_t *forks;
	pthread_t *philo;
	t_philo   *philos;

}   t_table;


//&forks[i]   i < number philos

void	ft_print_error(char *s);
int		ft_atoi(char *s);
int		ft_check_nbrs(int ac, char **av, t_table *lst);
void	ft_forks_to_philos(t_table *lst);
void	creat_philos(t_philo **philos, t_table *lst);

#endif