/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:43:35 by dcarassi          #+#    #+#             */
/*   Updated: 2023/03/31 15:03:14 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s)
{
	int	value;
	int	sign;

	sign = 1;
	value = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		value *= 10;
		value += *s - 48;
		s++;
	}
	return (value * sign);
}

int	check_input_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
	}
	return (1);
}

t_data	*allocate_data(char **argv, char argc)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_num = ft_atoi(argv[1]);
	data->death_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	data->finished = 0;
	if (argc == 6)
		data->meals_nb = ft_atoi(argv[5]);
	else
		data->meals_nb = 0;
	data->forks = malloc(data->philo_num * sizeof(pthread_mutex_t));
	gettimeofday(&data->start_time, NULL);
	return (data);
}

void	allocate_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		pthread_mutex_init(data->forks + i, NULL);
		philos[i].status = 5;
		philos[i].prev_status = 0;
		philos[i].eat_count = 0;
		gettimeofday(&philos[i].start_sleep, NULL);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		philos[i].l_fork = data->forks + i;
		if (i == data->philo_num - 1)
			philos[i].r_fork = data->forks;
		else
			philos[i].r_fork = (data->forks + i + 1);
	}
	i = -1;
	while (++i < data->philo_num)
		pthread_create(&philos[i].t1, NULL, &start_execute, philos + i);
}

t_data	*handle_input(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6 || !(ft_atoi(argv[1]) >= 1
			&& ft_atoi(argv[1]) <= 200) || !check_input_int(argc, argv))
	{
		input_error();
		return (NULL);
	}
	data = allocate_data(argv, argc);
	if (data->death_time < 60 || data->sleep_time < 60 || data->eat_time < 60)
	{
		input_error();
		return (NULL);
	}
	data->philos = malloc(data->philo_num * sizeof(t_philo));
	if (!data->philos)
		return (NULL);
	allocate_philos(data->philos, data);
	return (data);
}
