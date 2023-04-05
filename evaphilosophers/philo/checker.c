/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:58:45 by dcarassi          #+#    #+#             */
/*   Updated: 2023/03/30 17:43:52 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	checker_status_zero(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s\n", ft_gettimestamp(philo[i].data->start_time),
		philo[i].id, SLEEP);
	philo[i].prev_status = 0;
}

static	void	checker_status_five(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s\n", ft_gettimestamp(philo[i].data->start_time),
		philo[i].id, THINK);
	philo[i].prev_status = 5;
}

static	void	checker_status_one(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s\n", ft_gettimestamp(philo[i].data->start_time),
		philo[i].id, FORK);
	philo[i].prev_status = 1;
}

static	void	checker_status_two(t_philo *philo, int i)
{
	printf("%lu\t%d\t%s\n", ft_gettimestamp(philo[i].data->start_time),
		philo[i].id, FORK);
	printf("%lu\t%d\t%s\n", ft_gettimestamp(philo[i].data->start_time),
		philo[i].id, EAT);
	philo[i].prev_status = 2;
}

int	checker(t_philo *philo, int i)
{
	if (philo->data->meals_nb != 0
		&& philo->data->finished == philo->data->philo_num)
		return (0);
	if (ft_gettimestamp(philo[i].start_sleep) >= philo[i].data->death_time)
		philo[i].status = 4;
	if (philo[i].prev_status != philo[i].status)
	{
		if (philo[i].status == 0)
			checker_status_zero(philo, i);
		else if (philo[i].status == 5)
			checker_status_five(philo, i);
		else if (philo[i].status == 1)
			checker_status_one(philo, i);
		else if (philo[i].status == 2)
			checker_status_two(philo, i);
		else if (philo[i].status == 4)
		{
			printf("%lu\t%d\t%s\n", ft_gettimestamp(philo[i].data->start_time),
				philo[i].id, DEAD);
			return (0);
		}
	}
	return (1);
}
