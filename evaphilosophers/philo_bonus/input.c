/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:53 by dcarassi          #+#    #+#             */
/*   Updated: 2023/04/05 16:21:07 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	print_error(int str)
{
	if (str == NB_INPUT)
	{
		write(err, "\e[0;31mUSAGE: ./philo number_of_philosophers ", 46);
		write(err, "time_to_die time_to_eat time_to_sleep ", 38);
		write(err, "[number_of_times_each_philosopher_must_eat]\n\e[0m", 49);
	}
	if (str == WRG_INPUT)
	{
		write(err, "\e[0;31mWRONG INPUT: Philos must make an action ", 48);
		write(err, "at least for 1ms and eat at least 1 time.\n\e[0m", 47);
	}
	exit(1);
}

int	ft_atoi(char *str)
{
	long int	r;
	int			i;

	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		print_error(WRG_INPUT);
	if (str[i] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
			print_error(WRG_INPUT);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_error(WRG_INPUT);
		r = r * 10 + (str[i++]) - 48;
	}
	if (r > 2147483647)
		print_error(WRG_INPUT);
	return (r);
}

int	check_params(t_tab *t, int ac, char *av[])
{
	if (ac < 5 || ac > 6)
		print_error(NB_INPUT);
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200 || ft_atoi(av[2]) < 60
		|| ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		print_error(WRG_INPUT);
	t->num_philo = ft_atoi(av[1]);
	t->time_to_die = ft_atoi(av[2]);
	t->time_to_eat = ft_atoi(av[3]);
	t->time_to_sleep = ft_atoi(av[4]);
	t->philo.eat_times = 0;
	t->meal_cnt = -1;
	if (ac == 6)
		t->meal_cnt = ft_atoi(av[5]);
	write(out, "TIME\tPHILO\tACTION\n\n", 19);
	t->forks = "/forks";
	t->post = "/post";
	sem_unlink(t->forks);
	sem_unlink(t->post);
	t->sem_f = sem_open(t->forks, O_CREAT, 0666, t->num_philo);
	t->sem_p = sem_open(t->post, O_CREAT, 0666, 1);
	return (0);
}
