/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:02:38 by julberna          #+#    #+#             */
/*   Updated: 2023/10/09 21:20:42 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

void	receive_signal(int signo);
void	send_bit(int server_pid, char c);
void	print_char(int signo, siginfo_t *siginfo, void *context);

#endif