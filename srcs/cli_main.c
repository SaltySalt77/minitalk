/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:47:31 by hyna              #+#    #+#             */
/*   Updated: 2022/07/10 20:31:39 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "minitalk.h"
#include "client.h"

int	main(int argc, char	**argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		return (0);
	ft_printf("%d\n", getpid());
	transmit_processor(pid, argv[2]);
	while (1)
		sleep(1);
	return (0);
}
