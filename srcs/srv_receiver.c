/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_receiver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:22:36 by hyna              #+#    #+#             */
/*   Updated: 2022/07/10 15:01:39 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"
#include "libft.h"

static void	refresh(char	*message, int	*count, char	*letter)
{
	if (message)
		ft_bzero(message, 100);
	*count = 0;
	*letter = 0;
}

void	receive_processor(int signo, siginfo_t	*info, void	*context)
{
	static char	message[100];
	static int	idx;
	static int	count;
	static char	letter;

	(void) info;
	(void) context;
	if (signo == SIGUSR1)
		letter |= 1;
	count++;
	if (letter == 127)
	{
		ft_printf("%s\n", message);
		refresh(message, &count, &letter);
		idx = 0;
		return ;
	}
	if (count == 8)
	{
		message[idx] = letter;
		idx++;
		refresh(NULL, &count, &letter);
	}
	if (idx == 100)
	{
		ft_printf("%s", message);
		refresh(message, &count, &letter);
		idx = 0;
	}
	letter <<= 1;
}
