/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyna@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:53:56 by hyna              #+#    #+#             */
/*   Updated: 2022/06/24 14:46:00 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	which_conversion(char c, va_list ap)
{
	int	result;

	if (c == 'c')
		result = conversion_c(ap);
	else if (c == 's')
		result = conversion_s(ap);
	else if (c == 'p')
		result = conversion_p(ap);
	else if (c == 'd')
		result = conversion_di(ap);
	else if (c == 'i')
		result = conversion_di(ap);
	else if (c == 'u')
		result = conversion_u(ap);
	else if (c == 'x')
		result = conversion_x(ap);
	else if (c == 'X')
		result = conversion_upper_x(ap);
	else if (c == '%')
		result = write(1, "%", 1);
	else
		return (-1);
	return (result);
}

static int	check_format(const char	*format, va_list ap)
{
	int	result;
	int	i;
	int	tmp;

	result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = which_conversion(format[++i], ap);
			if (tmp == -1)
				return (-1);
			i++;
			result += tmp;
		}
		else
		{
			write(1, &(format[i]), 1); 
			result++;
			i++;
		}
	}
	return (result);
}

int	ft_printf(const char	*format, ...)
{
	va_list	ap;
	int		result;

	va_start(ap, format);
	result = check_format(format, ap);
	va_end(ap);
	if (result == -1)
		return (-1);
	return (result);
}
