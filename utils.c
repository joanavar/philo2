/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:51:35 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/16 18:05:06 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error_msg(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

long	get_time(void)
{
	struct timeval	tv;
	long			end;

	gettimeofday(&tv, NULL);
	end = ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
	return (end);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = get_time();
	while (get_time() - time < ms)
		usleep(100);
}

int ft_atoi(const char *s)
{
	unsigned int	num;
	int				i;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num));
}

time_t get_timestamp(void)
{
	static time_t start_time;
	struct timeval t;

	start_time = 0;
	if (start_time == 0)
	{
		gettimeofday(&t, NULL);
		start_time = ((t.tv_sec * 1000) + (t.tv_usec / 1000));
	}
	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000) - start_time);


}
