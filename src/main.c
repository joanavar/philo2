/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:00:33 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/21 18:43:18 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	finish(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_unlock(&table->m_done);
	pthread_mutex_unlock(&table->m_end);
	pthread_mutex_unlock(&table->m_time);
	pthread_mutex_unlock(&table->m_print);
	if (table->philo_nbr == 1)
		pthread_mutex_unlock(&table->forks[0]);
	while (++i < table->philo_nbr)
		pthread_join(table->philos[i].t_id, NULL);
	i = -1;
	while (++i < table->philo_nbr)
	{
		pthread_mutex_unlock(&table->forks[i]);
		pthread_mutex_destroy(&table->forks[i]);
	}
	pthread_mutex_destroy(&table->m_time);
	pthread_mutex_destroy(&table->m_end);
	pthread_mutex_destroy(&table->m_done);
	pthread_mutex_destroy(&table->m_print);
	return (1);

}

int	monitor(t_table *table)
{
	int i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&table->m_done);
		if (table->done_eating == table->philo_nbr 
				&& table->meals_c != 0)
			return (full_meals(table));
		pthread_mutex_unlock(&table->m_done);
		pthread_mutex_lock(&table->m_time);
		if (table->philos[i].last_meal + table->time_to_die < get_timestamp())
		{
			pthread_mutex_lock(&table->m_end);
			table->end = 1;
			//printf("%ld %d DIED\n", get_timestamp(), table->philos[i].id);
			pthread_mutex_unlock(&table->m_end);
			print_status(table->philos[i].id, "Died", table);
			return (finish(table));
		}
		pthread_mutex_unlock(&table->m_time);
		if (++i == table->philo_nbr)
			i = 0;
	}
	return (0);
}

int full_meals(t_table *table)
{
	pthread_mutex_lock(&table->m_end);
	table->end = 1;
	pthread_mutex_unlock(&table->m_end);
	printf("------Everyone full meals------");
	return(finish(table));

}
int	dinner_start(t_table *table)
{
	t_philo *philo;
	int i;
	
	philo = table->philos;
	i = -1;	
	while (++i <table->philo_nbr)
	{
		if (pthread_create(&(table->philos[i].t_id), NULL, 
			&routine, &(table->philos[i])) != 0)
			error_msg("Error creating threads");
	}
	return (0);
}



int main (int argv, char **argc)
{
	t_table table;

	if (!parsing_check(argv, argc))
	{
		if (!data_init(&table, argc))
		{
			philo_init(&table);
			if (!dinner_start(&table))
				monitor(&table);
		}
		free(table.philos);
		free(table.forks);
	}
}
