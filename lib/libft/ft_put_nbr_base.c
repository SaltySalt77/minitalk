/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:53:51 by hyna              #+#    #+#             */
/*   Updated: 2022/04/09 16:03:27 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_putnbr_base(long long nbr, char	*base)
{
	int	len;
	int	result;

	result = 0;
	len = check_base(base);
	if ((len == 0) || (len == 1))
		return (-1);
	else if (nbr == 0)
		return (write(1, "0", 1));
	else
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			result += write(1, "-", 1);
		}
		print_num((unsigned long long)nbr, base, len, &result);
	}
	return (result);
}
