/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:47 by dcarassi          #+#    #+#             */
/*   Updated: 2023/04/05 16:20:44 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleep_well(t_tab *t)
{
	deadly_af(t);
	if (gap_time(t->philo.start_eat) >= t->time_to_eat)
	{
		t->philo.eat_times++;
		if (t->philo.eat_times == t->meal_cnt)
		{
			sem_post(t->sem_f);
			sem_post(t->sem_f);
			sem_unlink("/post");
			sem_unlink("/forks");
			sem_close(t->sem_f);
			sem_close(t->sem_p);
			exit(1);
		}
		sem_post(t->sem_f);
		sem_post(t->sem_f);
		sem_wait(t->sem_p);
		printf("%lu\t%d\tIS SLEEPING\n", gap_time(t->start), t->philo.id);
		sem_post(t->sem_p);
		gettimeofday(&t->philo.start_sleep, NULL);
		t->philo.state = SLEEPING;
		think(t);
	}
}

void	eat(t_tab *t)
{
	if (t->num_philo == 1)
	{
		sem_wait(t->sem_p);
		printf("%lu\t%d\tDIED\n", gap_time(t->start), t->philo.id);
		exit(0);
	}
	deadly_af(t);
	sem_wait(t->sem_f);
	sem_wait(t->sem_p);
	printf("%lu\t%d\tHAS TAKEN A FORK\n", gap_time(t->start), t->philo.id);
	printf("%lu\t%d\tIS EATING\n", gap_time(t->start), t->philo.id);
	sem_post(t->sem_p);
	deadly_af(t);
	gettimeofday(&t->philo.start_eat, NULL);
	t->philo.state = EATING;
	sleep_well(t);
}

void	first_fork(t_tab *t)
{
	sem_wait(t->sem_p);
	printf("%lu\t%d\tIS THINKING\n", gap_time(t->start), t->philo.id);
	sem_post(t->sem_p);
	deadly_af(t);
	sem_wait(t->sem_f);
	sem_wait(t->sem_p);
	printf("%lu\t%d\tHAS TAKEN A FORK\n", gap_time(t->start), t->philo.id);
	sem_post(t->sem_p);
	deadly_af(t);
	t->philo.state = TAKE_FORKS;
	eat(t);
}

void	think(t_tab *t)
{
	deadly_af(t);
	if (gap_time(t->philo.start_sleep) >= t->time_to_sleep)
	{
		t->philo.state = THINKING;
		first_fork(t);
	}
}

void	run_child(t_tab *t)
{
	t->philo.state = THINKING;
	gettimeofday(&t->philo.start_sleep, NULL);
	gettimeofday(&t->start, NULL);
	while (1)
	{
		if (t->philo.state == SLEEPING)
			think(t);
		if (t->philo.state == THINKING)
			first_fork(t);
		else if (t->philo.state == TAKE_FORKS)
			eat(t);
		else if (t->philo.state == EATING)
			sleep_well(t);
	}
}
