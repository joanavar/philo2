/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:00:33 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/18 12:20:50 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	monitor(t_table *table)
{
	int i;

	i = 0;
	pthread_mutex_lock(table->m_done);
	if (table->done_eating == table->philo_nbr 
			&& table->meals_c != 0)
		return (full_meals(table));
	pthread_mutex_unlock(table->m_done);
	pthread_mutex_lock(table->m_time);
	if (table->philos[i].last_meal + table->time_to_die < get_timestamp)
	{
		pthread_mutex_lock(table->m_end);
		table->end = 1;
		pthread_mutex_unlock(table->m_end);
		print_status(table->philos[i].id, "Died", table);
		return (Funcion de finalizar(table));

	}

	
}

int full_meals(t_table *table)
{
	pthread_mutex_lock(table->m_end);
	table->end = 1;
	pthread_mutex_unlock(table->m_end);
	printf("------Everyone full meals------");
	return(funcion de finalizar(&table));

}
int	dinner_start(t_table *table)
{
	int i;

	i = -1;
	get_timestamp();
	while (++i <table->philo)
	{
		if (pthread_create(&(table->philos[i].t_id), NULL, 
			&routine, table->philos[i]) != 0)
			error_msg("Error creating threads");
	}
	return (0);
}



int main (int argv, char **argc)
{
	if (!parsing_check(argv, argc))
	{
		if (!data_init(argv, argc))
		{
			philo_init(&table);
			if (!dinner_start(&table))
				monitor(&table);
		}
	}
}
