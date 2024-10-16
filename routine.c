/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:07:50 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/16 19:17:31 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	print_status(int philo, char *arg, t_table *table)
{
	pthread_mutex_lock(&table->m_end);
	pthread_mutex_lock(&table->m_print);
	pthread_mutex_lock(&table->m_time);
	if (table->end == 0)
		printf("%ld %s %d\n", get_timestamp(), philo, arg);
	pthread_mutex_unlock(&table->m_end);
	pthread_mutex_unlock(&table->m_print);
	pthread_mutex_unlock(&table->m_time);

}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	print_status(philo->id, "He has taken first fork", philo->table);
	pthread_mutex_lock(&philo->right_fork);
	print_status(philo->id, "He has taken second fork", philo->table);
	print_status(philo->id, "He is eating", philo->table);
	pthread_mutex_lock(&philo->table->m_time);
	philo->last_meal = get_timestamp();
	pthread_mutex_unlock(&philo->table->m_time);
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(&philo->right_fork);
	philo->num_meals_c++;
	

}




void	*routine(void *table)
{
	t_philo	*philo;

	philo = (t_philo *)table;
	if (philo->id % 2 == 0)
		ft_usleep(table->time_to_eat * 0,5);
	while (1)
	{
		pthread_mutex_lock(&philo->table->m_end);
		if (&philo->table->end == 1)
		{
			pthread_mutex_unlock(&philo->table->m_end);
			break ;
		}
		pthread_mutex_unlock(&philo->table->m_end);
		if (eat(philo))

	}
}
