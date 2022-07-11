/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:47:56 by hyna              #+#    #+#             */
/*   Updated: 2022/07/11 11:19:25 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minitalk.h"
#include "server.h"

int	main(void)
{
	int					pid;
	int					err;
	struct sigaction	act;

	pid = (int) getpid();
	ft_printf("PID : %d\n", pid);
	act.sa_sigaction = receive_processor;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	err = sigaction(SIGUSR1, &act, NULL);
	if (err == -1)
		exit(1);
	err = sigaction(SIGUSR2, &act, NULL);
	if (err == -1)
		exit(1);
	while (1)
		sleep(1);
	return (0);
}
