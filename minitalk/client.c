/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgolino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:03:33 by lgolino           #+#    #+#             */
/*   Updated: 2023/04/04 12:03:41 by lgolino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_message(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

void	ft_client_handler(int signum)
{
	(void)signum;
	ft_printf("Message correctly sent and received by the server.\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;
	pid_t				pid;
	int					c;

	c = -1;
	if (argc != 3)
	{
		ft_printf("ERROR\n./client <server_pid> <text>\n");
		exit (0);
	}
	pid = ft_atoi(argv[1]);
	signal.sa_handler = ft_client_handler;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	while (argv[2][++c])
		ft_send_message(pid, argv[2][c]);
	ft_send_message(pid, 0);
}
