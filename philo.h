/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:39:39 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/18 11:19:18 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mtx;
typedef struct s_philo	t_philo;

typedef struct s_table
{
	int			philo_nbr;
	time_t		time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals_c;
	int			end;
	int			done_eating;
	t_philo		*philos;
	t_mtx		*forks;

}t_table;


struct s_philo
{
	int			id;
	time_t		last_meal;
	int			num_meals;
	pthread_t	t_id;
	t_mtx		*left_fork;
	t_mtx		*right_fork;

};
