/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:47:31 by hyna              #+#    #+#             */
/*   Updated: 2022/07/09 20:19:35 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char	**argv)
{
	int	pid;

	if (argc != 2)
		return (0);
	pid = ft_atoi(argv[1]);
	ft_printf("%d\n", pid);
	if (pid <= 300 || pid > 32768)
		return (0);
	ft_printf("testdone!\n");
	return (0);
}
