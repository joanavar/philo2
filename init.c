/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:31:55 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/18 12:05:08 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(int argv, char **argv)
{
	int i;

	table->philo_nbr = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->meals_c = ft_atoi(argv[5]);
	else 
		table->meals_c = 0;
	table->done_eating = 0;
	table->end = 0;
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = malloc(sizeof(t_mtx) * table->philo_nbr);
	if (!data->philos || !data->forks)
		return (error_msg("Memory problem"));
	i = 0;
	while (i < table->philo_nbr)
		pthread_mutex_init(&(table->forks[i++]), NULL);
	pthread_mutex_init(&(table->m_done), NULL);
	pthread_mutex_init(&(table->m_time), NULL);
	pthread_mutex_init(&(table->m_print), NULL);
	pthread_mutex_init(&(table->m_end), NULL);
	return (0);
}

void	philo_init(t_table *table)
{
	int i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].num_meals_c = 0;
		table->philos[i].table = table;
		table->philos[i].last_meal = 0;
		table->philos[i].left_fork = &(table->forks[i]);
		if (table->philo_nbr == 1)
			table->philos[i].right_fork = table->philos[i].left_fork;
		else
		{
			if (i + i == table->philo_nbr)
				table->philos[i].right_fork = table->forks;
			else
				table->philos[i].right_fork = &(table->forks[i + 1]);
		}
		i++;
	}
}
