/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:19:17 by dcarassi          #+#    #+#             */
/*   Updated: 2023/03/31 15:40:53 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_gettimestamp(struct timeval goddog)
{
	struct timeval	now;
	unsigned long	res;

	gettimeofday(&now, NULL);
	res = (((now.tv_sec * 1000) + (now.tv_usec / 1000))
			- ((goddog.tv_sec * 1000) + (goddog.tv_usec / 1000)));
	return (res);
}

void	input_error(void)
{
	printf("Wrong input\n");
	printf("Correct input: number_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]");
	printf("\nAll of the arguments must be integers. The 2nd, 3rd and");
	printf("4th have to be written as millisecoonds");
}

void	ft_close(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(data->philos[i].l_fork);
		pthread_mutex_destroy(data->philos[i].r_fork);
	}
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	free (data);
}

void	*start_execute(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 != 0)
		usleep(1000);
	routine(philo);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	data = handle_input(argc, argv);
	if (!data)
		return (0);
	while (1)
	{
		i = -1;
		while (++i < data->philo_num)
		{
			if (!checker(data->philos, i))
				return (0);
		}
	}
	ft_close(data);
	return (0);
}
