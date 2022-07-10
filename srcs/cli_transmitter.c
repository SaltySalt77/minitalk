/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_transmitter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:36:27 by hyna              #+#    #+#             */
/*   Updated: 2022/07/10 15:15:48 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static int	get_bit(char c)
{
	if (c & 128)
		return (1);
	return (0);
}

static void	transmitter(int pid, char	c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (get_bit(c))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
		c <<= 1;
	}
}

int	transmit_processor(int	pid, char	*message)
{
	int	i;

	i = 0;
	while (message[i])
		transmitter(pid, message[i++]);
	transmitter(pid, 127);
	exit(0);
}
