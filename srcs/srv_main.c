/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:47:56 by hyna              #+#    #+#             */
/*   Updated: 2022/07/10 14:10:49 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minitalk.h"
#include "server.h"
#include <stdio.h>

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = (int) getpid();
	ft_printf("pid = %d\n", pid);
	act.sa_sigaction = receive_processor;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		sleep(1);
	return (0);
}
