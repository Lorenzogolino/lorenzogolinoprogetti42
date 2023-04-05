/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:02:51 by dcarassi          #+#    #+#             */
/*   Updated: 2023/03/31 15:45:33 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status_zero(t_philo *philo)
{
	if (ft_gettimestamp(philo->start_sleep) >= philo->data->sleep_time)
	{
		philo->prev_status = 0;
		philo->status = 5;
		return ;
	}
}

void	status_one(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork) == 0)
		philo->status = 1;
}

void	status_two(t_philo *philo)
{
	if (philo->data->philo_num == 1)
		philo->status = 4;
	else if (pthread_mutex_lock(philo->r_fork) == 0)
	{
		philo->status = 2;
		gettimeofday(&philo->start_eat, NULL);
		return ;
	}
}

void	status_three(t_philo *philo)
{
	if (ft_gettimestamp(philo->start_eat) >= philo->data->eat_time)
	{
		philo->status = 0;
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		if (philo->data->meals_nb > 0)
		{
			philo->eat_count++;
			if (philo->eat_count == philo->data->meals_nb)
			{
				philo->status = 10;
				philo->data->finished++;
				return ;
			}
		}
		gettimeofday(&philo->start_sleep, NULL);
		return ;
	}
}

void	routine(t_philo *philo)
{
	while (1)
	{
		usleep(100);
		if (philo->status == 0)
			status_zero(philo);
		else if (philo->status == 5)
			status_one(philo);
		else if (philo->status == 1)
			status_two(philo);
		else if (philo->status == 2)
			status_three(philo);
		else if (philo->status == 10)
			gettimeofday(&philo->start_sleep, NULL);
	}
}
