/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:46:02 by joanavar          #+#    #+#             */
/*   Updated: 2024/10/15 18:09:12 by joanavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parsing_values(int argv, char **argc)
{
	int i;

	i = 0;
	while (i++ < argv - 1)
		if (ft_atoi(argc[i]) == 0)
			return (error_msg("Arguments cant be 0"));
	return (0);
}

int parsing_check(int argv, char **argc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argv != 5 && argv != 6)
		return (error_msg("Number of arguments invalid"));
	while (argc[++j])
	{
		while (argc[j][i] >= '0' && argc[j][i] <= '9')
			i++;
		if (argc[j][i] == '\0')
		{
			if (i == 0)
				return (error_msg("Empty argument found"));
			else 
				i = 0;
		}
		else if (argc[j][i] == '-' && i == 0)
			return (error_msg("Negative Number"));
		else 
			return (error_msg("Non digit caracter found in arguments"));
	}
	return (parsing_values(argv, argc));


}
