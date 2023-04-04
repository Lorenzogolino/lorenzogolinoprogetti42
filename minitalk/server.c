/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:13:29 by lgolino           #+#    #+#             */
/*   Updated: 2023/04/04 12:13:36 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server_handler(int signum, siginfo_t *pid, void *giratina)
{
	static char	value;
	static int	bit;

	(void)giratina;
	if (bit == 0)
		value = 0;
	if (signum == SIGUSR1)
		value += (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", value);
		if (value == 0)
		{
			ft_printf("\n");
			kill(pid->si_pid, SIGUSR1);
		}
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	signal;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal.sa_sigaction = &ft_server_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
		pause();
}
