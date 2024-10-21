/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:39:39 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/21 18:16:35 by joanavar         ###   ########.fr       */
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

# define EAT 1
# define SLEEP 2
# define DIE 3

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
	t_mtx		m_done;
	t_mtx		m_time;
	t_mtx		m_print;
	t_mtx		m_end;
	t_philo		*philos;
	t_mtx		*forks;

}t_table;


struct s_philo
{
	int			id;
	time_t		last_meal;
	int			num_meals_c;
	t_table		*table;
	pthread_t	t_id;
	t_mtx		*left_fork;
	t_mtx		*right_fork;

};

//-----------FUNCTIONS----------

//init.c
int		data_init(t_table *table, char **argc);
void	philo_init(t_table *table);
//parsing.c
int		parsing_values(int argv, char **argc);
int		parsing_check(int argv, char **argc);
//utils.c
int 	error_msg(char *msg);
long	get_time(void);
void	ft_usleep(int ms);
int		ft_atoi(const char *s);
time_t	get_timestamp(void);
//routine.c
void	print_status(int philo, char *arg, t_table *table);
void	ft_sleep(t_philo *philo);
int		eat(t_philo *philo);
void	*routine(void *table);
//main.c
int		finish(t_table *table);
int		monitor(t_table *table);
int		full_meals(t_table *table);
int		dinner_start(t_table *table);



#endif


