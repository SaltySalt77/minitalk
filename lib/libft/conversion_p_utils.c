/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:42:56 by hyna              #+#    #+#             */
/*   Updated: 2022/06/24 14:49:12 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	check_base(char	*str)
{
	int	len;
	int	j;

	len = 0;
	while (str[len])
	{
		if ((str[len] == '+') || (str[len] == '-'))
			return (0);
		j = len + 1;
		while (str[j])
		{
			if ((str[len] == str[j]) || (str[j] == '+') || (str[j] == '-'))
				return (0);
			j++;
		}
		len++;
	}
	return (len);
}

static void	print_num(unsigned long long nbr, char *base, int len, int	*result)
{
	char	c;

	if (nbr < (unsigned int)len)
	{
		c = base[nbr];
		write(1, &c, 1);
		(*result)++;
	}
	else
	{
		print_num(nbr / len, base, len, result);
		print_num(nbr % len, base, len, result);
	}
}

int	conversion_p_util(unsigned long long n, char	*base)
{
	int	len;
	int	result;

	result = 0;
	len = check_base(base);
	if (len == 0 || len == 1)
		return (-1);
	else if (n == 0)
		return (write(1, "0", 1));
	else
	{
		print_num(n, base, len, &result);
	}
	return (result);
}
