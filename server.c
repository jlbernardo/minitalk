/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:50:19 by julberna          #+#    #+#             */
/*   Updated: 2023/10/09 18:17:52 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit = 0;

void	print_char(int signo, siginfo_t *siginfo, void *context);

int	main(void)
{
	struct sigaction	print;

	print.sa_sigaction = print_char;
	sigemptyset(&print.sa_mask);
	print.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %i\n", getpid());
	sigaction(SIGUSR1, &print, NULL);
	sigaction(SIGUSR2, &print, NULL);
	while (1)
		pause();
}

void	print_char(int signo, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;

	(void)context;
	if (signo == SIGUSR1)
		g_bit++;
	else if (signo == SIGUSR2)
	{
		c |= 1;
		g_bit++;
	}
	if (g_bit == 8)
	{
		write(1, &c, 1);
		g_bit = 0;
		c = 0;
	}
	c <<= 1;
	kill(siginfo->si_pid, SIGUSR1);
}
