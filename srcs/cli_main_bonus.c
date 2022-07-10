/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:47:31 by hyna              #+#    #+#             */
/*   Updated: 2022/07/10 21:13:37 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "minitalk.h"
#include "client.h"

char	*message;

void	put_success_msg(int	signo,siginfo_t	*info, void	*context)
{
	(void)	signo;
	(void)	context;
	ft_printf(" * Handshake_Succeded *\n");
	transmit_processor(info->si_pid, message);
}

int	main(int argc, char	**argv)
{
	struct sigaction	act;
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		return (0);
	message = argv[2];
	kill(pid, SIGUSR1);
	act.sa_sigaction = put_success_msg;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	while (1)
		sleep(1);
	return (0);
}
