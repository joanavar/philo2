/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:51:35 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/15 18:11:35 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int error_msg(char *msg)
{
	printf("%s\n", msg);
	return (1);
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

