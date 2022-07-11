/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_receiver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:22:36 by hyna              #+#    #+#             */
/*   Updated: 2022/07/11 11:22:14 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"
#include "libft.h"

static void	refresh(char	*message, int	*count, char	*letter)
{
	if (message)
		ft_bzero(message, 103);
	*count = 0;
	if (letter != NULL)
		*letter = 0;
}

static void	put_message(char	*message, int	*idx, int *count, char	*letter)
{
	ft_printf("%s", message);
	if (letter != NULL && *letter == 127)
		ft_printf("\n");
	refresh(message, count, letter);
	*idx = 0;
}

void	receive_processor(int signo, siginfo_t	*info, void	*context)
{
	static char	message[101];
	static int	idx;
	static int	count;
	static char	letter;

	(void) info;
	(void) context;
	if (signo == SIGUSR1)
		letter |= 1;
	count++;
	if (letter == 127)
		put_message(message, &idx, &count, &letter);
	if (count == 8)
	{
		message[idx++] = letter;
		refresh(NULL, &count, &letter);
	}
	if (idx == 100)
		put_message(message, &idx, &count, &letter);
	letter <<= 1;
}
