/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:31:55 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/15 18:59:20 by joanavar         ###   ########.fr       */
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
		table->meals_c = -1;
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
