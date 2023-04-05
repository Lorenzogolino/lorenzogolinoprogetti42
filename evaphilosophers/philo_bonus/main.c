/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:58 by dcarassi          #+#    #+#             */
/*   Updated: 2023/04/05 16:22:29 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	gap_time(struct timeval v)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (((t.tv_sec * 1000) + (t.tv_usec / 1000))
		- ((v.tv_sec * 1000) + (v.tv_usec / 1000)));
}

int	deadly_af(t_tab *t)
{
	if (gap_time(t->philo.start_sleep) >= t->time_to_die)
	{
		sem_wait(t->sem_p);
		printf("%lu\t%d\tDIED\n", gap_time(t->start), t->philo.id);
		exit(0);
	}
	return (0);
}

int	start_dad(t_tab *t)
{
	int	cnt_m;
	int	state;

	cnt_m = 0;
	while (waitpid(0, &state, 0))
	{
		if (((state >> 8) & 0x0000000ff) == 0)
		{
			kill(0, SIGKILL);
			break ;
		}
		if (((state >> 8) & 0x0000000ff) == 1)
		{
			cnt_m++;
			if (cnt_m == t->num_philo)
				break ;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_tab		*t;
	int			i;

	t = (t_tab *)malloc(sizeof(t_tab));
	check_params(t, ac, av);
	i = -1;
	while (++i < t->num_philo)
	{
		t->parent = fork();
		if (!t->parent)
		{
			t->philo.id = i + 1;
			break ;
		}
	}
	if (!t->parent)
		run_child(t);
	start_dad(t);
	free(t);
	return (0);
}
