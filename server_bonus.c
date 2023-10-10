/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:06:57 by julberna          #+#    #+#             */
/*   Updated: 2023/10/09 21:37:07 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_bit = 0;

int	main(void)
{
	struct sigaction	print;

	print.sa_sigaction = print_char;
	sigemptyset(&print.sa_mask);
	print.sa_flags = SA_SIGINFO;
	ft_printf("Server PID: %i\n\n", getpid());
	sigaction(SIGUSR1, &print, NULL);
	sigaction(SIGUSR2, &print, NULL);
	while (42)
		pause();
}

void	print_char(int signo, siginfo_t *siginfo, void *context)
{
	static unsigned char	c = 0;

	(void)context;
	g_bit++;
	else if (signo == SIGUSR2)
		c |= 1;
	if (g_bit == 8)
	{
		write(1, &c, 1);
		g_bit = 0;
		c = 0;
	}
	c <<= 1;
	kill(siginfo->si_pid, SIGUSR1);
}
