/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_conversions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:04:42 by hyna              #+#    #+#             */
/*   Updated: 2022/04/09 16:05:03 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_p(va_list	ap)
{
	int					result;
	unsigned long long	pointer;

	result = 0;
	pointer = (unsigned long long) va_arg(ap, void *);
	result += write(1, "0x", 2);
	result += conversion_p_util(pointer, "0123456789abcdef");
	return (result);
}

int	conversion_x(va_list	ap)
{
	int				result;
	int				num;
	char			*s;

	result = 0;
	num = va_arg(ap, int);
	s = ft_itoa_base(num, "0123456789abcdef");
	if (!s)
		return (-1);
	result = write(1, s, ft_strlen(s));
	free(s);
	return (result);
}

int	conversion_upper_x(va_list	ap)
{
	int		result;
	int		num;
	char	*s;

	result = 0;
	num = va_arg(ap, int);
	s = ft_itoa_base(num, "0123456789ABCDEF");
	if (!s)
		return (-1);
	result = write(1, s, ft_strlen(s));
	free(s);
	return (result);
}

int	conversion_u(va_list	ap)
{
	int			result;
	long long	num;

	result = 0;
	num = (long long) va_arg(ap, unsigned int);
	result += ft_putnbr_base(num, "0123456789");
	return (result);
}
