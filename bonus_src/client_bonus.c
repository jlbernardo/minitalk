/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:07:07 by julberna          #+#    #+#             */
/*   Updated: 2023/10/10 00:04:53 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_handshake = 0;

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*string;
	struct sigaction	signal;

	if (verification(argc, argv[1]))
		return (1);
	server_pid = ft_atoi(argv[1]);
	string = argv[2];
	signal.sa_handler = receive_signal;
	signal.sa_flags = 0;
	sigaction(SIGUSR1, &signal, NULL);
	while (*string != '\0')
		send_bit(server_pid, *(string)++);
}

void	receive_signal(int signo)
{
	if (signo == SIGUSR1)
		g_handshake = 1;
}

void	send_bit(int server_pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_handshake = 0;
		if (((c >> bit) & 1) == 0)
			kill(server_pid, SIGUSR1);
		else if (((c >> bit) & 1) == 1)
			kill(server_pid, SIGUSR2);
		bit--;
		while (!g_handshake)
			;
	}
}

int	verification(int argc, char *pid)
{
	int	i;

	i = 0;
	if (argc != 3)
		return (ft_printf("Wrong number of arguments.\n"));
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
			return (ft_printf("Wrong PID.\n"));
		i++;
	}
	return (0);
}
