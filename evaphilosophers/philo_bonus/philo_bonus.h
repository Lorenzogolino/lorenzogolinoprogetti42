/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:20:02 by dcarassi          #+#    #+#             */
/*   Updated: 2023/04/05 16:23:48 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <semaphore.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

enum e_fd
{
	in,
	out,
	err,
};

enum e_state
{
	SLEEPING,
	THINKING,
	TAKE_FORKS,
	EATING,
};

enum e_error
{
	WRG_INPUT,
	NB_INPUT,
};

typedef struct s_philos
{
	int				id;
	int				state;
	int				eat_times;
	struct timeval	start_eat;
	struct timeval	start_sleep;
}				t_philos;

typedef struct s_tab
{
	int				num_philo;
	int				meal_cnt;
	char			*forks;
	char			*post;
	pid_t			parent;
	sem_t			*sem_f;
	sem_t			*sem_p;
	t_philos		philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	struct timeval	start;
}				t_tab;

int				check_params(t_tab *t, int ac, char *av[]);
unsigned long	gap_time(struct timeval v);
int				deadly_af(t_tab *t);
void			run_child(t_tab *t);
void			eat(t_tab *t);
void			first_fork(t_tab *t);
void			think(t_tab *t);
#endif