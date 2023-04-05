/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarassi <dcarassi@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:28:10 by dcarassi          #+#    #+#             */
/*   Updated: 2023/03/31 15:03:13 by dcarassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SLEEP "is sleeping"
# define EAT "is eating"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DEAD "has died"

typedef struct s_philo {
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	int				eat_count;
	int				status;
	int				prev_status;
	struct timeval	start_sleep;
	struct timeval	start_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_philo;

typedef struct s_data {
	int					philo_num;
	int					meals_nb;
	int					finished;
	t_philo				*philos;
	unsigned long		death_time;
	unsigned long		eat_time;
	unsigned long		sleep_time;
	struct timeval		start_time;
	pthread_mutex_t		*forks;
}				t_data;

int				ft_atoi(char *s);
void			input_error(void);
void			routine(t_philo *philo);
int				checker(t_philo *philo, int i);
void			*start_execute(void *data);
t_data			*handle_input(int argc, char **argv);
unsigned long	ft_gettimestamp(struct timeval goddog);

#endif