/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:28:19 by hyna              #+#    #+#             */
/*   Updated: 2022/06/24 14:49:51 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	result_len(long long n, int base_len)
{
	int	len;

	len = 1;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

static void	ft_rev(char	*tab, int size)
{
	char	temp;
	int		i;
	int		j;

	i = size - 1;
	j = 0;
	while (j < size / 2)
	{
		temp = tab[j];
		tab[j] = tab[i];
		tab[i] = temp;
		i--;
		j++;
	}
}

static void	make_result(long long n, char	*result, int pos, char	*base)
{
	int	i;
	int	base_len;

	base_len = ft_strlen(base);
	i = 0;
	while (i < pos)
	{
		result[i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	ft_rev(result, ft_strlen(result));
}

char	*ft_itoa_base(unsigned int n, char	*base)
{
	char	*result;

	result = (char *) ft_calloc(result_len(n, ft_strlen(base)), sizeof(char));
	if (result == NULL)
		return (NULL);
	make_result(n, result, result_len(n, ft_strlen(base)) - 1, base);
	return (result);
}
